#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 12 20:16:58 2022

@author: Don
"""

S5 =     [
            [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
            [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
            [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
            [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3],
        ]

def parity(x):
    if bin(x)[2:].zfill(4).count('1')%2==1:
        return '1'
    return '0'

sol={}
for y in range(16):
    sol[y]=[]
    for row in range(4):
        if y in S5[row]:
            a = bin(row)[2:].zfill(2)
            b = bin(S5[row].index(y))[2:].zfill(4)
            x = a[0] + b + a[1]
            if x[1]==parity(y):
                sol[y].append(int(x,2))
        
            