#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug  4 23:15:40 2022

@author: Don
"""

# lib
import hashlib
import binascii
from Crypto.Cipher import AES # AESをimport

#func
def ex_euclid(a,b):
    x0, x1 = 1, 0
    y0, y1 = 0, 1
    while b!=0:
        q, r = divmod(a, b) # r = a0 % a1, q = (a0 – r)//a1 でも可
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
        a, b = b, r
    return [a, x0, y0]

def mod_binary(g,k,n):
    # out: g^k mod n
    bk = bin(k)[2:]
    y = 1
    for i in bk:
        y = y * y % n
        if i == '1':
            y = y * g % n
    return y

def rsaEnc(m, n, e):
    return mod_binary(m, e, n)

def rsaDec(c, n, d):
    return mod_binary(c, d, n)

def mgf(D, oLen):
    if len(D) % 2 == 1:
        D = b'0' + D
    m = binascii.unhexlify(D)
    return hashlib.shake_128(m).hexdigest(oLen)

def xor(x, y):
    import binascii
    bx = binascii.unhexlify(x)
    by = binascii.unhexlify(y)
    bz = bytes(a ^ b for a, b in zip(bx, by))
    return binascii.hexlify(bz)

def rsa_oaep_Enc(m, k0, k1, k2, lHASH, r, e, n):
    m = str(hex(m)[2:]).encode()
    lHASH = str(hex(lHASH)[2:]).encode()
    r = str(hex(r)[2:]).encode()
    PS = b'00'*k1
    
    padm = lHASH + PS + b'01' + m
    s = xor(mgf(r,k0+k1+k2+1), padm)
    t = xor(mgf(s,k0), r)
    w = b'00' + t + s
    cipher = rsaEnc(int(w.decode(), 16), n, e)
    return cipher
    
def rsa_oaep_Dec(C, k0, k1, k2, r_oaep, d, n):
    w = rsaDec(C,n,d)
    w = str(hex(w)[2:]).encode()
    if w[-1].to_bytes(1, 'little') != b'0':
        return None
    t = w[0:2*k0]
    s = w[2*k0:len(w)]
    r = xor(mgf(s, k0), t)
    if int(r.decode(), 16) != r_oaep:
        return None
    z = xor(mgf(r, k0+k1+k2+1), s)
    m = z[0:2*k2]
    return int(m.decode(), 16)

def gcd(a,b):
    return ex_euclid(a,b)[0]

def lcm(a,b):
    return a*b//gcd(a,b)

def inv(a,n):
    return ex_euclid(a,n)[1] % n

def rsaSignGenKey(p, q, e):
    n  = p*q
    lambda_n = lcm(p-1, q-1)
    if gcd(e,lambda_n) != 1:
        return 0
    d = inv(e, lambda_n)
    return(n, e, d)

def rsaSignGen(m, n, d):
    mhash = shake128(m, 127)
    return mod_binary(mhash, d, n)

def rsaSignVerify(m, sigma, n, e):
    mhash = shake128(m, 127)
    return mhash == mod_binary(sigma,e,n)

def shake128(m, h_size):
    mhash = hashlib.shake_128(m.encode()).hexdigest(h_size)
    return int(mhash, 16)

# 演習4.1のk0, k1, k2
k0 = 20
k1 = 70
k2 = 16

# Generate keys
p=117122396397187566022319901006614351890918745392121360853052845839451044782683550439081108282296378901224557545636144813065182416439944295796145873457749188546480292560829910385307548247946417248162583126257783569215746705530854075805962995750212469043529731821942870087645297955420394548523484258221186315121
q=122109141636613312780067737900817605131679271750360581539238494345933258543366700691927028731689476451156706646638374448342932183226061032441594718847442840095318074225678783465926857195599849292597334842158648847365327770447117466327250903803495546030773034209473227916347431829420791949521401319509679197691
e=763583

n, e, d = rsaSignGenKey(p, q, e)

# Random 128-bit K and its encrypted cipher
K = 200885762114415633156669858668564875839
n1 = 17447903641709445604225025395928909148052367395731991914691418751996569904665756979575116702195295053413842779538350013463922507807708470313610594108412198064724861792386714461937311349560386934656865365080335664071256156191728003068503375427054333830000113468717988594763912983792585057111885072851288760706891970060567635041270567373168754472058759361986368192650802742315283703266206031798110209114534532011501585246930253902659325227933071548251342038267871217404362721092246100637117339506647966808848026578895213400379041187060709244839964259293606656641511205434360941649950504847220612128550212186342573656093
e1 = 2705880806217937081
roaep_160 = 788255724614721016190591162463944054696650907899
lHASH = 1245845410931227995499360226027473197403882391305

Ck = rsa_oaep_Enc(K, k0, k1, k2, lHASH, roaep_160, e1, n1)

# AES encrypt
key = str(hex(Ck)[2:])
key = shake128(key, 16)
key = bytes.fromhex(str(hex(key))[2:])
key = binascii.hexlify(key)

AES_object = AES.new(key, AES.MODE_EAX) # AESのオブジェクト
m = 'peer-to-peer net' # 平文
mh = binascii.hexlify(m.encode())
while len(mh) < len(key): 
    mh = b'0' + mh # mh と key の長さがそろうように先頭に 0 をパディングする必要がある.
ciphertext, tag = AES_object.encrypt_and_digest(mh) # "Data"を暗号化
print("{}の暗号文={}".format(m, ciphertext)) # 暗号文の表示
# sign
sign = rsaSignGen(m, n, d)

# decrypt
AES_object_nonce = AES_object.nonce # AESオブジェクトのナンス値を取得
cipher_dec = AES.new(key, AES.MODE_EAX, AES_object_nonce) # 鍵とAESのモード（EAX)とナンス値で復号のためのオブジェクトを取得
data = cipher_dec.decrypt_and_verify(ciphertext, tag) # 暗号文とtagを入力し復号
print("復号結果(バイト列)=", data) # 復号結果を表示
print("復号結果(通常の文字列)=", binascii.unhexlify(data).decode()) # 文字列で表示

# Verify sign
v = rsaSignVerify(m, sign, n, e)