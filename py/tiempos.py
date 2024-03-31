import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

def dispercion(data_path):
    divisions=8
    datos=pd.read_csv(data_path,sep=" " ,names=['s2','t'])
    fig, ax = plt.subplots( )
    ax.scatter(datos['s2'],datos['t'])
    ax.set_xlabel("Area del vaso(unit²)")
    ax.set_ylabel("Tiempo asentamiento(steps)")
    ax.grid(True, linewidth=0.1)
    plt.savefig("./pdf/tiempos.pdf")
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python graficador.py <data_path>")
        sys.exit(1)
        
    data_path = sys.argv[1]
    dispercion(data_path)