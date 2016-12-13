#!/bin/csh
@ inicio = 100
@ fin = 20600
@ incremento = 500
set ejecutable = ej_5
set salida = tiempos_ej_5.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
