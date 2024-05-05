#ifndef NODO_ARBOL_B_H
#define NODO_ARBOL_B_H

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::string;

template<typename tipo> class ArbolB;
template<typename tipo>
class NodoArbolB {
    friend class MainWindow;
    friend class ArbolB<tipo>;
private:
    int n; // Número de claves almacenadas en el nodo
    bool leaf; // Si el nodo es hoja (true) o interno (false)
    tipo *key; // Almacena las claves en el nodo
    NodoArbolB<tipo> **child; // Arreglo de punteros a los hijos

public:
    // Constructor
    NodoArbolB(int t) {
        n = 0;
        leaf = true;
        key = new tipo[2 * t - 1]; // Tamaño máximo de claves en el nodo
        child = new NodoArbolB<tipo>*[2 * t]; // Tamaño máximo de hijos del nodo
    }

    // Destructor
    ~NodoArbolB() {
        delete[] key;
        for (int i = 0; i < 2 * n + 1; i++) {
            delete child[i];
        }
        delete[] child;
    }

    // Método para imprimir el contenido del nodo
    std::string imprimir() const {
        std::string output = "[";
        for (int i = 0; i < n; i++) {
            // Convert key to string (assuming key is a type that can be converted to string)
            std::stringstream ss;
            ss << key[i]; // Assuming key[i] is a Silabo object
            output += ss.str();

            if (i < n - 1) output += " | ";
        }
        output += "]";
        return output;
    }


    // Método para encontrar una clave en el nodo
    int find(const tipo& k) const {
        for (int i = 0; i < n; i++) {
            if (key[i] == k) {
                return i;
            }
        }
        return -1; // Devuelve -1 si la clave no se encuentra
    }

    // Métodos de acceso y modificación
    tipo getKey(int index) const { return key[index]; }
    void setKey(int index, const tipo& value) { key[index] = value; }
    NodoArbolB<tipo>* getChild(int index) const { return child[index]; }
    void setChild(int index, NodoArbolB<tipo>* node) { child[index] = node; }
    int getN() const { return n; }
    void setN(int value) { n = value; }
    bool isLeaf() const { return leaf; }
    void setLeaf(bool value) { leaf = value; }
};

#endif // NODO_ARBOL_B_H
