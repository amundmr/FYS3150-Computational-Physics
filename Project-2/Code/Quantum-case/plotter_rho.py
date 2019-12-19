import matplotlib.pyplot as plt
import numpy as np
import sys

#Reading from file
f = open(sys.argv[1],"r")
lines=f.readlines()
x = np.zeros(len(lines))
y = np.zeros_like(x)
y1 = np.zeros_like(x)
i=0
for line in lines:
    x[i] = float(line.split()[0])
    y[i] = float(line.split()[1])
    y1[i] = float(line.split()[2])
    i += 1

#Ploting read data
plt.figure(figsize=(6,8))
plt.subplot(211)
plt.scatter(x,y, label = "Average error of Eigenvalues", color = 'g')
plt.plot(x,y,color='gray', linewidth=1)
plt.ylabel("Average Error")
#plt.xlabel("Integration points, N")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Presicion and time varies with $\rho_{max}$. Integration points = 200")
#plt.yscale('log')
#plt.legend()

plt.subplot(212)
plt.scatter(x,y1, label = "Time spent", color = 'b')
plt.plot(x,y1,color='gray', linewidth = 1)
plt.ylabel("Time spent(s)")
plt.xlabel(r"$\rho_{max}$")
plt.tick_params(direction='in', top = 'true', right = 'true')
#plt.legend()


#plt.suptitle("Presicion and time increase with more integration points")
plt.savefig("PLOT_rho.png", bbox_inches='tight')
plt.show()
