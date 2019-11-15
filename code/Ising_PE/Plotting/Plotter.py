import matplotlib.pyplot as plt
import numpy as np
import sys

#Reading file
f1 = open("../cold","r")
f2 = open("../warm","r")

Data = f1.readlines()
Data2 = f2.readlines()

N =  len(Data)
N2 = len(Data2)

Alldata = np.zeros(N)
Alldata2 = np.zeros(N2)


i = 0
for line in Data:
    Alldata[i] = float(line)
    i +=1

i = 0
for line in Data2:
    Alldata2[i] = float(line)
    i +=1




#x = np.random.normal(size = 1000)
plt.hist(Alldata,bins = 20, density=True) #bins=30
plt.ylabel('Probability')
plt.xlabel('Energy')
plt.title(r'Energy Probability for $T=1$ with %d MC cycles' %N)
plt.show()


"""
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
"""
