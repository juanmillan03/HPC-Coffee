import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import linregress
from scipy.stats import norm

def dispercion(data_path):
    datos=pd.read_csv(data_path,sep=" " ,names=['s','t'])
    log_s=np.log(datos['s'])
    log_t=np.log(datos["t"])
    
    slope, intercept, r_value,p_value,std_err= linregress(log_s,log_t)
    
    n=len(log_s)
    se_intercept= std_err*np.sqrt(np.sum(log_s**2)/n)
    
    teori_s=np.linspace(min(log_s),max(log_s))
    teori_t= intercept+slope*teori_s
    
    fig, ax = plt.subplots( )
    ax.scatter(log_s,log_t,label="Entropia")
    label_ajuste=f'Regresion K*ln(s)+b\n K={slope:.2f} ± {std_err:.2f} -- b={intercept:.1f} ± {se_intercept:.1f}'
    ax.plot(teori_s,teori_t,label=label_ajuste,c="red",linestyle='--')
    ax.set_xlabel("Ln(Tamaño)")
    ax.set_ylabel("Ln( Tiempo )")
    ax.grid(True, linewidth=0.1)
    ax.legend()
    plt.savefig("./pdf/tiempos.pdf")
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python graficador.py <data_path>")
        sys.exit(1)
        
    data_path = sys.argv[1]
    dispercion(data_path)