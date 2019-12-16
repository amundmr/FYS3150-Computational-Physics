import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np
import sys

#Reading the data
x = []; y = []; z = []
with open('../complete_solar-system/output/perihelion/Mercury_rel.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        x.append(float(l[0])); y.append(float(l[1])); z.append(float(l[2]))

sun_x = []; sun_y = []; sun_z = []
with open('../complete_solar-system/output/perihelion/Sun_rel.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        sun_x.append(float(l[0])); sun_y.append(float(l[1])); sun_z.append(float(l[2]))


#Finding the last perihelion point
olddist = 1
failcount = 0
for i in reversed(range(len(x))):
    dist = np.sqrt(x[i]*x[i] + y[i]*y[i] + z[i]*z[i])
    if dist < olddist:
        xp = x[i]
        yp = y[i]
        olddist = dist
    else:
        failcount += 1
    if failcount > 50:
        break



#Printing the last perihelion point and angle difference from initial conditions
print("Perihelion position after a century: (%g, %g) in AU" %(xp,yp))
rad = np.arctan(yp/xp)
print("Perihelion angle after a century: %g degrees" %np.rad2deg(rad))
