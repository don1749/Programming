#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 13 18:17:55 2023

@author: Don
"""

def solve(a,b):
    cnt = 0
    while(a!=b and a!=0):
        if a<b:
            a,b = b,a
        if a%b==0:
            cnt += a//b -1
        else:
            cnt += a//b
        a = a%b
    
    return cnt

[a,b] = [int(x) for x in input().split()]
print(solve(a,b))