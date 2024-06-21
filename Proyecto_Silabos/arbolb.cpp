#include "arbolB.h"

// Constructor del árbol B
arbolB::arbolB(int t) {
    raiz = NULL;
    this->t = t;
    nextId = 1;  // Inicializar el próximo ID a 1
}

// Recorrer y mostrar todas las llaves del árbol
void arbolB::recorrer() {
    if (raiz != NULL) raiz->recorrer();
}

// Buscar una llave en el árbol por datosClase
Silabos* arbolB::buscar(const string& datosClase) {
    return (raiz == NULL) ? NULL : raiz->buscar(datosClase);
}

// Insertar una llave en el árbol
void arbolB::insertar(Silabos& k) {
    k.setId(nextId++);  // Asignar el próximo ID disponible al Silabos

    // Si el árbol está vacío
    if (raiz == NULL) {
        // Asignar raíz
        raiz = new nodoB(true);
        raiz->llaves.push_back(k);
    } else { // Si el árbol no está vacío
        // Si la raíz está llena, el árbol crece en altura
        if (raiz->llaves.size() == 2*t-1) {
            // Crear una nueva raíz
            nodoB *s = new nodoB(false);

            // Hacer que la antigua raíz sea hija de la nueva raíz
            s->hijos.push_back(raiz);

            // Dividir la antigua raíz y mover una llave al nuevo nodo
            s->dividirHijo(0, raiz);

            // La nueva raíz tiene dos hijos, insertar la nueva llave en el hijo apropiado
            int i = 0;
            if (s->llaves[0].getDatosClase() < k.getDatosClase()) {
                i++;
            }
            s->hijos[i]->insertarNoLleno(k);

            // Cambiar la raíz
            raiz = s;
        } else {
            // Si la raíz no está llena, llamar a insertarNoLleno para la raíz
            raiz->insertarNoLleno(k);
        }
    }
}
