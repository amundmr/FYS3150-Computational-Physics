import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
fig = plt.figure()
ax = plt.axes(projection='3d')

earth_x = []; earth_y = []; earth_z = []
with open('../complete_solar-system/output/Mercury.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth_x.append(float(l[0])); earth_y.append(float(l[1])); earth_z.append(float(l[2]))


ax.plot3D(earth_x, earth_y, earth_z)
plt.show()
plt.savefig('fig1.png')
