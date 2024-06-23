#include "nodoB.h"

// Constructor del nodo B
nodoB::nodoB(bool hoja) {
    this->hoja = hoja;
}

// Recorrer y mostrar todas las llaves del nodo
void nodoB::recorrer() {
    int i;
    for (i = 0; i < llaves.size(); i++) {
        if (!hoja) {
            hijos[i]->recorrer();
        }
        llaves[i].imprimir();
    }

    if (!hoja) {
        hijos[i]->recorrer();
    }
}

// Buscar una llave en el nodo por datosClase
Silabos* nodoB::buscar(const string& datosClase) {
    int i = 0;
    while (i < llaves.size() && datosClase > llaves[i].getDatosClase()) {
        i++;
    }

    if (i < llaves.size() && llaves[i].getDatosClase() == datosClase) {
        return &llaves[i];
    }

    if (hoja) {
        return nullptr;
    }

    return hijos[i]->buscar(datosClase);
}

// Insertar una llave en un nodo no lleno
void nodoB::insertarNoLleno(Silabos k) {
    int i = llaves.size() - 1;

    if (hoja) {
        llaves.push_back(k);
        while (i >= 0 && llaves[i].getDatosClase() > k.getDatosClase()) {
            llaves[i+1] = llaves[i];
            i--;
        }
        llaves[i+1] = k;
    } else {
        while (i >= 0 && llaves[i].getDatosClase() > k.getDatosClase()) {
            i--;
        }
        i++;
        if (hijos[i]->llaves.size() == 2 * 5 - 1) {  // 2*t - 1, donde t=5 para Árbol B de orden 5
            dividirHijo(i, hijos[i]);
            if (llaves[i].getDatosClase() < k.getDatosClase()) {
                i++;
            }
        }
        hijos[i]->insertarNoLleno(k);
    }
}

// Dividir un hijo en dos nodos
void nodoB::dividirHijo(int i, nodoB *y) {
    nodoB *z = new nodoB(y->hoja);
    z->llaves.resize(5 - 1);  // t - 1, donde t=5 para Árbol B de orden 5

    for (int j = 0; j < 5 - 1; j++) {
        z->llaves[j] = y->llaves[j + 5];
    }

    if (!y->hoja) {
        z->hijos.resize(5);
        for (int j = 0; j < 5; j++) {
            z->hijos[j] = y->hijos[j + 5];
        }
    }

    y->llaves.resize(5 - 1);

    hijos.insert(hijos.begin() + i + 1, z);

    llaves.insert(llaves.begin() + i, y->llaves[5 - 1]);
}

// Obtener todos los Silabos en el nodo
void nodoB::obtenerTodos(vector<Silabos>& resultado) {
    int i;
    for (i = 0; i < llaves.size(); i++) {
        if (!hoja) {
            hijos[i]->obtenerTodos(resultado);
        }
        resultado.push_back(llaves[i]);
    }

    if (!hoja) {
        hijos[i]->obtenerTodos(resultado);
    }
}
