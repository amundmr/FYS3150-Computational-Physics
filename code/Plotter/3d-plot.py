import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
fig = plt.figure()
ax = plt.axes(projection='3d')


def axisEqual3D(ax):
    extents = np.array([getattr(ax, 'get_{}lim'.format(dim))() for dim in 'xyz'])
    sz = extents[:,1] - extents[:,0]
    centers = np.mean(extents, axis=1)
    maxsize = max(abs(sz))
    r = maxsize/2
    for ctr, dim in zip(centers, 'xyz'):
        getattr(ax, 'set_{}lim'.format(dim))(ctr - r, ctr + r)

earth_x = []; earth_y = []; earth_z = []
with open('../complete_solar-system/output/Earth.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        earth_x.append(float(l[0])); earth_y.append(float(l[1])); earth_z.append(float(l[2]))
##

sun_x = []; sun_y = []; sun_z = []
with open('../complete_solar-system/output/Sun.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        sun_x.append(float(l[0])); sun_y.append(float(l[1])); sun_z.append(float(l[2]))

mercury_x = []; mercury_y = []; mercury_z = []
with open('../complete_solar-system/output/Mercury.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        mercury_x.append(float(l[0])); mercury_y.append(float(l[1])); mercury_z.append(float(l[2]))

venus_x = []; venus_y = []; venus_z = []
with open('../complete_solar-system/output/Venus.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        venus_x.append(float(l[0])); venus_y.append(float(l[1])); venus_z.append(float(l[2]))

mars_x = []; mars_y = []; mars_z = []
with open('../complete_solar-system/output/Mars.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        mars_x.append(float(l[0])); mars_y.append(float(l[1])); mars_z.append(float(l[2]))

jupiter_x = []; jupiter_y = []; jupiter_z = []
with open('../complete_solar-system/output/Jupiter.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        jupiter_x.append(float(l[0])); jupiter_y.append(float(l[1])); jupiter_z.append(float(l[2]))

saturn_x = []; saturn_y = []; saturn_z = []
with open('../complete_solar-system/output/Saturn.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        saturn_x.append(float(l[0])); saturn_y.append(float(l[1])); saturn_z.append(float(l[2]))

uranus_x = []; uranus_y = []; uranus_z = []
with open('../complete_solar-system/output/Uranus.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        uranus_x.append(float(l[0])); uranus_y.append(float(l[1])); uranus_z.append(float(l[2]))

neptune_x = []; neptune_y = []; neptune_z = []
with open('../complete_solar-system/output/Neptune.txt', 'r') as f:
    for line in f:
        l = line.split("\t")
        neptune_x.append(float(l[0])); neptune_y.append(float(l[1])); neptune_z.append(float(l[2]))

Plotskip = 100 #Plot only N'th point in the vectors

ax.scatter(sun_x[::Plotskip], sun_y[::Plotskip], sun_z[::Plotskip], label = "Sun", color = "yellow")
ax.scatter(mercury_x[::Plotskip], mercury_y[::Plotskip], mercury_z[::Plotskip], label = "Mercury", color = "#7f838a")
ax.scatter(venus_x[::Plotskip], venus_y[::Plotskip], venus_z[::Plotskip], label = "Venus", color = "#a68b62")
ax.scatter(earth_x[::Plotskip], earth_y[::Plotskip], earth_z[::Plotskip], label = "Earth", color = "blue")
ax.scatter(mars_x[::Plotskip], mars_y[::Plotskip], mars_z[::Plotskip], label = "Mars", color = "orange")
ax.scatter(jupiter_x[::Plotskip], jupiter_y[::Plotskip], jupiter_z[::Plotskip], label = "Jupiter", color = "#9e8367")
ax.scatter(saturn_x[::Plotskip], saturn_y[::Plotskip], saturn_z[::Plotskip], label = "Saturn", color = "#96642f")
ax.scatter(uranus_x[::Plotskip], uranus_y[::Plotskip], uranus_z[::Plotskip], label = "Uranus", color = "#86a7b5")
ax.scatter(neptune_x[::Plotskip], neptune_y[::Plotskip], neptune_z[::Plotskip], label = "Neptune", color = "#0086bf")

<<<<<<< HEAD
axisEqual3D(ax)
plt.xlabel("Xpos")
plt.ylabel("Ypos")
plt.legend()
=======
ax.plot3D(earth_x, earth_y, earth_z)
>>>>>>> 3797ce059e5fa751c0b3c0f35ff4f66d355a52a6
plt.show()
plt.savefig('fig1.png')
