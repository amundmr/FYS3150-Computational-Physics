""
import matplotlib.pyplot as plt
from numpy import *
#import sys
#from matplotlib.patches import Polygon

#Making data
r1 = linspace(0, 5, 100)
r2 = linspace(-5, 0, 100)

y1 = exp(-4*(r1))
y2 = exp(4*(r2))


#Plotting read data

plt.plot(r1,y1, label = r"$e^{-\alpha r_1}$", color = 'g')
plt.plot(r2,y2, label = r"$e^{-\alpha r_2}$", color = 'g')
plt.ylabel(r"$e^{-\alpha r_i}$ [arb units]")
plt.xlabel("Interatomic distance, r")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Value of $e^{-\alpha r_i}$ over interatomic spacing.")
plt.legend()

plt.savefig("../../doc/latex/img/expfunc_plot.png", bbox_inches='tight')
