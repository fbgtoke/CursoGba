Curso de programación para GameBoy Advance
Sesión Extra 1

En esta sesión tiene como objetivo mostrar al alumno la forma de añadir interacción con el usuario mediante los botones físicos de la consola.

Igual que muchos otros aspectos de la consola, el input del usuario se puede leer en un registro de memória. Este registro se encuentra mapeado a la posición 0x04000130. 

Los 10 bits mas bajos de este registro indican, cada uno, el estado actual de uno de los botones de los que dispone la consola. En el archivo "input.h" se puede ver un listado de estos 10 botones. Hay que destacar que el estado de estos bits esta invertido, cuando el botón correspondiente esta pulsado el bit tiene el valor de 0 y cuando no se pulsa el botón tiene le valor de 1.

Por lo tanto, simplemente leyendo los valores del registro podemos saber si un botón esta pulsado o no. Pero esto no es suficiente para poder implementar algunas funcionalidades comunes en la mayoria de juegos. En algunos casos queremos realizar una acción solo una vez por cada click del botón. 

Por ejemplo, el botón de start se usa para pausar y reanudar el juego. A 60 fotogramas por segundo, si realizamos este cambio mientras el botón esté pulsado, en un click se pausará y reanudará el juego múltiples veces y el estado final del juego sera basicamente aleatorio.

Para evitar este problema se puede usar un tartamiento síncrono del input de usuario. Al principio de cada fotograma se guarda el estado de los botones, guardando además el estado de los botones en el fotograma anterior. De esta forma podemos comparar el estado actual de los botones con el esatdo del fotograma anterior, permitiendonos detectar cuando si un boton ha sido pulsado justo en este fotograma o ya estaba siendo pulsado en el fotograma anterior.

ejemplo-1: Los archivos "input.h" y "input.c" contienen la implementación de un sistema síncrono de input para la GBA.   

ejercicio-1: Modifique el programa de ejemplo para que el movimiento se produzca cuando se mantiene pulsada alguna de las teclas de dirección.

ejercicio-2: Modifique el programa de ejemplo para que el movimiento se produzca usando las funciones de tristates (ver input.c), ademas añada funcionalidad a un botón (A o B) para que se limpie la pantalla (pintarla de negro). 