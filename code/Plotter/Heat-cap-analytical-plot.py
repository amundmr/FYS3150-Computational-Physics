import numpy as np
import matplotlib.pyplot as plt

def f(T):
    kb = 1
    J = 1
    f = (64*J**2*(1/(2*np.cosh(8*J/(kb*T))))**2 * (4 + 12*np.cosh(8*J/(kb*T))))**2 / (kb*T*T)
    return f
def newf(T):
    kb = 1
    J = 1
    b = 1/(kb*T)
    f = 1/(kb*T) * 64*J*J*(np.cosh(b*8*J)/(np.cosh(b*8*J)+3) -(-np.sinh(b*8*J)/(np.cosh(b*8*J)+3))**2)
    return f

def Daniel(T):
    kb = 1
    J = 1
    f = 1/(kb*T) *( (256*J*J * np.cosh(8*J/(kb*T)))/ (4*np.cosh(8*J/(kb*T)) + 12) - ((8*J*np.sinh(8*J/(kb*T)))/(np.cosh(8*J/(kb*T)) + 3))**2)
    return f
T = np.linspace(2,4.5,100)
Cv = newf(T)
Daniel = Daniel(T)
print(T)
print(Cv)
plt.plot(T,Daniel)
plt.plot(T,Cv)
plt.show()
