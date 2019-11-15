import matplotlib.pyplot as plt
import numpy as np
import sys

#Reading file
f1 = open("../cold","r")
<<<<<<< HEAD
f2 = open("../coldsmall","r")
=======
f2 = open("../warm","r")
>>>>>>> af80a730ea5b3db70f4ecf4fff5b18fb82ec0871

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
plt.ylabel('Probability')
plt.xlabel('Energy')
plt.title(r'Energy Probability distribution for $T=1$ with %g MC cycles' %N)
plt.savefig("../ProbE_T1.png", bbox_inches='tight')
plt.show()

plt.hist(Alldata2[10000:],bins = 122, density=True) #bins=30
plt.ylabel('Probability')
plt.xlabel('Energy')
plt.title(r'Energy Probability distribution for $T=2.4$ with %g MC cycles' %N2)
<<<<<<< HEAD
plt.savefig("../ProbE_T24test.png", bbox_inches='tight')
plt.axvline(x=-100, linestyle = "--", color ='r')
plt.axvline(x=-108, linestyle = "--", color ='r')
=======
plt.savefig("../ProbE_T24.png", bbox_inches='tight')
plt.axvline(x=-550, linestyle = "--", color ='r')
plt.axvline(x=-430, linestyle = "--", color ='r')
>>>>>>> af80a730ea5b3db70f4ecf4fff5b18fb82ec0871
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
