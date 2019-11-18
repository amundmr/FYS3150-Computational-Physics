import matplotlib.pyplot as plt
import numpy as np
import sys

#Reading file

f1 = open("../data/L20_1m_step0-005.csv","r")
f2 = open("../data/L40_1m_step0-005.csv","r")
f3 = open("../data/L60_1m_step0-005.csv","r")
f4 = open("../data/L80_1m_step0-005.csv","r")
f5 = open("../data/L100_1m_step0-005.csv","r")
"""
f1 = open("../data/L20_100k_step0-005.csv","r")
f2 = open("../data/L40_100k_step0-005.csv","r")
f3 = open("../data/L60_100k_step0-005.csv","r")
f4 = open("../data/L80_100k_step0-005.csv","r")
f5 = open("../data/L100_100k_step0-005.csv","r")
"""
files = [f1, f2, f3, f4, f5]
for i in range(5):
    files[i].readline()
    files[i].readline()

Alldata = [files[0].readlines(), files[1].readlines(), files[2].readlines(), files[3].readlines(), files[4].readlines()]
Moredata = []
i = 0
for file in Alldata:
    length = len(file)
    Moredata.append(np.zeros((5,length)))
    j=0
    for line in file:


        Moredata[i][0][j] = float(line.split()[0]) #0 IS TEMP
        Moredata[i][1][j] = float(line.split()[1]) #1 IS MAGNE
        Moredata[i][2][j] = float(line.split()[2]) #2 IS ENERGY
        Moredata[i][3][j] = float(line.split()[3]) #3 IS SUSCEP
        Moredata[i][4][j] = float(line.split()[4]) #4 IS HEAT CAP

        j+=1
    i+=1



#Plotting read data
for i in range(3,4):
    plt.plot(Moredata[0][0],Moredata[0][i], linewidth=1, label= "L = 20")
    plt.plot(Moredata[1][0],Moredata[1][i], linewidth=1, label= "L = 40")
    plt.plot(Moredata[2][0],Moredata[2][i], linewidth=1, label= "L = 60")
    plt.plot(Moredata[3][0],Moredata[3][i], linewidth=1, label= "L = 80")
    plt.plot(Moredata[4][0],Moredata[4][i], linewidth=1, label= "L = 100")

plt.ylabel(r"$C_V$")
plt.xlabel("Temperature")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Heat Capacity")
#plt.ylim(0,13.5)
#plt.yscale('log')
plt.legend(loc="upper left")

plt.savefig("Heatcapacity.png", bbox_inches='tight')
plt.show()
