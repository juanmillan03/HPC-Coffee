import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

def dispercion(data_path):
    divisions=8
    datos=pd.read_csv(data_path,sep="\t" ,names=['x','y'])
    fig, ax = plt.subplots( )
    ax.scatter(datos['x'],datos['y'])
    ax.set_xlabel("x(unit)")
    ax.set_ylabel("y(unit)")
    ax.grid()
    ax.set_xlim(xmin = -105, xmax = 105)
    ax.set_ylim(ymin = -105, ymax = 105)
    plt.savefig("./pdf/Tasa.pdf")
    
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python graficador.py <data_path>")
        sys.exit(1)
        
    data_path = sys.argv[1]
    dispercion(data_path)