#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 13 17:53:42 2023

@author: Don
"""

s = input()

def check_string(s):
    if s.count('K') != 1 or s.count('Q') != 1 or s.count('R') != 2 or s.count('B') != 2 or s.count('N') != 2:
        return False
    b_indices = [i for i, c in enumerate(s) if c == 'B']
    if len(b_indices) == 2 and b_indices[0] % 2 == b_indices[1] % 2:
        return False
    r_indices = [i for i, c in enumerate(s) if c == 'R']
    k_index = s.index('K')
    if not (r_indices[0] < k_index and k_index < r_indices[1]):
        return False
    return True

if check_string(s):
    print('Yes')
else:
    print('No')
