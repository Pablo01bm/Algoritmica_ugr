#!/bin/csh
@ inicio = 1000
@ fin = 50000
@ incremento = 1000
@ i = $inicio

rm tiempos_basica.dat
rm tiempos_DyV.dat

while($i <= $fin)

    echo `./genera-duplicados $i` > vector.txt
    echo `./depuracionBasica vector.txt` >> tiempos_basica.dat
    echo `./depuracionDyV vector.txt` >> tiempos_DyV.dat
    @ i += $incremento
end



