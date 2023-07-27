#!/bin/csh
@ inicio = 30
@ fin = 500
@ incremento = 10
set ejecutable = dijkstra
set salida = tiempos_dijstra.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000 ` >> $salida
  @ i += $incremento
end
