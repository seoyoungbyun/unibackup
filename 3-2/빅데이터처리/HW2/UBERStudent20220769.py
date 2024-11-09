#! /usr/bin/python3

from openpyxl import load_workbook
import sys
import datetime

inputpath = sys.argv[1]
outputpath = sys.argv[2]

weekday = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
uber = dict()
with open(inputpath, 'r', encoding = 'utf-8') as fp:
    for line in fp:
        uber_line = line.strip().split(',')
        date = uber_line[1].split('/')
        y = int(date[2])
        m = int(date[0])
        d = int(date[1])
        day = datetime.date(y, m, d).weekday()
        
        id = uber_line[0] + "," + weekday[day]
        
        if id not in uber:
            uber[id] = uber_line[2] + "," + uber_line[3]
        else:
            num = uber[id].strip().split(',')
            
            active = int(num[0])
            trip = int(num[1])
            active += int(uber_line[2])
            trip += int(uber_line[3])
            
            uber[id] = str(active) + "," + str(trip)
            
with open(outputpath, "w", encoding="utf-8") as file:
       for key, value in uber.items():
           file.write("{} {}\n".format(key, value))  