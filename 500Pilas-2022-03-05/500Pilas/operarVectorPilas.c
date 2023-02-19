#include "operarVectorPilas.h"

int abrirArchivo(FILE **arch, const char *nomArch, const char *ap)
{
    *arch = fopen(nomArch, ap);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se ha podido abrir el archivo %s en modo %s",
                        nomArch, ap);
        return ARCH_ERROR;
    }
    return ARCH_OK;
}
int crearVectorPilasConArch(const char *nomArchDatos, tVecPila *vp)
{
    tPar par;
    char reg[TAM_REG];
    FILE *archDatos;
    if(abrirArchivo(&archDatos, nomArchDatos, "rt") == ARCH_ERROR)
    {
        return ARCH_ERROR;
    }
    if(fgets(reg, TAM_REG, archDatos))
    {
        if(!crearVectorPilas(vp, parsearNumPilas(reg)))
        {
            //printf("%d",vp->n);
            return ERROR_N;
        }
    }

    while(fgets(reg, TAM_REG, archDatos))
    {
        parsearPares(reg, &par);
        //printf("(%d,%d)", par.i, par.j);
        if(par.i > 0)
        {
            if(par.j == 0)
            {
                vaciarPilaDeVec(vp, par.i);
            }
            else
            {
                if(!ponerEnVecPila(vp, par.i, par.j))
                {
                    return ERROR_N;
                }
            }
        }
        else if(par.i < 0)
        {

            //cambiarle el signo antes de enviarlo
            par.i *= -1;
            eliminarDeVecPila(vp, par.i);
            //sacarDeVecPila(vp,  par.i);
        }
        else
        {
            fclose(archDatos);
            return FIN_ANORMAL;
        }
    }
    fclose(archDatos);
    return ARCH_OK;
}
void exportarPilas(const char *nomArchExp, tVecPila *vp)
{
    int num, pos;
    FILE *archExp;
    if(!abrirArchivo(&archExp, nomArchExp, "wt"))
    {
        return;
    }
    for(pos = 1;pos <= vp->n;++pos)
    {
        // posicion = indice + 1
        while(sacarDeVecPila(vp, &num, pos))
        {
            fprintf(archExp, "(%d,%d)\n", pos, num);
        }
    }
    fclose(archExp);
}
void exportarPilasEnVariosArchivos(tVecPila *vp)
{
    char nomArchPila[50];
    int num, pos;
    FILE *archPila;

    system("if not exist archivosPilas mkdir archivosPilas");

    for(pos = 1;pos <= vp->n;++pos)
    {
        // posicion = indice + 1
        if(!pilaDeVecVacia(vp, pos))
        {
            cambiarNombrePilaPos(nomArchPila, pos);
            if(!abrirArchivo(&archPila, nomArchPila, "wt"))
            {
                return;
            }
            while(sacarDeVecPila(vp, &num, pos))
            {
                actArchPila(archPila, num, pos);
            }
            fclose(archPila);
        }
    }
}
void actArchPila(FILE *archPila, int num, int pos)
{
    fprintf(archPila, "(%d,%d)\n", pos, num);
}
void cambiarNombrePilaPos(char *nomArchPila, int pos)
{
    sprintf(nomArchPila, "archivosPilas/pila%d.txt", pos);
}
int parsearNumPilas(char *reg)
{
    int num = 0;
    char *aux;
    aux = strchr(reg, '\n');
    *aux = '\0';
    sscanf(reg, "%d", &num);
    return num;
}
void parsearPares(char *reg, tPar *par)
{
    char *aux = reg;
    aux = strchr(reg, '\n');
    *aux = '\0';
    aux = strrchr(reg, ',');
    sscanf(aux+1, "%d", &par->j);
    *aux = '\0';

    sscanf(reg+1, "%d", &par->i);
}
