import numpy as np
import os
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d

fig = plt.figure()
ax = plt.axes(projection='3d')
Plotskip = 100 #Plot only N'th point in the vectors
dotsize = 1

def axisEqual3D(ax):
    extents = np.array([getattr(ax, 'get_{}lim'.format(dim))() for dim in 'xyz'])
    sz = extents[:,1] - extents[:,0]
    centers = np.mean(extents, axis=1)
    maxsize = max(abs(sz))
    r = maxsize/2
    for ctr, dim in zip(centers, 'xyz'):
        getattr(ax, 'set_{}lim'.format(dim))(ctr - r, ctr + r)


# Colors for each of the planets. Dictionary keys correspond with names of output files.
colors = {
    "Sun": "yellow",
    "Mercury": "#7f838a",
    "Venus": "#a68b62",
    "Earth": "blue",
    "Mars": "orange",
    "Jupiter": "#9e8367",
    "Saturn": "#96642f",
    "Uranus": "#86a7b5",
    "Neptune": "#0086bf"
}


# Storing paths, names and color to all the output files.
path = "../complete_solar-system/output/innerPlanets/"
outputs = {
    'path': [],
    'name': [],
    'color': [],
}

for r, d, f in os.walk(path):
    for file in f:
        outputs['path'].append(os.path.join(r,file))
        outputs['name'].append(file[:-4])
        outputs['color'].append(colors[file[:-4]])


# Plotting each output file.
for i in range(len(outputs['path'])):
    x = []; y = []; z = []
    with open(outputs['path'][i]) as f:
        for line in f:
            l = line.split('\t')
            x.append(float(l[0])); y.append(float(l[1])); z.append(float(l[2]))

        ax.scatter(x[::Plotskip], y[::Plotskip], z[::Plotskip], s=dotsize, label = outputs['name'][i], color = outputs['color'][i])
ax.scatter(0,0,s = 60, c = "#f5ed00")
axisEqual3D(ax)
ax.set_xlabel('x (AU)')
ax.set_ylabel('y (AU)')
ax.set_zlabel('z (AU)')
ax.view_init(60, 35)
plt.legend()
plt.savefig('innerPlanets.png', bbox_inches='tight')
plt.show()
