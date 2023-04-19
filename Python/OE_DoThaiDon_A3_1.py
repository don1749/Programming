#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug  4 23:15:40 2022

@author: Don
"""

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

def inv(a,n):
    return ex_euclid(a,n)[1] % n

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

# def common_mod_attack(e1,e2, n, c1, c2):
#     (gcd, a, b) = ex_euclid(e1,e2)
#     if a < 0:
#         i = inv(n, c1)
#         mx = mod_binary(i, -a, n)
#         my = mod_binary(c2, b, n)
#     else:
#         i = inv(n, c2)
#         mx = mod_binary(c1, a, n)
#         my = mod_binary(i, -b, n)
#     return mod_binary(mx*my, 1, n)

# D.9
n1=122834028293712296720762660347542146164652093481670201947376324993009557691933003435610085976898758687338316692229094216953583611028600068975461290111594197522486713161058298860890998555271590454234774552183738893956388244959334034615659391123981756945729584040032409298308902656405787758214276110040436127519
e1_1=576545171
e1_2=4170652133

# 不定方程式e1-1x + e1-2y = 1 の解(x, y) を求めよ．
(x, y) = ex_euclid(e1_1, e1_2)[1:3]

# 解析3.1のc1, c2
c1=65913456858381744726703495790535502558058418141035592761812786810053902283272982020633893731291185344911988234350437394158600004327803826880308837307784270136254350487703455203690744021595367802891780797578347935159301055290853602783298175420341346182522717841330601795771072039611467307624813697419985912915
c2=56921468748227833936974157976122482813932477044704257001980025078299534078748338195879015738729680717539425517423375281410611904152379878880247588425742549275641314512099192251294731860358653555747820683938057836031397323303323052698327226284347887912321006668636137371086195636622499922152134659285296585070

# mを復元
c1 = mod_binary(c1,x,n1)
c2 = inv(c2,n1)
c2 = mod_binary(c2,-y,n1)
m = mod_binary(mod_binary(c1*c2,1,n1), 1, n1)
