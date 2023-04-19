#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug  4 22:00:10 2022

@author: Don
"""
import hashlib
import binascii

# func
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

def gcd(a,b):
    return ex_euclid(a,b)[0]

def lcm(a,b):
    return int(a*b/gcd(a,b))

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

def rsaEnc(m, n, e):
    return mod_binary(m, e, n)

def shake128(m, h_size):
    mhash = hashlib.shake_128(m.encode()).hexdigest(h_size)
    return int(mhash, 16)

# rsa encode
m = "私はサイモン・シンの「暗号解読」の本が好きで、RSAの演習で非常に楽しいと感じました"
n = 132639128328156874302341968448627869114681769925253308356386508014896474072062362479952607784543134302534592007855554898302262711335875317907787788175302032187091773786443929734402942858254023783150409433342703442152907413461389601036781602744581302475935905417201036386878337159526581802689674768037898370557
e = 1009483867

m_bytes = binascii.hexlify(m.encode())
m_int = int(m_bytes, 16)
c = rsaEnc(m_int, n, e)

# D.10 data
p2=11853085763133505990286201269363921131755361282207771806454216823906463045956110404018518118871988561332197770015175458025096566875663947404231597048649687
q2=13241479879786700069537673013402283713461303895018638725043715728333351182535991791698730454905679569343041660910401104499998964541968688709360528771269943
n2=156952396645918502955193834718776388506857399213019211056913567025447783623953424981098100320371797037390713527200065108048504302347881505742461209041764469658052100493063095556772159136964337847882433273567579158528625301415253145239724411443393127148129610564195773940563184444586953330741471865748319457841
e1=16906953396398285955
d1=724312013274593559104718233668131011194996096397911006981852189172961239048948863282836141926358773822231408712979119342947633487509489681999208855556699754187911367602954918028434935166295469845715934583725830138105140714265139027719788715269467483599026617823666098202900871395864967128743435198316095145

# rsa sign gen
(n3, e3, d3) = rsaSignGenKey(p2,q2,e1)
sigma = rsaSignGen(m,n2,d1)
v = rsaSignVerify(m, sigma, n2, e1)
sigma2 = rsaSignGen(m,n3,d3)
v2 = rsaSignVerify(m, sigma, n3, e3)