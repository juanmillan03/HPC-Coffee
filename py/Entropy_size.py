import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

def dispercion(data_path):
    divisions=8
    datos=pd.read_csv(data_path,sep="\t" ,names=['t','E',"S"])
    fig1, ax1 = plt.subplots( )
    datos["t"]=datos["t"]/1e6
    ax1.scatter(datos['t'],datos['E'])
    ax1.set_xlabel("t(10⁶unit)")
    ax1.set_ylabel("Entropy")
    ax1.grid(True, linewidth=0.1)
    plt.savefig("./pdf/Entropy.pdf")
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python graficador.py <data_path>")
        sys.exit(1)
        
    data_path = sys.argv[1]
    dispercion(data_path)