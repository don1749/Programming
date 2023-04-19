#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 13 18:41:24 2023

@author: Don
"""

n, k = map(int, input().split())
prices = sorted(list(map(int, input().split())))

total_costs = set()

# Try all possible sets of takoyakis
for i in range(1,n):
    for j in range(n-i):
        total_cost = sum(prices[j:j+i])
        total_costs.add(total_cost)

# Convert the set to a list, sort it, and output the k-th element
sorted_costs = sorted(list(total_costs))
print(sorted_costs)
