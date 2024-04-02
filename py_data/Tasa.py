import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

if __name__ == "__main__":        
    path = sys.argv[1]
    datos=pd.read_csv(path,sep="\t" ,names=['x','y'])
    fig, ax = plt.subplots( )
    ax.scatter(datos['x'],datos['y'])
    ax.set_xlabel("x(unit)")
    ax.set_ylabel("y(unit)")
    ax.grid()
    ax.set_xlim(xmin = -105, xmax = 105)
    ax.set_ylim(ymin = -105, ymax = 105)
    plt.savefig("./pdf/Tasa.pdf")  