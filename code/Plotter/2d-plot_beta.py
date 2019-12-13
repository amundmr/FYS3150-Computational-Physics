import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np
import sys


earth_x = []; earth_y = []; earth_z = []
with open('../complete_solar-system/output/beta/Earthb2.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth_x.append(float(l[0])); earth_y.append(float(l[1])); earth_z.append(float(l[2]))

earth22_x = []; earth22_y = []; earth22_z = []
with open('../complete_solar-system/output/beta/Earthb2-2.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth22_x.append(float(l[0])); earth22_y.append(float(l[1])); earth22_z.append(float(l[2]))

earth24_x = []; earth24_y = []; earth24_z = []
with open('../complete_solar-system/output/beta/Earthb2-4.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth24_x.append(float(l[0])); earth24_y.append(float(l[1])); earth24_z.append(float(l[2]))

earth26_x = []; earth26_y = []; earth26_z = []
with open('../complete_solar-system/output/beta/Earthb2-6.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth26_x.append(float(l[0])); earth26_y.append(float(l[1])); earth26_z.append(float(l[2]))

earth28_x = []; earth28_y = []; earth28_z = []
with open('../complete_solar-system/output/beta/Earthb2-8.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth28_x.append(float(l[0])); earth28_y.append(float(l[1])); earth28_z.append(float(l[2]))
##

sun_x = []; sun_y = []; sun_z = []
with open('../complete_solar-system/output/beta/Sun.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        sun_x.append(float(l[0])); sun_y.append(float(l[1])); sun_z.append(float(l[2]))

Plotskip = 1 #Plot only N'th point in the vectors
dotsize = 3


#Plotting read data
plt.scatter(earth_x, earth_y,s=dotsize, label= r"$\beta = 2$")
plt.scatter(sun_x, sun_y,s=dotsize, label= "Sun")
plt.scatter(earth22_x, earth22_y,s=dotsize, label= r"$\beta = 2.2$")
plt.scatter(earth24_x, earth24_y,s=dotsize, label= r"$\beta = 2.4$")
plt.scatter(earth26_x, earth26_y,s=dotsize, label= r"$\beta = 2.6$")
plt.scatter(earth28_x, earth28_y,s=dotsize, label= r"$\beta = 2.8$")

#plt.scatter(0,0,label = "Sun", s=30, color = "black")

plt.ylabel("Y Position, [AU]")
plt.xlabel("X Position, [AU]")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Earth Orbit using Verlet method. 2 years, 1e5 int points")
#plt.ylim(0,13.5)
#plt.yscale('log')
plt.legend(loc="upper left")

plt.savefig('Earth-Sun_beta.png', bbox_inches='tight')
plt.show()
