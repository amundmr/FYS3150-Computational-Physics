import matplotlib.pyplot as plt
import numpy as np
import sys
from matplotlib.patches import Polygon

#Making data
n = 100000
r = np.linspace(-2.9, 2.9, n)

y = np.exp(-2*abs(r))

#Summing all the values
sum = np.trapz(y, dx = 1/n)
print("sum is: ", sum)

#Plotting read data

plt.plot(r,y, label = r"$e^{-\alpha r_i}$", color = 'g')
plt.ylabel(r"$e^{-\alpha r_i}$ [arb units]")
plt.xlabel("Interatomic distance, r")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Value of $e^{-\alpha r_i}$ over interatomic spacing.")
plt.yscale('log')
plt.legend()

plt.savefig("expfunc_plot.png", bbox_inches='tight')
plt.show()
