Curso de programación para GameBoy Advance
Sesión 2

Esta sesión abarca los modos de visualización por mapas de baldosas (tilemaps) regulares de la GBA.

El uso de mapas de bits es poco eficiente en cuanto a uso de memoria y rendimiento del programa. Una sencilla imagen puede llegar a ocupar toda la memoria de video de la GBA y actualizar la pantalla entera a cada refresco se torna complicado, si no imposible. Por ello, casi todos los juegos comerciales de la consola utilizan tilemaps.

La idea es utilizar pequeñas imágenes (baldosas) con un tamaño definido, 8x8 píxeles, y distribuirlas formando una rejilla. Estas baldosas se denominan tiles. La imagen resultante de agruparlas es un tilemap.

Para implementar un tilemap se utilizan una especie de paletas de baldosas denominadas tilesheets. Estas paletas contienen todas las tiles que se pueden utilizar en un momento determinado. Se definen como pequeños mapas de bits utilizando una paleta de colores.

De esta manera, una región de la memoria contiene el tilesheet, que define los tiles, y otra contiene el tilemap, que define qué tile colocar en cada celda de la rejilla.

Los modos 0, 1 y 2 de la GBA utilizan mapas de baldosas. Cada uno de ellos tiene sus particularidades pero todos tienen en común la distribución de la memoria.

La VRAM contiene tanto los tilesheets como los tilemaps. Para los tilesheets se define una estructura denominada character block y ocupa 16KB (16384 bytes). Los tilemaps utilizan otra estructura denominada screen block que ocupa 2049 bytes.

En la definiciaón de un character block, la GBA permite dos modos de selección de color, 4bpp y 8bpp. Con 4bpp se pueden direccionar hasta 16 colores de una paleta y la paleta a utilizar se determina en el screen block. Para el modo 8bpp se direccionan los 256 colores de la paleta.

Tanto los character blocks como los screen blocks se distribuyen a lo largo de la VRAM por lo que hay 4 character blocks y 32 screen blocks en total. Cabe destacar que existe un solapamiento entre las dos estructuras de datos y gestionarlas queda a manos del programador. La siguiente figura muestra la distribución de la VRAM.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+   Memoria   + 0x06000000 + 0x06004000 + 0x06008000 + 0x0600C000 +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+  charblock  +     0      +     1      +      2     +      3     +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+ screenblock +  0 ... 7   +  8 ... 15  +  16 ... 23 +  24 ... 31 +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

El modo 0 permite la gestión de hasta 4 tilemaps simultaneos. Esto permite sobreponer un mapa a otro, creando sensación de profundidad. Cada tilemap, o background, tiene asignados 3 registros que controlan configuracìón, desplazamiento horizontal y desplazamiento vertical respectivamente.

El ejemplo-1 utiliza el modo 0 para pintar una sencilla escena construida con un tilemap indexando los colores de la paleta con 4 bits. El ejemplo-2 es igual que el anterior, esta vez indexando los colores con 8 bits. Observe como cambia la definición de tilesheet.c

Los tilamaps o backgrounds de la GBA pueden desplazarse tanto de manera vertical como horizontal. Esto permite mover varios mapas independientemente. Para ello, se dispone de un par de registros por background donde se escribe el valor del desplazamiento.

El ejemplo-3 muestra un sencillo mapa despazándose una unidad hacia la izquierda cada dos refrescos de pantalla.

El ejemplo-4 muestra dos mapas desplazándose horizontalmente en sentidos opuestos.

Especificar tanto las paletas como los character blocks a mano es una tarea pesada. Para automatizar el proceso de pasar de una imagen a una matriz de C se puede utilizar grit. El ejemplo-5 utiliza una imagen como tilesheet de la cual se extrae la información necesaria. Después se define el tilemap. Existen otras herramientas que hacen más ligera la tarea de escribir un tilemap (véase Tiled).

El comando utilizado en el Makefile del ejemplo-5 que utiliza grit para extraer información de una imagen es:

ejemplo-5$ $(DEVKITARM)/bin/grit [img] -gu16 -gt -gB8 -gTff00ff -pu16 -ftc

El campo size del registro de configuración de un background indica cuántos screen blocks ocupa y cómo se distribuyen. Esto es útil para escenas donde el mapa ocupa más de un screen block y hay desplazamiento.

Las distintas configuraciones de medida y distribución de un background se muestran en la tabla siguiente.

+++++++++++++++++++++++++
+ Tamaño + Distribución +
+++++++++++++++++++++++++
+        +  #####       +
+ 32x32  +  # 0 #       +
+        +  #####       +
+++++++++++++++++++++++++
+        +  #########   +
+ 64x32  +  # 0 # 1 #   +
+        +  #########   +
+++++++++++++++++++++++++
+        +  #####       +
+        +  # 0 #       +
+ 32x64  +  #####       +
+        +  # 1 #       +
+        +  #####       +
+++++++++++++++++++++++++
+        +  #########   +
+        +  # 0 # 1 #   +
+ 64x64  +  #########   +
+        +  # 2 # 3 #   +
+        +  #########   +
+++++++++++++++++++++++++

El ejemplo-6 utiliza un background de 64x32 tiles.

Los modos 1 y 2 de la GBA permiten el uso de backgrounds afines los cuales no se cubren en esta sesión. El modo 1 utiliza 2 backgrounds regulares y 1 afín. El modo 2 utiliza 2 backgrounds afines.

ejercicio-1: Cree un programa que haga uso del modo 0 para pintar una escena utilizando 4 backrounds de manera simultanea.

ejercicio-2: Modifique el programa anterior para que almenos 2 de los backgrounds se muevan de manera independiente.

Para juegos con mapas muy grandes con transiciones continuas debe diseñarse un mecanismo que configure el background para que cumpla los requisitos de la aplicación.

El tamaño máximo de un background es de 64x64 tiles (2x2 screen blocks). Por tanto, es necesario actualizar la región de memoria del background y el desplazamiento del mismo.

Es necesario considerar que, en un momento dado, en la pantalla se muestran un máximo de 4 screen blocks de manera simultanea. Con esto se debe detectar el punto en el que un screen block no es visible y cambiarlo por uno visible. Otro modo es actualizar los márgenes de los screen blocks. De esta manera, no se cambia el screen block a mostrar.

ejercicio-3: Construya un mapa de un tamaño mayor a 64x64 tiles y diseñe un programa que desplace la ventana de visión por el mismo.