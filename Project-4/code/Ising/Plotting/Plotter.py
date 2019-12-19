import matplotlib.pyplot as plt
import numpy as np
import sys

#Reading file

f1 = open("../useful","r")

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
"""
Alldata = f1.readlines()[1:]
print(Alldata)
MCc = np.zeros(len(Alldata))
Accspin = np.zeros(len(Alldata))

for i in range(len(Alldata)):
    MCc[i] = int(Alldata[i].split()[0])
    Accspin[i] = float(Alldata[i].split()[1])
print(MCc)


plt.plot(MCc,Accspin,linewidth=1,  label= "L = 20")


plt.ylabel("Flipped spins for entire lattice")
plt.xlabel("Monte Carlo cycles")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Flipped spins for $T = 1$, ordered initialization")
#plt.ylim(0,13.5)
#plt.yscale('log')
plt.legend(loc="upper right")

plt.savefig("AccSpins_T1_100k_ordered.png", bbox_inches='tight')
plt.show()
