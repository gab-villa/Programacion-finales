#include "Vehiculos.h"

int abrirArchivo(FILE** arch, const char *nomArch, const char* ap)
{
    *arch = fopen(nomArch, ap);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se puede abrir el archivo %s en modo %s.",
                nomArch, ap);
        return ARCH_ERR;
    }
    return ARCH_OK;
}
void crearLoteDePrueba(const char *nomArch)
{
    tVehiculo autos[] = {
        {"AAAAAA", 10, 200},
        {"AAAAAB", 5, 500},
        {"AAAAAC", 5, 800},
        {"AAAAAD", 10, 300},
        {"AAAAAE", 5, 100},
        {"AAAAAF", 10, 200},
        {"AAAAAG", 5, 200},
        {"AAAAAH", 2, 300},
        {"AAAAAI", 10, 200},
        {"AAAAAJ", 10, 900},
        {"AAAAAK", 2, 2000},
        {"AAAAAL", 10, 1000}
    };
    FILE* archAutos;
    if(abrirArchivo(&archAutos, nomArch, "wb") == ARCH_ERR)
    {
        return;
    }
    fwrite(autos, sizeof(autos), 1, archAutos);
    fclose(archAutos);
}
void calcularPromedio(const char *nomArch)
{


    FILE *archAutos;
    if(abrirArchivo(&archAutos, nomArch, "rb") == ARCH_ERR)
    {
        return;
    }

    calcularPromedioProc(archAutos);

    fclose(archAutos);
}
void calcularPromedioProc(FILE *archAutos)
{
    tVehiculo v;
    tLista lsProm;
    crearLista(&lsProm);
    fread(&v, sizeof(tVehiculo), 1, archAutos);
    while(!feof(archAutos))
    {

        ponerEnOrden(&lsProm, &v, sizeof(tVehiculo),
                     compDom, NULL);
        fread(&v, sizeof(tVehiculo), 1, archAutos);
    }
    printf("LISTA DE VEHICULOS:\n\n");
    mostrarVehiculo(NULL);
    mostrarLista(&lsProm, mostrarVehiculo);

    printf("\n\n");
    printf("LISTA DE PROM DE KM RECORRIDO:\n\n");
    sacarPromDeListaOrd(&lsProm, compAnt, acumPromKmRec, sacarPromKmRec);
    mostrarVehiculo(NULL);
    mostrarLista2(&lsProm, mostrarVehiculo);
    //mostrarLista(&lsProm, mostrarVehiculo);

    vaciarLista(&lsProm);
}
int compDom(const void *v1, const void *v2)
{
    const tVehiculo *a1 = (const tVehiculo*)v1;
    const tVehiculo *a2 = (const tVehiculo*)v2;

    if(a1->ant == a2->ant)
    {
        return strcmp(a1->cod, a2->cod);
    }
    else if(a1->ant > a2->ant)
    {
        return 1;
    }
    return -1;
}
int compAnt(const void *v1, const void *v2)
{
    const tVehiculo *a1 = (const tVehiculo*)v1;
    const tVehiculo *a2 = (const tVehiculo*)v2;
    if(a1->ant > a2->ant)
    {
        return 1;
    }
    else if(a1->ant == a2->ant)
    {
        return 0;
    }
    return -1;
}
void acumPromKmRec(void *vProm, const void *v)
{
    tVehiculo *prom = (tVehiculo*)vProm;
    const tVehiculo *a = (const tVehiculo*)v;
    prom->kmRec += a->kmRec;
}
void sacarPromKmRec(void *v, unsigned cant)
{
    tVehiculo *a = (tVehiculo *)v;
    a->kmRec /= cant;
}
void mostrarVehiculo(const void *v)
{
    const tVehiculo *a = (const tVehiculo*)v;
    if(a == NULL)
    {
        printf("%-15s%-15s\n","ANTIGUEDAD","PROM_REC");
    }
    else
    {
        printf("%-15u%-13.2f\n",a->ant, a->kmRec);
    }
}
