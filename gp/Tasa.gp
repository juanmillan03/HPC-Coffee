reset session
set term pdf
set out "pdf/Tasa.pdf"
set xlabel "x(unit)"
set ylabel "y( unit)"
set grid
set size square 
set key off
set title "Cream in Coffee"
plot 'gp/datos.dat'u 1:2 w p lt 1 pt 7 ps 0.25