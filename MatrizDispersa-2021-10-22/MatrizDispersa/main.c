#include <stdio.h>
#include <stdlib.h>
#include "matrizDispersa.h"
#define NOMBRE_ARCH_DATOS "mat1.txt"

int main()
{
    tFila maxDP;
    tMatrizRala mr;
    verificarMatrizRala(NOMBRE_ARCH_DATOS);
    crearMatrizRala(&mr, sacarFilaDeArchivo(NOMBRE_ARCH_DATOS));

    cargarMatrizRala(NOMBRE_ARCH_DATOS, &mr);
    imprimirMatRala(&mr);

    maxDP = maxDP_mat_rala(&mr);
    printf("\n max: %d %d %d", maxDP.fila, maxDP.c.col, maxDP.c.val);

    vaciarMatrizRala(&mr);
    return 0;
}
