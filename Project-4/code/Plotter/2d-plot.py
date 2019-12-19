import matplotlib.pyplot as plt
import numpy as np
import csv

def fileToList():
    data = input("Data file (csv): ")
    name = data.split(".")
    title = []

    file = open("../Ising/"+data,"r")
    reader = csv.reader(file, delimiter=" ")
    axes = next(reader)
    ncol = len(axes)
    nrow = len(list(reader))
    file.seek(0)
    reader = csv.reader(file, delimiter=" ")

    for i in range(ncol-1):
        title.append(input("Title of plot number "+str(i+1)+" (column header is \'"+axes[i+1]+"\'): "))

    i = 0
    plot_data = np.zeros((ncol,nrow-1))
    next(reader)
    for row in reader:
        plot_data[:,i-1] = np.array(row)
        i += 1

    return plot_data,title,axes,name,ncol


plot_data,title,axes,name,ncol = fileToList()

x = plot_data[0,:]

for i in range(ncol-1):
    y = plot_data[i+1,:]

    #plt.plot(np.log10(x),np.cumsum(y))
    plt.plot(x,np.cumsum(y))
    #plt.plot(np.log10(x),y)
    #plt.plot(x,y)
    plt.xlabel(axes[0])
    plt.ylabel(axes[i+1])
    plt.title(title[i])
    plt.savefig("../../doc/latex/img/"+name[0]+"_"+str(i+1)+".png")
    plt.close()
