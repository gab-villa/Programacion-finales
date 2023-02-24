#include <stdio.h>
#include <stdlib.h>

#include "normalizar.h"

#define NOMBRE_ARCH_TXT "arch.txt"
#define NOMBRE_ARCH_LIMPIO "archLimpio.txt"

int main()
{
    tCola txt;
    crearCola(&txt);
    normalizarArchivo(NOMBRE_ARCH_TXT, &txt);
    vaciarColaTxtEnArchivo(NOMBRE_ARCH_LIMPIO, &txt);
    //por las dudas
    vaciarCola(&txt);
    return 0;
}
