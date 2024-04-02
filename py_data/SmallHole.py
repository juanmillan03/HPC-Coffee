import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm    
    
if __name__ == "__main__":
    path = sys.argv[1]
    datos = pd.read_csv(path, sep="\t", names=['t', 'te', "muestra"])
    
    fig1, ax1 = plt.subplots()
    ax1.scatter(datos['t'], datos['te'], s=2, label="Theorical cream molecules", color='blue')  # Añadido label y color
    ax1.scatter(datos['t'], datos['muestra'], s=2, label="Simulated cream molecules", color='orange')  # Añadido label y color
    ax1.set_xlabel("time(10⁶unit)")
    ax1.set_ylabel("Number of cream molecules inside the container")
    ax1.grid(True, linewidth=0.1)
    ax1.legend()  # Muestra las leyendas en la gráfica
    plt.savefig("./pdf/Smallhole.pdf")

