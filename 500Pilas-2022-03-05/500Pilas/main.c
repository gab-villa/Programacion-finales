#include <stdio.h>
#include <stdlib.h>
#include "vectorPilas.h"
#include "operarVectorPilas.h"

#define NOMBRE_ARCH_DATOS "datos.txt"
#define NOMBRE_ARCH_EXPORT "pilai.txt"
int main()
{
    tVecPila vp;
    crearVectorPilasConArch(NOMBRE_ARCH_DATOS, &vp);
    //exportarPilas(NOMBRE_ARCH_EXPORT, &vp);
    exportarPilasEnVariosArchivos(&vp);
    vaciarVecPila(&vp);
    //unlink(NOMBRE_ARCH_DATOS); borra el archivo de datos
    return 0;
}
