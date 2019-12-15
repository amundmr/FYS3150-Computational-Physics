import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np
import sys


earth_x = []; earth_y = []; earth_z = []
with open('../complete_solar-system/output/Mercury.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth_x.append(float(l[0])); earth_y.append(float(l[1])); earth_z.append(float(l[2]))

sun_x = []; sun_y = []; sun_z = []
with open('../complete_solar-system/output/Sun.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        sun_x.append(float(l[0])); sun_y.append(float(l[1])); sun_z.append(float(l[2]))

x = np.array(earth_x[-100:-80])
y = np.array(earth_y[-100:-80])
z = np.array(earth_z[-100:-80])

xp = x[-1]
yp = y[-1]

print(np.arctan(xp/yp))

Lastyeardistance = np.sqrt(x*x + y*y + z*z)
#print(Lastyeardistance)
plt.scatter(np.linspace(0,len(Lastyeardistance), len(Lastyeardistance)), Lastyeardistance)





"""
Plotskip = 10 #Plot only N'th point in the vectors
dotsize = 3

#plt.scatter(sun_x[::Plotskip], sun_y[::Plotskip], s=dotsize, label = "Sun", color = "orange")
#plt.scatter(earth_x[::Plotskip], earth_y[::Plotskip],  s=dotsize, label = "Earth", color = "blue")

t = np.linspace(0,len(earth_x[::Plotskip]),len(earth_x[::Plotskip]))
t = t*1000/len(t)
yrs = 1000
dt = yrs/(len(earth_x)-1)

#Plotting read data
cm = cm.get_cmap('gist_rainbow')
sc = plt.scatter(earth_x[::Plotskip], earth_y[::Plotskip],s=dotsize, label= "Earth Orbit", c = t, cmap = cm)
sc1 = plt.scatter(sun_x[::Plotskip], sun_y[::Plotskip],s=dotsize, label= "Sun", c = t, cmap = cm)
cb = plt.colorbar(sc)
cb.set_label("Years after simulation start.")

#plt.scatter(0,0,label = "Sun", s=30, color = "black")
"""
dt = 1
plt.ylabel("Y Position, [AU]")
plt.xlabel("X Position, [AU]")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Earth Orbit using Verlet method and $\Delta t = %g yr$"%dt)
#plt.ylim(0,13.5)
#plt.yscale('log')
#plt.legend(loc="upper left")

plt.savefig('Perihelion_Lastyear.png', bbox_inches='tight')
plt.show()
