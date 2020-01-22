#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Author: cuiyi@zuoshouyisheng.com
# Created Time: 22 January 2020 23:24


def array_2d_for_go(array_2d):
    def _array_2d_for_go(_l):
        eles = []
        for ele in _l:
            if isinstance(ele, list):
                eles.append(_array_2d_for_go(ele))
            else:
                eles.append(str(ele))
        return "{{{}}}".format(", ".join(eles))
    return _array_2d_for_go(array_2d)


def main():
    print(array_2d_for_go([[3, 0, 8, 4], [2, 4, 5, 7], [9, 2, 6, 3], [0, 3, 1, 0]]))
