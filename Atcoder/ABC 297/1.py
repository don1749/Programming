#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 13 17:43:34 2023

@author: Don
"""

[N, D] = [int(x) for x in input().split(' ')]
arr = [int(x) for x in input().split(' ')]
flag = False

for i in range(1,N):
    if arr[i]-arr[i-1] <= D:
        print(arr[i])
        flag = True
        break

if flag == False:
    print(-1)