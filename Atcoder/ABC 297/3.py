#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 13 18:05:23 2023

@author: Don
"""

def solve(strings):
    for i in range(len(strings)):
        s = list(strings[i])
        for j in range(len(s)-1):
            if s[j]==s[j+1]=="T":
                s[j] = "P"
                s[j+1] = "C"
            strings[i] = "".join(s)
    return '\n'.join(strings)

strings = []
[H,W] = [int(x) for x in input().split(" ")]

for i in range(H):
    strings.append(input())

print(solve(strings))