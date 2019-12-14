# -*- coding: utf-8 -*-
"""
Created on Sat Aug 31 06:34:47 2019

@author: Arne
"""

import urllib
import urllib.request
import time
import random

a = "http://11603319.pxl-ea-ict.be/Write_Data.php?Sensor_ID=1&waarde="
b = "http://11603319.pxl-ea-ict.be/Write_Data.php?Sensor_ID=2&waarde="
temp = 0
light = 0

tempWaarde = 20
lightWaarde = 50

lightMin = 45
lightMax = 55

tempMin = 15
tempMax = 25

while True:
    time.sleep(60)
    if temp >= 5:
        tempWaarde = random.randrange(tempMin,tempMax)
        
        if tempWaarde - 5 <= 0:
            tempMin = 0
        else:
            tempMin = tempWaarde - 5
        
        if tempWaarde + 5 >= 100:
            tempMax = 101
        else:
            tempMax = tempWaarde + 5
        
        print("TEMP = " + str(tempWaarde) + " MIN = " + str(tempMin) + " MAX = " + str(tempMax))
        webpage = a + str(tempWaarde)
        urllib.request.urlopen(webpage).read()
        temp = -1
    if light >= 10:
        lightWaarde = random.randrange(lightMin,lightMax)
        
        if lightWaarde - 5 <= 0:
            lightMin = 0
        else:
            lightMin = lightWaarde - 5
        
        if lightWaarde + 5 >= 100:
            lightMax = 101
        else:
            lightMax = lightWaarde + 5
        
        print("lichtwaarde = " + str(lightWaarde) + " Min = " + str(lightMin) + " Max = " + str(lightMax))
        webpage = b + str(lightWaarde)
        urllib.request.urlopen(webpage).read()
        light = -1
    temp = temp + 1
    light = light +1
