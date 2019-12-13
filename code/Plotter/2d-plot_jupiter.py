import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np
import sys


earth_x = []; earth_y = []; earth_z = []
with open('../complete_solar-system/output/jupiter/Earthg1000.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth_x.append(float(l[0])); earth_y.append(float(l[1])); earth_z.append(float(l[2]))

jupiter_x = []; jupiter_y = []; jupiter_z = []
with open('../complete_solar-system/output/jupiter/Jupiterg1000.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        jupiter_x.append(float(l[0])); jupiter_y.append(float(l[1])); jupiter_z.append(float(l[2]))
##

sun_x = []; sun_y = []; sun_z = []
with open('../complete_solar-system/output/jupiter/Sung1000.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        sun_x.append(float(l[0])); sun_y.append(float(l[1])); sun_z.append(float(l[2]))

Plotskip = 10 #Plot only N'th point in the vectors
dotsize = 2

#plt.scatter(sun_x[::Plotskip], sun_y[::Plotskip], s=dotsize, label = "Sun", color = "orange")
#plt.scatter(earth_x[::Plotskip], earth_y[::Plotskip],  s=dotsize, label = "Earth", color = "blue")

t = np.linspace(0,len(earth_x[::Plotskip]),len(earth_x[::Plotskip]))
t = t*12/len(t)
yrs = 12
dt = yrs/(len(earth_x))

#Plotting read data
cm = cm.get_cmap('gist_rainbow')
plt.plot(sun_x[::Plotskip], sun_y[::Plotskip],linewidth=dotsize*3, label= "Sun", color='r', zorder=0)
sc1 = plt.scatter(sun_x[::Plotskip], sun_y[::Plotskip],s=dotsize, c = t, cmap = cm, zorder=1)

plt.plot(jupiter_x[::Plotskip], jupiter_y[::Plotskip],linewidth=dotsize*3, label= "Jupiter", color='b', zorder=3)
sc2 = plt.scatter(jupiter_x[::Plotskip], jupiter_y[::Plotskip],s=dotsize, c = t, cmap = cm, zorder=4)

sc = plt.scatter(earth_x[::Plotskip], earth_y[::Plotskip],s=dotsize, label = "Earth", c = t, cmap = cm, zorder=5)

cb = plt.colorbar(sc)
cb.set_label("Years after simulation start.")

#plt.scatter(0,0,label = "Sun", s=30, color = "black")

plt.ylabel("Y Position, [AU]")
plt.xlabel("X Position, [AU]")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Earth and Jupiter, $M_{Jupiter}=9.54E-1$, $\Delta t = %g yr$"%dt)
#plt.ylim(0,13.5)
#plt.yscale('log')
plt.legend()

plt.savefig('Earth-Sun_Test.png', bbox_inches='tight')
plt.show()
