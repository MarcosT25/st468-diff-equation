# @author: Marcos Takahashi
# @school: Universidade Estadual de Campinas

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data = np.genfromtxt("plotfile.csv", delimiter=",", names=["t", "x", "y", "z"])
plt.plot(data['t'], data['x'])

plt.plot(data['t'], data['y'])

plt.plot(data['t'], data['z'])

plt.show()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(data['x'], data['y'], data['z'])

plt.show()