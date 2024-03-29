reset session
set term pdf
set out "pdf/Entropy.pdf"
set xlabel "time(10⁶ steps)"
set ylabel "Entropy"
set grid
set key off
set title "Entropy versus time"
plot 'gp/entropy.dat'u ($1/1000000):2 w p lt 1 pt 4 ps 0.1