import matplotlib.pyplot as plt
import numpy as np
import sys

#Reading file
f1 = open("../out","r")

E = np.zeros(1000000)

for



Allfiles = [f1, f2, f3]
Alldata = np.zeros((3,15))
i = 0
for file in Allfiles:
    file.readline()
    j=0
    for line in file.readlines():
        Alldata[i][j] = float(line.split()[6]) #6 IS HEAT CAP
        j+=1
    i+=1

Vd = np.linspace(0.5,1.9,15)
T = Vd

Analytical = 0.25* 1/(T*T) * 64 * ((np.cosh(8/T))/(np.cosh(8/T)+3) - ((-np.sinh(8/T))/(np.cosh(8/T)+3))**2)

AllError = [Analytical-Alldata[0], Analytical-Alldata[1], Analytical-Alldata[2]]
#AllError = Alldata
#Plotting read data
for i in range(len(AllError)):
    plt.scatter(Vd,AllError[i],s=20, label= r"$MCC = 1e($ %d $)$"%float(i+5))
    plt.plot(Vd,AllError[i], linewidth=1)
print(Analytical)
plt.plot(Vd, Analytical-Analytical, label = "Analytical")
plt.ylabel("Heat Capacity Error")
plt.xlabel("Temperature")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Comparison of different MC cycles")
#plt.ylim(0,13.5)
#plt.yscale('log')
plt.legend(loc="upper left")

plt.savefig("../CyclesComparison.png", bbox_inches='tight')
#plt.show()
