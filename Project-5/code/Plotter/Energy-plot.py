import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np
import sys


earth_x = []; earth_y = []; earth_z = []
with open('../complete_solar-system/output/Earth.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth_x.append(float(l[3])); earth_y.append(float(l[4])); earth_z.append(float(l[2]))
##

sun_x = []; sun_y = []; sun_z = []
with open('../complete_solar-system/output/Sun.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        sun_x.append(float(l[0])); sun_y.append(float(l[1])); sun_z.append(float(l[2]))

Plotskip = 5 #Plot only N'th point in the vectors
dotsize = 3

#plt.scatter(sun_x[::Plotskip], sun_y[::Plotskip], s=dotsize, label = "Sun", color = "orange")
#plt.scatter(earth_x[::Plotskip], earth_y[::Plotskip],  s=dotsize, label = "Earth", color = "blue")

t = np.linspace(0,len(earth_x[::Plotskip]),len(earth_x[::Plotskip]))
t = t*1000/len(t)
yrs = 1000
dt = yrs/(len(earth_x)-1)

#Plotting read data
sc = plt.scatter(t, earth_x[::Plotskip],s=dotsize, label= "Kinetic enegy")
sc1 = plt.scatter(t, earth_y[::Plotskip],s=dotsize, label= "Potential energy")

#plt.scatter(0,0,label = "Sun", s=30, color = "black")

plt.ylabel("Energy")
plt.xlabel("Time, [Years]")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Energy variance using Verlet method and $\Delta t = %g yr$"%dt)
#plt.ylim(0,13.5)
#plt.yscale('log')
plt.legend(loc="upper left")

plt.savefig('Earth-Sun_Test.png', bbox_inches='tight')
plt.show()
