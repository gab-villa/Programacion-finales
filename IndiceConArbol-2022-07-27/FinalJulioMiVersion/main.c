#include <stdio.h>
#include <stdlib.h>

#include "LoteDePrueba.h"
#include "tArbol.h"

#define NOMBRE_ARCH_PRUEBA "productos.dat"
#define NOMBRE_ARCH_INDICE "ProdTC.idx"

int main()
{
    tArbol p;
    crearArbol(&p);
    crearLoteDePrueba(NOMBRE_ARCH_PRUEBA);
    cargarArbolConPrueba(&p, NOMBRE_ARCH_PRUEBA);
    printf("********** ");
    printf("ARBOL SIN BALANCEAR: ");
    printf("**********\n\n");
    //mostrarArbolGrafico(&p, mostrarIndice);
    mostrarArbolGrafico(&p, mostrarIndiceConForma);
    printf("\n\naltura: %d" , alturaArbol(&p));
    printf("\n\n");



    vaciarArbolEnIndice(&p, NOMBRE_ARCH_INDICE);
    crearArbolDeIndiceBalanceado(NOMBRE_ARCH_INDICE, &p);
    //mostrarArbolGrafico(&p, mostrarIndice);

    //mostrarArchivoIndice(NOMBRE_ARCH_INDICE);

    //mostrarArbolEnOrden(&p, mostrarIndice);
    printf("********** ");
    printf("ARBOL BALANCEADO: ");
    printf("**********\n\n");
    mostrarArbolGrafico(&p, mostrarIndiceConForma);
    printf("\n\naltura: %d" , alturaArbol(&p));

    printf("HIJOS DEL ARBOL: \n");
    mostrarIndice(NULL);
    mostrarHijos(&p, mostrarIndice);

    vaciarArbol(&p);
    return 0;
}
