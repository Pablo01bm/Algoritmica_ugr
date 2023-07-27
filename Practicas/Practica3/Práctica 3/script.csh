#!/bin/csh
@ inicio = 1
@ fin = 11
@ incremento = 1
@ i = $inicio

rm tiempos_greedy_1.dat
rm tiempos_greedy_2.dat
rm tiempos_fuerzabruta.dat

g++ generarPesos.cpp -o generarPesos
g++ recipientes_greedy1.cpp -o recipientes_greedy1
g++ recipientes_greedy2.cpp -o recipientes_greedy2
g++ recipientes-fuerzabruta.cpp -o recipientes-fuerzabruta

while ( $i <= $fin )
    ./generarPesos $i > pesos.txt

    ./recipientes_greedy1 pesos.txt >> tiempos_greedy_1a.dat
    

    ./recipientes_greedy2 pesos.txt >> tiempos_greedy_2a.dat
   

    ./recipientes-fuerzabruta $i >> tiempos_fuerzabruta.dat
    
    @ i += $incremento
end

rm generarPesos
rm recipientes_greedy1
rm recipientes_greedy2r
