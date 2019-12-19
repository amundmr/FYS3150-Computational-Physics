import numpy as np
import matplotlib.pyplot as plt
import sys

#Reading file
f = open(sys.argv[1], "r")
lines = f.readlines()
T_calc = np.zeros(len(lines))
Cv_calc = np.zeros_like(T_calc)
i = 0
for line in lines:
    T_calc[i] = float(line.split()[0])
    Cv_calc[i] = float(line.split()[1])/1e7
    i += 1
#Now we have all calculated values in Cv_calc and T_calc


def newf(T): #Analytical function
    kb = 1
    J = 1
    b = 1/(kb*T)
    f = 1/(kb*T) * 64*J*J*(np.cosh(b*8*J)/(np.cosh(b*8*J)+3) -(-np.sinh(b*8*J)/(np.cosh(b*8*J)+3))**2)
    return f

T_ana = np.linspace(2,4.5,100)
Cv_ana = newf(T_ana)


plt.plot(T_calc, Cv_calc, label = "Computed")

plt.plot(T_ana,Cv_ana, label = "Analytical")
plt.legend()
plt.show()
