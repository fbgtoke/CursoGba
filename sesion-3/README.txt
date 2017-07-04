Curso de programación para GameBoy Advance
Sesión 3

En esta sesión se trata el manejo de Sprites. Éstos son los entes más dinámicos del videojuego. Se utilizan para representar los personajes y elementos interactivos en una escena.

La GBA da soporte hardware a los Sprites reservando una región de memoria denominada Object Attribute Memory (OAM). Aquí se almacenan hasta 128 registros denominados Object Attributes (OBJ_ATTR) que definen los parámetros de los sprites en uso. Por tanto, la GBA puede manejar hasta 128 sprites simultáneos.

Cada sprite se compone por pequeños tiles de 8x8 píxeles y se definen en los Character Blocks 4 y 5 (también conocidos como OVRAM). Esta definición es análoga a la definición de tiles en los modos de Tilemap. También es necesario definir una paleta de colores en la región de memoria OBJPALMEM, contigua a la PALMEM.

La defini
ción de los tiles de un sprite puede realizarse distribuyéndolos de dos maneras:

	- La distribución 1D asume que los tiles que componen el sprite siguiendo el orden izquierda-derecha y arriba-abajo se disponen de forma consecutiva en la OVRAM.

	- La distribución 2D asume que los tiles que componen el sprite siguiendo el orden izquierda-derecha se disponen de forma consecutiva en la OVRAM y cada linea siguiendo el orden arriba-abajo se alinea a 32 tiles.

La configuración de la distribución se hace sobre el registro DISPCNT.

Una vez inicializada la OVRAM y la OBJPALMEM, es necesario configurar los parámetros del OBJ_ATTR. Estas estructuras de datos ocupan 64bits divididos en palabras de 16bits. La primera palabra se denomina Attr0, la segunda Attr1, la tercera Attr2 y la tercera no contiene información relevante. Cada atributo define una serie de características. Más información en la definición de estas estructuras de datos en el archivo mem.h.

El ejemplo-1 muestra un sprite en el centro de la pantalla con el modo de color 4bpp y distribución 1D. Para ello se ha invocado el programa grit con el siguiente comando:

ejemplo-1$ $(DEVKITARM)/bin/grit quote1d.png -gu16 -gB4 -ftc

Obsérvese que hay una inicialización previa de la OAM. Esto es debido a que la memoria de la GBA no se inicializa al encenderse. Por tanto, es posible que se configure la OAM para mostrar sprites, cuyo resultado serían errores visuales en pantalla.

Otro punto a tener en cuenta es el uso de un buffer para los OBJ_ATTR. Esto es útil porque la GBA no permite escribir sobre la OAM durante el VDRAW. Para prevenir escrituras fallidas, se hace uso del buffer y se actualiza la OAM durante el VBLANK.

El ejemplo-2 muestra un sprite en el centro de la pantalla con el modo de color 4bpp y distribución 2D.

El ejemplo-3 muestra un sprite desplazándose en diagonal por la pantalla. Obsérvese como la posición definida en el OBJ_ATTR es relativa a la esquina superior izquierda de la pantalla. Nótese también el uso de máscaras de bits para actualizar el contenido de los attributos de un objeto.

ejercicio-1: Defina las máscaras de bits y operaciones necesarias para implementar la actualización de los atributos del OBJ_ATTR.

ejercicio-2: Complete el código para controlar el sprite con las flechas direccionales.

ejercicio-3: Utilice el modo 0 de la GBA para dibujar un Tilemap de fondo junto a un sprite. Observe como el movimiento del Tilemap y del sprite es independiente.

ejercicio-4: Utilice el modo 0 de la GBA para dibujar un Tilemap que interactúe con un sprite.

ejercicio-5: Diseñe una escena que contenga varios sprites en pantalla al mismo tiempo.