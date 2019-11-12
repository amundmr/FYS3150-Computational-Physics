import matplotlib.pyplot as plt
import numpy as np
import csv

def fileToList():
    print("Data file (csv):")
    data = input()
    title1 = "Magnetization"
    title2 = "Energy"

    file = csv.reader(open(data,"r"), delimiter=" ")

    x = []; y = []; z = []

    for row in file:
        if file.line_num == 1:
            axes = row
        else:
            x.append(float(row[0]))
            y.append(float(row[1]))
            z.append(float(row[2]))
    
    return x,y,z,title1,title2,axes,data.split(".")

x,y,z,title1,title2,axes,data = fileToList()

plt.plot(x,y)
plt.xlabel(axes[0])
plt.ylabel(axes[1])
plt.title(title1)
plt.savefig(data[0]+"_1.png")

plt.close()

plt.plot(x,z)
plt.xlabel(axes[0])
plt.ylabel(axes[2])
plt.title(title2)
plt.savefig(data[0]+"_2.png")