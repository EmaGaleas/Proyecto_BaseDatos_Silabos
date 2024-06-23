#ifndef NODOB_H
#define NODOB_H

#include <vector>
#include <iostream>
#include "Silabos.h"

using namespace std;

class nodoB {
public:
    vector<Silabos> llaves;  // Array de llaves
    vector<nodoB*> hijos;  // Array de punteros a hijos
    bool hoja;  // Es verdadero si el nodo es una hoja. De lo contrario, falso

    // Constructor
    nodoB(bool hoja);

    // Insertar una llave en un nodo no lleno
    void insertarNoLleno(Silabos k);

    // Dividir un hijo en dos nodos
    void dividirHijo(int i, nodoB *y);

    // Recorrer y mostrar todas las llaves del nodo
    void recorrer();

    // Buscar una llave en el nodo por datosClase
    Silabos* buscar(const string& datosClase);

    // Obtener todos los Silabos en el nodo
    void obtenerTodos(vector<Silabos>& resultado);
};

#endif // NODOB_H
