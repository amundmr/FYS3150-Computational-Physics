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
plt.hist(Alldata[10000:],bins = 50, density=True) #bins=30
plt.ylabel('Probability density')
plt.xlabel('Energy')
plt.title(r'Energy Probability distribution for $T=1$ with %g MC cycles' %N)

std1 = np.std(Alldata[10000:])
mean1 = np.mean(Alldata[10000:])
plt.axvline(x=mean1-std1, linestyle = "--", color ='r', label = r"Standard deviation: %.2f"%std1)
plt.axvline(x=mean1, linestyle = "--", color ='g', label = r"Mean: %.2f"%mean1)
plt.axvline(x=mean1+std1, linestyle = "--", color ='r')
plt.legend()
plt.savefig("../ProbE_T1.png", bbox_inches='tight')
plt.show()

plt.hist(Alldata2[10000:],bins = 120, density=True) #bins=30
plt.ylabel('Probability density')
plt.xlabel('Energy')
plt.title(r'Energy Probability distribution for $T=2.4$ with %g MC cycles' %N2)
std = np.std(Alldata2[10000:])
mean = np.mean(Alldata2[10000:])
plt.axvline(x=mean-std, linestyle = "--", color ='r', label = r"Standard deviation: %.2f"%std)
plt.axvline(x=mean, linestyle = "--", color ='g', label = r"Mean: %.2f"%mean)
plt.axvline(x=mean+std, linestyle = "--", color ='r')

plt.legend()
plt.savefig("../ProbE_T24.png", bbox_inches='tight')

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
