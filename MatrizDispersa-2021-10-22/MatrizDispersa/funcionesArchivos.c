#include "funcionesArchivos.h"

int abrirArchivo(FILE** arch, const char* nomArch, const char* modoAp)
{
    *arch = fopen(nomArch, modoAp);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s en modo %s",nomArch,
                                                                    modoAp);
        return ERROR;
    }
    return TODO_OK;
}
int sacarFilaDeArchivo(const char *nomArch)
{
    int tamFila, tamCol;
    FILE *archMatriz;
    char reg[TAM_REG];
    if(abrirArchivo(&archMatriz, nomArch, "rt" ) == ERROR)
    {
        return -1;
    }
    if(fgets(reg, TAM_REG, archMatriz))
    {
        parsearTam(reg, &tamFila, &tamCol);
    }
    fclose(archMatriz);
    return tamFila;
}
int verificarMatrizRala(const char *nomArch)
{
    int tamFila, tamCol;
    tFila fila;
    FILE *archMatriz;
    char reg[TAM_REG];
    if(abrirArchivo(&archMatriz, nomArch, "rt" ) == ERROR)
    {
        return ERROR;
    }
    if(fgets(reg, TAM_REG, archMatriz))
    {
        parsearTam(reg, &tamFila, &tamCol);
        //printf("%d %d", tamFila, tamCol);
        if(tamFila <= 0 || tamFila >= 1000 ||
            tamCol <= 0 || tamCol >= 1000)
        {
            return 0;
        }
        while(fgets(reg, TAM_REG, archMatriz))
        {
            parsearReg(reg, &fila);
            //printf(" %d %d %d\n", fila.fila, fila.c.col, fila.c.val);
            if(!verificarCord(&fila, tamFila, tamCol))
            {

                return 0;
            }
        }
    }

    fclose(archMatriz);
    return 1;
}

void parsearTam(char *reg, int *tamFila, int *tamCol)
{
    char *aux = reg;

    aux = strchr(reg, '\n');
    --aux;
    *aux = VACIO;

    aux = strrchr(reg, '[');
    sscanf(aux+1, "%d", tamCol);
    --aux;
    *aux = VACIO;

    sscanf(reg+1, "%d", &(*tamFila));
}
void parsearReg(char *reg, tFila *f)
{
    char *aux = reg;
    aux = strchr(reg, '\n');
    *aux = VACIO;

    aux = strrchr(reg, ']');
    sscanf(aux+1, "%d", &f->c.val);
    *aux = VACIO;

    aux = strrchr(reg, '[');
    sscanf(aux+1, "%d", &f->c.col);
    --aux;
    *aux = VACIO;

    sscanf(reg+1, "%d", &f->fila);
}

int verificarCord(const tFila *f, int tamFila, int tamCol)
{
    if(f->fila < 0 || f->fila >= tamFila ||
        f->c.col < 0 || f->c.col >= tamCol)
    {
        return 0;
    }
    return 1;
}
