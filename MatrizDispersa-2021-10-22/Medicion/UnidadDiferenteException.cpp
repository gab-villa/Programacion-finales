#include "UnidadDiferenteException.h"

const char* UnidadDiferenteException::what() const throw()
{
    return "No se puede restar mediciones de distinta unidad de medida";
}
