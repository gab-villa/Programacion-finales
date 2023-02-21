#include <stdio.h>
#include <stdlib.h>

#include "Vehiculos.h"
#define NOMBRE_ARCH_AUTOS "Vehiculos.bin"

int main()
{
    crearLoteDePrueba(NOMBRE_ARCH_AUTOS);
    calcularPromedio(NOMBRE_ARCH_AUTOS);
    return 0;
}
