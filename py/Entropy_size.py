import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm
from scipy.stats import linregress


def plot(data_path):
    datos=pd.read_csv(data_path,sep="\t" ,names=['t','E',"S"])
    
    fig1, ax1 = plt.subplots( )
    
    
    
    ax1.scatter(datos['t']/1e6,datos['E'],s=2)
    ax1.set_xlabel("time(10⁶unit)")
    ax1.set_ylabel("Entropy")
    ax1.grid(True, linewidth=0.1)
    plt.savefig("./pdf/Entropy.pdf")
    
    log_t=np.log(datos["t"][17:106])
    log_s=np.log(datos["S"][17:106])
    slope, intercept, r_value,p_value,std_err= linregress(log_t,log_s)
    
    n=len(log_s)
    se_intercept= std_err*np.sqrt(np.sum(log_t**2)/n)
    
    teori_t=np.linspace(min(log_t),14.6)
    teori_s= intercept+slope*teori_t
    
    fig2, ax2 = plt.subplots( )
    label_ajuste=f'Regresion K*ln(t)+b\n K={slope:.3f} ± {std_err:.3f} -- b={intercept:.2f} ± {se_intercept:.2f}'
    ax2.scatter(np.log(datos["t"][16:]),np.log(datos["S"][16:]),s=2,c="b",label="Tamaño medio")
    ax2.plot(teori_t,teori_s,label=label_ajuste,c="r",linestyle='--')
    ax2.set_xlabel("Ln( Tiempo )")
    ax2.set_ylabel("Ln( Tamaño )")
    ax2.grid(True, linewidth=0.1)
    ax2.legend()
    plt.savefig("./pdf/Size.pdf")
    
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python graficador.py <data_path>")
        sys.exit(1)
        
    data_path = sys.argv[1]
    plot(data_path)