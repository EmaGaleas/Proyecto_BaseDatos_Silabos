#ifndef ARBOLB_H
#define ARBOLB_H

#include "nodoB.h"

class arbolB {
public:
    nodoB *raiz;
    int t;  // Grado mínimo
    int nextId;  // Siguiente ID disponible para los Silabos

    // Constructor
    arbolB(int t);

    // Recorrer y mostrar todas las llaves del árbol
    void recorrer();

    // Buscar una llave en el árbol por datosClase
    Silabos* buscar(const string& datosClase);

    // Insertar una llave en el árbol
    void insertar(Silabos& k);
};

#endif // ARBOLB_H
