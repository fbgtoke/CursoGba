Curso de programación para GameBoy Advance
Sesión 1

Esta sesión sirve a modo de introducción al curso. Su objetivo es familiarizar al alumno con las herramientas de desarrollo que se usarán a lo largo de las sesiones.

Una vez configurado el entorno de desarrollo, se invita a compilar y ejecutar el ejemplo-1.

ejemplo-1$ make
ejemplo-1$ mgba main.gba

Se observa un mensaje en pantalla: "HELLO". El archivo main.c contiene el código del programa. No se espera que el alumno entienda el programa por el momento pero sí que observe como prácticamente todas las sentencias escriben valores sobre la memoria de la máquina. Se distinguen 2 accesos:
	1.- Inicialización   => 0x04000000
	2.- Volcado de datos => 0x06000000

La inicialización del programa configura ciertos parámetros de visualización de la consola. Las sentencias posteriores simplemente asignan un color determinado a píxeles de la pantalla.

La GameBoy Advance cuenta con diversos modos de visualización. Los modos 0-2 utilizan paletas de tiles (tilemaps) y los modos 3-5 mapas de bits. El ejemplo-2 muestra 3 píxeles por pantalla utilizando el modo 3.

Observando el código del ejemplo-2 se aprecian las 2 zonas de memoria discutidas con anterioridad. En primer lugar, DISPCNT es el registro en memoria que controla la configuración de la pantalla. Es en esta posición donde se debe especificar el modo en uso, el fondo (background) a utilizar y otras configuraciones. Nótese que el ejemplo-2 activa el background 2 específicamente. Esto es porque los modos de mapa de bits utilizan, forzosamente, este fondo.

Más adelante se define la región de memoria VRAM, que es donde todos los datos a mostrar por pantalla deben llegar. Es importante notar el hecho de que las escrituras sobre la VRAM se hacen a tamaño de 16bits, pues la máquina no soporta escrituras de 8bits en esta región.

El modo 3 asigna una palabra de 16bits a cada píxel de la pantalla por lo que dibujar primitivas sencillas es trivial. Obsérvese que las componentes de color de cada píxel ocupan 5bits cada una, dejando el bit de mayor peso sin uso.

ejercicio-1: diseñe una función que dibuje una caja rectangular dados los vértices y un color a partir de la cabecera siguiente.

void m3_draw_rect(int l, int t, int r, int b, uint16_t color)

Donde l, t, r y b son los extremos izquierdo, superior, derecho e inferior respectivamente de acuerdo al sistema de coordenadas con origen en la esquina superior iquierda de la pantalla.

El ejemplo-3 es similar al ejemplo-2. Esta vez se utiliza el modo 4 de visualización. La diferencia reside en que ahora cada píxel no contiene el color sino un índice de paleta. La paleta de colores a utilizar se almacena en otro lugar de la memoria. Este modo asigna una palabra de 8bits por píxel por lo que solo se pueden mostrar 256 colores distintos en un instante determinado.

Recuerde que aunque la palabra dedicada al píxel es de 8bits, la VRAM no permite escrituras con una granularidad tan fina. El byte de menor peso corresponderá al píxel izquierdo y el byte de mayor peso al derecho.

ejercicio-2: diseñe una función que dibuje una caja rectangular dados los vértices y un color a partir de la cabecera siguiente.

void m4_draw_rect(int l, int t, int r, int b, uint8_t index)

Nótese como, al designar la mitad de bits a un píxel, el modo 4 deja espacio en la VRAM para otro mapa de bits. Los mapas de bits ocupan las siguientes regiones de memoria:
	1.- 0x06000000 - 0x060095ff
	2.- 0x0600A000 - 0x060135ff

La máquina cuenta con la funcionalidad añadida de mostrar por pantalla uno u otro mapa de bits según la configuración del DISPCNT. Esto permite escribir sobre una de las ventanas mientras la otra se muestra. Esta funcionalidad recibe el nombre de page-flipping.

ejercicio-3: revise la descripción del registro DISPCNT para encontrar la configuración del page-flipping. Posteriormente, escriba un programa que utilice esta funcionalidad alternando entre las dos ventanas de manera periódica.

Por último, el ejemplo-4 muestra 2 figuras alternando colores. Este ejemplo utiliza el modo 5 y la funcionalidad de page-flipping. Este modo es una combinación de los modos 3 y 4: cada píxel se expresa con una palabra de 16bits (modo 3) y se permite el page-flipping (modo 4). No obstante, para que ambas ventanas quepan en memoria, se reduce el tamaño de la ventana a 160x128 píxeles.

ejercicio-4: Analice las imágenes del directorio y justifique si es posible representarlas utilizando el modo 4 de la máquina. En caso positivo, escriba un programa que muestre algunas por pantalla.

Una vez familizarizado con los modos de mapa de bits, salta a la vista que asignar valores a píxeles uno a uno incrementa en gran medida el volumen del código. El ejemplo-5 utiliza una matriz de valores para definir un mapa de bits en modo 3 y un bucle for que la recorre para copiarla sobre la VRAM.

La distribución de devkitARM incluye una herramienta que genera la matriz de valores a partir de una imagen. Esta herramienta se llama grit y el comando utilizado para conseguir la matriz del ejemplo-5 es el siguiente:

ejemplo-5$ $DEVKIT_ARM/bin/grit [imagen] -gb -gB16 -gu16 -ftc

Nótese que el ejemplo-5 recorre la matriz hasta que el valor del iterador es igual a la mitad del tamaño de la misma. Esto es porque el tamaño descrito por grit viene dado en bytes y cada elemento ocupa 2 bytes (16bits).

La copia a utilizando un bucle for dista mucho de ser la mejor opción. El ejemplo-6 muestra como utilizar el DMA de la máquina. Con esta operación, la CPU se detiene mientras la memoria gestiona la copia de los datos. Esto es útil para ahorrar número de instrucciones ejecutadas y, por tanto, consumo de energía.

ejercicio-5: Encapsule la funcionalidad de copia de datos por DMA en 2 funciones con las siguientes cabeceras.

void memcpy16(uint32_t src, uint32_t des, uint16_t count)
void memcpy32(uint32_t src, uint32_t des, uint16_t count)

Una vez implementada la copia de mapas de bits, es posible realizar un programa que muestre en secuencia varias imágenes: un video. Para ello será necesario controlar la velocidad con la que se avanza al siguiente fotograma.

El ejemplo-7 implementa una posible versión. Este ejemplo incluye un corto video en formato mp4 y un script de bash que lo convierte a una sola imagen png habiendo extraído algunos fotogramas. Para utilizar el script, copie el siguiente comando:

ejemplo-7$ sh video_to_gba.sh [nombre]

Se generará un subdirectorio con todos los fotogramas extraídos y la imagen final. Posteriormente, utilice el comando make para compilar el programa. Observe que el Makefile realiza también la conversión de la imagen png a matriz de datos.

Por último, fíjese en la gestión del periodo VBlank. Este ejemplo realiza una espera activa hasta que la máquina deja de pintar sobre la pantalla para introducir nuevos datos en la VRAM. En ejemplos posteriores se enseña otro método para realizar esta espera a través de interrupciones.

ejercicio-8: Para evitar redefinir constantes y direcciones de memoria, cree un archivo mygbalib.h con las definiciones que considere apropiadas. Esto le resultará útil en las sesiones posteriores.

ejercicio-9: Recopile las funciones de dibujo que ha diseñado a lo largo de la sesión y añada otras que crea convenientes.