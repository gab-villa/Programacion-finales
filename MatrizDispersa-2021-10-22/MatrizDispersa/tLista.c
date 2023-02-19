#include "tLista.h"
#define minimo( X , Y )     ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )

void crearLista(tLista *p){
    *p = NULL;
}
int listaVacia(const tLista *p){
    return *p == NULL;
}
int listaLlena(const tLista *p, unsigned cantBytes){
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}
void vaciarLista(tLista *p){
    while(*p){
        tNodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

void recorrerListaConCeros(tLista *p, int fin,
                        void (*ponerCeros)(const void *, int*, int),
                        void (*ponerRestante)(int *, int))
{
    int ini = 0;
    tNodo *mos = *p;
    while(mos)
    {
        ponerCeros(mos->info, &ini, fin);
        mos = mos->sig;
    }
    if(ini > 0)
    {
        ponerRestante(&ini, fin);
    }
}
void recorrerLista(tLista *p, void (*mostrar)(const void *info))
{
    tNodo *mos = *p;
    while(mos)
    {
        mostrar(mos->info);
        mos = mos->sig;
    }
}
int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes){
    tNodo *nue;
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
    (nue->info = malloc(cantBytes)) == NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}
int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes){
    tNodo *aux = *p;

    if(aux == NULL)
        return 0;
    *p = aux->sig;
    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}
int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes){
    if(*p == NULL)
        return 0;
    memcpy(d, (*p)->info,minimo(cantBytes, (*p)->tamInfo));
    return 1;
}
int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    while(*p)
    {
        p = &(*p)->sig;
    }
    *p = nue;

    return 1;
}
int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes){
    if(*p == NULL)
        return 0;
    while((*p)->sig)
        p = &(*p)->sig;
    memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
    free((*p)->info);
    free(*p);
    *p = NULL;
    return 1;
}

int verUltimoLista(const tLista *p, void *d, unsigned cantBytes){
    if(*p == NULL)
        return 0;
    while((*p)->sig)
        p = &(*p)->sig;
    memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
    return 1;
}
int ponerEnOrdenAcum(tLista *p, const void *d, unsigned cantBytes,
                     int (*comparar)(const void *, const void *),
                     int (*acumular)(void **, unsigned *, const void *, unsigned))
{
    tNodo* nue;
    //tNodo* aux = *p; probar cuando todo este ok
    while(*p && comparar((*p)->info, d) < 0)
    {
        p = &(*p)->sig;
    }
    if(*p && comparar((*p)->info, d) == 0)
    {
        if(acumular)
        {
            if(!acumular(&(*p)->info, &(*p)->tamInfo, d, cantBytes))
            {
                return SIN_MEM;
            }
        }
        return CLA_DUP;
    }
    nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return SIN_MEM;
    }
    nue->info = malloc(cantBytes);
    if(nue->info == NULL)
    {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return OK;
}
int buscarPorClaveEnListaOrd(const tLista *ls, void *cla, unsigned tam,
                    int (*comp)(const void *, const void *),
                    int (*act)(void **, unsigned *, const void *, unsigned))
{
    while(*ls && comp((*ls)->info, cla) < 0)
    {
        ls = &(*ls)->sig;
    }
    if(*ls && comp((*ls)->info, cla) == 0)
    {
        if(act)
        {
            if(!act(&cla, &tam, (*ls)->info, (*ls)->tamInfo))
            {
                return ERROR_ACT;
            }
        }
        return FOUND;
    }
    return NOT_FOUND;
}
