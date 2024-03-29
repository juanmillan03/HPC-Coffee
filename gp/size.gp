reset session
set term pdf
set out "pdf/size.pdf"
set xlabel "Time(10⁶steps)"
set ylabel "Distancia media"
set grid
set key off
set title "Distancia media versus tiempo"
plot 'gp/tamano.dat'u ($1/1000000):2 w p lt 1 pt 7 ps 0.25