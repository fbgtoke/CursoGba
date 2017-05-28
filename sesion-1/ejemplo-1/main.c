/**
  VGA - Curso GBA
  Ejemplo 1

  Este programa muestra un mensaje en pantalla utilizando el modo de dibujo 3 
  sobre el fondo 2 de la GameBoy Advance.
*/
int main() {
  *(unsigned int*)0x04000000 = 0x0403;

  /* H */
  ((unsigned short*)0x06000000)[80 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 81 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 82 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 83 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 84 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 85 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 86 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 88 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 89 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 90 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 91 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 92 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 93 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 94 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[80 + 95 * 240] = 0x001f;

  ((unsigned short*)0x06000000)[81 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[82 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[83 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[84 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[85 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[86 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[87 + 87 * 240] = 0x001f;

  ((unsigned short*)0x06000000)[88 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 81 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 82 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 83 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 84 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 85 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 86 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 88 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 89 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 90 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 91 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 92 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 93 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 94 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[88 + 95 * 240] = 0x001f;

  /* E */
  ((unsigned short*)0x06000000)[96 + 80 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 81 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 82 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 83 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 84 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 85 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 86 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 87 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 88 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 89 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 90 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 91 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 92 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 93 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 94 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[96 + 95 * 240] = 0x03e0;

  ((unsigned short*)0x06000000)[ 96 + 80 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 97 + 80 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 98 + 80 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 99 + 80 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[100 + 80 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[101 + 80 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[102 + 80 * 240] = 0x03e0;

  ((unsigned short*)0x06000000)[ 96 + 87 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 97 + 87 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 98 + 87 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 99 + 87 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[100 + 87 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[101 + 87 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[102 + 87 * 240] = 0x03e0;

  ((unsigned short*)0x06000000)[ 96 + 95 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 97 + 95 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 98 + 95 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[ 99 + 95 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[100 + 95 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[101 + 95 * 240] = 0x03e0;
  ((unsigned short*)0x06000000)[102 + 95 * 240] = 0x03e0;

  /* L */
  ((unsigned short*)0x06000000)[110 + 80 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 81 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 82 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 83 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 84 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 85 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 86 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 87 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 88 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 89 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 90 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 91 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 92 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 93 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 94 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[110 + 95 * 240] = 0x7c00;

  ((unsigned short*)0x06000000)[110 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[111 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[112 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[113 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[114 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[115 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[116 + 95 * 240] = 0x7c00;

  /* L */
  ((unsigned short*)0x06000000)[124 + 80 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 81 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 82 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 83 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 84 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 85 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 86 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 87 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 88 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 89 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 90 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 91 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 92 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 93 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 94 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[124 + 95 * 240] = 0x7c00;

  ((unsigned short*)0x06000000)[124 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[125 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[126 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[127 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[128 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[129 + 95 * 240] = 0x7c00;
  ((unsigned short*)0x06000000)[130 + 95 * 240] = 0x7c00;

  /* O */
  ((unsigned short*)0x06000000)[138 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 81 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 82 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 83 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 84 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 85 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 86 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 88 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 89 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 90 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 91 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 92 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 93 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 94 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[138 + 95 * 240] = 0x001f;

  ((unsigned short*)0x06000000)[138 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[139 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[140 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[141 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[142 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[143 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[144 + 80 * 240] = 0x001f;

  ((unsigned short*)0x06000000)[138 + 95 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[139 + 95 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[140 + 95 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[141 + 95 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[142 + 95 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[143 + 95 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[144 + 95 * 240] = 0x001f;

  ((unsigned short*)0x06000000)[145 + 80 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 81 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 82 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 83 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 84 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 85 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 86 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 87 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 88 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 89 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 90 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 91 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 92 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 93 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 94 * 240] = 0x001f;
  ((unsigned short*)0x06000000)[145 + 95 * 240] = 0x001f;

  while (1);

  return 0;
}