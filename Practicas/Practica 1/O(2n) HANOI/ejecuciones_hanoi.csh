#!/bin/csh
@ inicio = 2
@ fin = 30
@ incremento = 1
set ejecutable = hanoi
set salida = tiempos_hanoi.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
