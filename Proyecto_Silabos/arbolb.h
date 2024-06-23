#ifndef ARBOLB_H
#define ARBOLB_H

#include "nodoB.h"
#include <vector>

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
    Silabos* buscar(int id);

    // Insertar una llave en el árbol
    void insertar(Silabos& k);

    // Obtener todos los Silabos en el árbol
    std::vector<Silabos> obtenerTodos();
};

#endif // ARBOLB_H
