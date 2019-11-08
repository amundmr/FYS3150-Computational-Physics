import matplotlib.pyplot as plt
import numpy as np
import csv

def fileToList():
    print("Data file (csv):")
    data = input()
    file = csv.reader(open(data,"r"), delimiter=",")
    x = []
    y = []

    for row in file:
        if file.line_num == 1:
            axes = row
        else:
            x.append(float(row[0]))
            y.append(float(row[1]))

print("Plot title:")
title = input()

plt.plot(x,y)
plt.xlabel(axes[0])
plt.ylabel(axes[1])
plt.title(title)
plt.savefig(title+".png")
