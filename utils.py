#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Author: cuiyi@zuoshouyisheng.com
# Created Time: 22 January 2020 23:24


null = None


def array_2d_for_go(array_2d, to_rune=False):
    def _array_2d_for_go(_l):
        eles = []
        for ele in _l:
            if isinstance(ele, list):
                eles.append(_array_2d_for_go(ele))
            else:
                if isinstance(ele, str):
                    if to_rune:
                        eles.append("'{}'".format(ele))
                    else:
                        eles.append('"{}"'.format(ele))
                else:
                    eles.append(str(ele))
        return "{{{}}}".format(", ".join(eles))
    
    print(_array_2d_for_go(array_2d))


def tree_vals_for_go(vals):
    go_vals = []
    for val in vals:
        if val is null:
            go_vals.append("nil")
        else:
            go_vals.append(str(val))
    print("{{{}}}".format(", ".join(go_vals)))


def main():
    array_2d_for_go([[3, 0, 8, 4], [2, 4, 5, 7], [9, 2, 6, 3], [0, 3, 1, 0]])
    tree_vals_for_go([10, 5, 15, 3, 7, null, 18])
