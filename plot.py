import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits.mplot3d import Axes3D

data=np.loadtxt("datos.dat")
x=np.arange(0,100,1)
y=np.arange(0,100,1)
x1=np.arange(0,100,1)/100
y1=np.arange(0,100,1)/100

def f(x,y):
    return data[x,y]

X,Y=np.meshgrid(x,y)
X1,Y1=np.meshgrid(x1,y1)

fig=plt.figure()
ax = Axes3D(fig)
ax.plot_wireframe(X1,Y1,f(X,Y),color='green')
plt.show()
plt.savefig('imagen.png')