#include "tProducto.h"

int compPorTipo(const void *v1, const void *v2)
{
    const tProd *prod1 = (const tProd*)v1;
    const tProd *prod2 = (const tProd*)v2;

    if(prod1->tipo == prod2->tipo)
    {
        return strcmp(prod1->cod, prod2->cod);
    }
    else if(prod1->tipo > prod2->tipo)
    {
        return 1;
    }
    return -1;
}
void copiarProd(void *ds, const void *info)
{
    FILE *arch = (FILE*)ds;
    //const tProd *prod = (const tProd*)info;

    fwrite(info, sizeof(tProd), 1, arch);
}
