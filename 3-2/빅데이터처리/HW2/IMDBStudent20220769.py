#! /usr/bin/python3

from openpyxl import load_workbook
import sys

inputpath = sys.argv[1]
outputpath = sys.argv[2]

genrge_num = dict()
with open(inputpath, 'r', encoding = 'utf-8') as fp:
    for line in fp:
        fields = line.strip().split('::')
        genrge = fields[2].split('|')
        
        for g in genrge:
            if g not in genrge_num:
                genrge_num[g] = 1
            else:
                genrge_num[g] += 1

with open(outputpath, "w", encoding="utf-8") as file:
       for key, value in genrge_num.items():
           file.write("{} {}\n".format(key, value))       
    
        