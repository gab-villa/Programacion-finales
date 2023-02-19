#include "LoteDePrueba.h"

int abrirArchivo(FILE** arch, const char *nomArch, const char* ap)
{
    *arch = fopen(nomArch, ap);
    if(arch == NULL)
    {
        fprintf(stderr, "No se puede abrir el archivo %s en modo %s.",
                nomArch, ap);
        return ARCH_ERR;
    }
    return ARCH_OK;
}
int esMayus(char car)
{
    return car >= 'A' && car <= 'Z';
}
int esMinus(char car)
{
    return car >= 'a' && car <= 'z';
}
int esLetra(char car)
{
    return esMayus(car) || esMinus(car);
}

void procesarArchivo(const char *nomArch)
{
    tPila cla;
    crearPila(&cla);
    char reg[MAX_LEN];
    FILE *archOfus, *archDesofus;

    if(abrirArchivo(&archOfus, nomArch, "rt") == ARCH_ERR)
    {
        return;
    }
    if(abrirArchivo(&archDesofus, "temp.txt", "wt") == ARCH_ERR)
    {
        fclose(archOfus);
        return;
    }

    while(fgets(reg, MAX_LEN, archOfus))
    {

        if(esClave(reg, &cla) == ES_CLA)
        {
            //mostrarPila(&cla);
            //printf("\n");
            //vaciarPila(&cla);
            vaciarPilaEnCadena(reg, &cla);
            fprintf(archDesofus, "%s", reg);
        }
    }

    fclose(archOfus);
    fclose(archDesofus);

    unlink(nomArch);

    if(rename("temp.txt", nomArch) != 0)
    {
        printf("q esta pasandooo");

    }
}
void vaciarPilaEnCadena(char *cad, tPila *p)
{
    char *ini = cad;
    char car;
    while(*cad && verTope(p, &car, sizeof(char)) != PI_VACIA)
    {
        eliminarDePila(p);
        *cad = car;
        ++cad;
    }
    //cortar la cadena antes de mandarla
    *cad = '\0';
    invertir(ini);
    vaciarPila(p);
}

int esClave(const char *reg, tPila *cla)
{
    char car;
    if(*reg)
    {
        insertarEnPila(cla, reg, sizeof(char));
        ++reg;
        while(*reg)
        {
            if(verTope(cla, &car, sizeof(char)) != PI_VACIA &&
               compCar(car, *reg))
            {
                eliminarDePila(cla);
            }
            else
            {
               insertarEnPila(cla, reg, sizeof(char));
            }

            ++reg;
        }
    }
    return pilaVacia(cla) ? NO_ES_CLA : ES_CLA;
}
int compCar(char a, char b)
{
    if(esLetra(a) && esLetra(b))
    {
        b = esMayus(b) ? toupper(b) : tolower(b);
    }
    return a == b;
}
void invertir(char *cad)
{
    char aux;
    char *fin = cad;
    if(!*cad)
    {
        return;
    }
    while(*fin)
    {
        ++fin;
    }
    --fin;

    while(cad < fin)
    {
        aux = *cad;
        *cad = *fin;
        *fin = aux;
        ++cad;
        --fin;
    }
}
