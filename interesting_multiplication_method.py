#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

def multiply(a, b):
    final_sum = float(0.0)
    while a >= 1:
        if a % 2 != 0:
            final_sum += b
        a = round((a/2))
        b*=2
    return final_sum

def main():
    try:
        print("{}*{}={:g}".format(sys.argv[1], sys.argv[2], multiply(float(sys.argv[1]), float(sys.argv[2]))))
    except Exception:
        print("Incorrect arguments.")

if __name__ == '__main__':
    main()
