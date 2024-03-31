import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

def dispercion(data_path):
    datos=pd.read_csv(data_path,sep="\t" ,names=['t','E',"S"])
    
    fig1, ax1 = plt.subplots( )
    ax1.scatter(datos['t']/1e6,datos['E'],s=2)
    ax1.set_xlabel("time(10⁶unit)")
    ax1.set_ylabel("Entropy")
    ax1.grid(True, linewidth=0.1)
    plt.savefig("./pdf/Entropy.pdf")
    
    fig2, ax2 = plt.subplots( )
    t=np.arange(0, 1.5, 0.2)
    ax2.plot(t,45*t+4)
    ax2.scatter((datos['t']/1e6)**0.5,datos['S'],s=2,c="r")
    ax2.set_xlabel(r"tiempo$^{1/2}$(10⁶unit)")
    ax2.set_ylabel("Tamaño")
    ax2.grid(True, linewidth=0.1)
    plt.savefig("./pdf/Size.pdf")
    
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python graficador.py <data_path>")
        sys.exit(1)
        
    data_path = sys.argv[1]
    dispercion(data_path)