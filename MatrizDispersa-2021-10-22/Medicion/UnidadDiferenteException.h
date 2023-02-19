#ifndef UNIDADDIFERENTEEXCEPTION_H_INCLUDED
#define UNIDADDIFERENTEEXCEPTION_H_INCLUDED

#include <exception>

using namespace std;

class UnidadDiferenteException : public exception
{
    public:
        const char* what() const throw();
};

#endif // UNIDADDIFERENTEEXCEPTION_H_INCLUDED
