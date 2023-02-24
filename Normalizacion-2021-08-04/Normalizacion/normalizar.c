#include "normalizar.h"

int abrirArchivo(FILE **arch, const char *nomArch, const char *ap)
{
    *arch = fopen(nomArch, ap);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se ha podido abrir el archivo %s en modo %s.",
                nomArch, ap);
        return ARCH_ERROR;
    }
    return ARCH_OK;
}
void vaciarColaTxtEnArchivo(const char *nomArch, tCola* txt)
{
    int car;
    FILE *arch;
    if(abrirArchivo(&arch, nomArch, "wt") == ARCH_ERROR)
    {
        return;
    }

    while(sacarDeCola(txt, &car, sizeof(int)) != COLA_VACIA)
    {
        fprintf(arch, "%c", car);
    }

    fclose(arch);
}
void normalizarArchivo(const char *nomArch, tCola *txt)
{
    FILE *arch;
    if(abrirArchivo(&arch, nomArch, "rt") == ARCH_ERROR)
    {
        return;
    }
    normalizarArchivoProc(arch, txt);
    fclose(arch);
}
void normalizarArchivoProc(FILE* arch, tCola *txt)
{

    int car;

    while((car = fgetc(arch)) != EOF && !esCarValido(car));

    while(car != EOF)
    {

        if(esCarValido(car))
        {
            //es una palabra
            if(isalpha(car))
            {
                car = toupper(car);
                insertarEnCola(txt, &car, sizeof(int));
                car = fgetc(arch);

                //toma una oracion completa
                while(car != EOF && car != '.')
                {
                    while(car != EOF && (isalpha(car) || car == '\n'))
                    {
                        car = tolower(car);
                        insertarEnCola(txt, &car, sizeof(int));
                        car = fgetc(arch);
                    }
                    if(car == ',')
                    {
                        insertarEnCola(txt, &car, sizeof(int));
                        car = ' ';
                    }
                    if(car == ' ')
                    {
                        //insertarEnCola(&txt, &car, sizeof(char));
                        //car = ' ';
                        insertarEnCola(txt, &car, sizeof(int));
                    }
                    while(car != EOF && !esCarValido(car))
                    {
                        car = fgetc(arch);
                    }
                }
                if(car == '.')
                {
                    insertarEnCola(txt, &car, sizeof(int));
                    car = ' ';
                    insertarEnCola(txt, &car, sizeof(int));

                    while((car = fgetc(arch)) != EOF && !esCarValido(car));
                }
            }
            //es otra cosa
            else
            {
                insertarEnCola(txt, &car, sizeof(int));
                while((car = fgetc(arch)) != EOF && esCarValido(car))
                {
                    insertarEnCola(txt, &car, sizeof(int));
                }
            }
        }
    }
    car = '\0';
    insertarEnCola(txt, &car, sizeof(int));
    //vaciarPila(&txt);

}
int esCarValido(int car)
{
    return  isalpha(car) || isdigit(car) ||
            car == '.' || car == ',' ||
            car == '¿' || car == '!' ||
            car == '¡' || car == ';' ||
            car == '\n' ||
            car == '?';
}

