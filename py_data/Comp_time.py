import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

if __name__ == "__main__":        
    path1 = sys.argv[1]
    path2 = sys.argv[2]
    datos1=pd.read_csv(path1,sep=" " ,names=['size','t'])
    datos2=pd.read_csv(path2,sep=" " ,names=['size','t'])
    fig, ax = plt.subplots( )
    ax.scatter(datos1['size'],datos1['t'],label="Sin O3")
    ax.scatter(datos2['size'],datos2['t'],label="Con O3")
    ax.plot(datos1['size'],datos1['t'])
    ax.plot(datos2['size'],datos2['t'])  
    ax.set_xlabel("System size")
    ax.set_ylabel("Computing time (ms)")
    ax.grid(True, linewidth=0.1)
    ax.set_ylim(ymin = 0, ymax = 80000)
    ax.legend()
    plt.savefig("./pdf/Comp_time.pdf")  