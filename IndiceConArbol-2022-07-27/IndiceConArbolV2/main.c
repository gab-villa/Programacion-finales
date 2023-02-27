#include <stdio.h>
#include <stdlib.h>

#include "LoteDePrueba.h"

#define NOMBRE_ARCH_PROD "Productos.dat"
#define NOMBRE_ARCH_IND "prodTC.idx"

int main()
{
    tArbol indProd;
    crearArbol(&indProd);
    if(regenerarArbolConIndice(NOMBRE_ARCH_IND, &indProd) == ARCH_ERROR)
    {
        crearLoteDePrueba(NOMBRE_ARCH_PROD);
        insertarArchivoDesordenadoEnArbol(NOMBRE_ARCH_PROD, &indProd);
        vaciarArbolEnArchIndiceEnOrd(NOMBRE_ARCH_IND, &indProd);
        insertarArchIndEnArbol(NOMBRE_ARCH_IND, &indProd);
        //mostrarArbolHorizontal(&indProd, mostrarInd);
        copiarArbolEnArchIndicePreOrd(NOMBRE_ARCH_IND, &indProd);
    }
    printf("CONTENIDO DEL INDICE PREORDEN: \n\n");
    mostrarArchInd(NOMBRE_ARCH_IND);

    printf("\n\n");
    printf("CONTENIDO DEL ARBOL: \n\n");
    mostrarArbolHorizontal(&indProd, mostrarInd);

    vaciarArbol(&indProd);
    return 0;
}
