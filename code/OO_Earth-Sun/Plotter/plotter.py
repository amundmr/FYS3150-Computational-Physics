import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np
import sys

#Reading file
f1 = open("../earthorbit.dat","r")
f1.readline()
data = f1.readlines()
x = np.zeros(len(data))
y = np.zeros_like(x)
t = np.zeros_like(x)

i = 0
for line in data:
    t[i] = float(line.split()[0])
    x[i] = float(line.split()[1])
    y[i] = float(line.split()[2])
    i+=1







#Plotting read data
c = cm.rainbow(np.linspace(0,1,len(y)))
print(c)
plt.scatter(x,y,s=2, label= "Earth Orbit", color = c)
#plt.plot(Vd,AllError[i], linewidth=1)

plt.ylabel("Y Position")
plt.xlabel("X Position")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Earth Orbit")
#plt.ylim(0,13.5)
#plt.yscale('log')
#plt.legend(loc="upper left")

plt.savefig("../EarthOrbit.png", bbox_inches='tight')
plt.show()
