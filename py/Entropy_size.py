import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

def dispercion(data_path):
    datos=pd.read_csv(data_path,sep="\t" ,names=['t','E',"S"])
    
    fig1, ax1 = plt.subplots( )
    datos["t"]=datos["t"]/1e6
    ax1.scatter(datos['t'],datos['E'],s=2)
    ax1.set_xlabel("time(10⁶unit)")
    ax1.set_ylabel("Entropy")
    ax1.grid(True, linewidth=0.1)
    plt.savefig("./pdf/Entropy.pdf")
    
    fig2, ax2 = plt.subplots( )
    ax2.scatter(datos['t']**0.5,datos['S'],s=2)
    ax2.set_xlabel("time(10⁶unit)")
    ax2.set_ylabel("Tamaño")
    ax2.grid(True, linewidth=0.1)
    plt.savefig("./pdf/Size.pdf")
    
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python graficador.py <data_path>")
        sys.exit(1)
        
    data_path = sys.argv[1]
    dispercion(data_path)