#ifndef ARBOLB_H
#define ARBOLB_H


//#include "NodoArbolB.h"
#include <NodoArbolB.h>
#include <Silabo.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <QString>
using std::ofstream;
using std::ios;
using std::string;
using std::ios;
using std::cout;

template<typename tipo>
class ArbolB {
    friend class MainWindow;
    friend class Arbol;

private:
    NodoArbolB<tipo>* root;
    const int t=5;
    int cant=0;
    void split(NodoArbolB<tipo>* x, int i, NodoArbolB<tipo>* y) {
        NodoArbolB<tipo>* z = new NodoArbolB<tipo>(t);
        z->setLeaf(y->isLeaf());
        z->setN(t - 1);

        for (int j = 0; j < t - 1; j++) {
            z->setKey(j, y->getKey(j + t));
        }

        if (!y->isLeaf()) {
            for (int k = 0; k < t; k++) {
                z->setChild(k, y->getChild(k + t));
            }
        }

        y->setN(t - 1);

        for (int j = x->getN(); j > i; j--) {
            x->setChild(j + 1, x->getChild(j));
        }

        x->setChild(i + 1, z);

        for (int j = x->getN() - 1; j >= i; j--) {
            x->setKey(j + 1, x->getKey(j));
        }

        x->setKey(i, y->getKey(t - 1));
        x->setN(x->getN() + 1);
    }



    void nonFullInsert(NodoArbolB<tipo>* x, const tipo& key) {
        int i = x->getN() - 1;

        if (x->isLeaf()) {
            while (i >= 0 && key.toNum() < x->getKey(i).toNum()) { // Modificación aquí
                x->setKey(i + 1, x->getKey(i));
                i--;
            }
            x->setKey(i + 1, key);
            x->setN(x->getN() + 1);
        } else {
            int j = 0;
            while (j < x->getN() && key.toNum() > x->getKey(j).toNum()) { // Modificación aquí
                j++;
            }
            if (x->getChild(j)->getN() == 2 * t - 1) {
                split(x, j, x->getChild(j));
                if (key.toNum() > x->getKey(j).toNum()) { // Modificación aquí
                    j++;
                }
            }
            nonFullInsert(x->getChild(j), key);
        }
    }


    NodoArbolB<tipo>* search(NodoArbolB<tipo>* current, const tipo& key) {
        int i = 0;
        while (i < current->getN() && key > current->getKey(i)) {
            i++;
        }

        if (i < current->getN() && key == current->getKey(i)) {
            return current;
        }

        if (current->isLeaf()) {
            return nullptr;
        } else {
            return search(current->getChild(i), key);
        }
    }

    std::string print(NodoArbolB<tipo>* n) {
        std::string data = ""; // Initialize an empty string to store data
        if (n != nullptr) {
            data += n->imprimir(); // Add data from current node (assuming it returns a string)
            if (!n->isLeaf()) {
                data += "\n"; // Add newline for non-leaf nodes
                for (int j = 0; j <= n->getN(); j++) {
                    data += print(n->getChild(j)); // Recursively print children and append data
                }
            }
        }
        return data; // Return the accumulated string containing the tree data
    }


public:

    ArbolB(int t) : t(t) {
        root = new NodoArbolB<tipo>(t);
    }

    ~ArbolB() {
        delete root;
    }

    void insertar(const tipo& key) {
        NodoArbolB<tipo>* r = root;
        if (r->getN() == 2 * t - 1) {
            NodoArbolB<tipo>* s = new NodoArbolB<tipo>(t);
            root = s;
            s->setLeaf(false);
            s->setN(0);
            s->setChild(0, r);
            split(s, 0, r);
            nonFullInsert(s, key);
        } else {
            nonFullInsert(r, key);
        }
    }

    NodoArbolB<tipo>* buscarNodoPorClave(const tipo& num) {
        return search(root, num);
    }

    void mostrarArbol() {
        print(root);
    }
    void extraerArbol() {
        std::ifstream file("silaboArbolB.xls");
        if (file.is_open()) {
            std::cout << "[extraer] Archivo abierto correctamente.\n";
            std::string line;
            std::getline(file, line); // Ignorar encabezado
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string field;
                std::vector<std::string> fields;

                std::cout << "~~~~~~LEYENDO~~~~~~~~\n\n";
                while (std::getline(ss, field, '\t')) {
                    fields.push_back(field);
                }

                if (fields.size() == 9) { //9 datos/campos
                    std::string facultad = fields[0];
                    std::string carrera = fields[1];
                    std::string nombre = fields[2];
                    std::string codigoClase = fields[3];
                    std::string ruta = fields[4];
                    std::string estado = fields[5];
                    std::string observacion = fields[6];
                    int id = std::stoi(fields[7]);
                    int numRevisiones = std::stoi(fields[8]);


//                    std::cout << "Facultad: " << facultad << ", Carrera: " << carrera << ", Nombre: " << nombre
//                                              << ", CodigoClase: " << codigoClase << ", Ruta: " << ruta << ", Estado: " << estado
//                                              << ", Observacion: " << observacion
//                                              << ", ID: " << id << ", NumRevisiones: " << numRevisiones << std::endl;
//                    std::cout << "-----------------------\n";

                    Silabo* nuevoSilabo = new Silabo(facultad, carrera, nombre, codigoClase, QString::fromStdString(ruta), estado, observacion, id, numRevisiones);
                    this->insertar(*nuevoSilabo);
                    cant++;
                } else {
                    std::cerr << "Error de formato en la línea: " << line << std::endl;
                }
            }
            file.close();
            std::cout << "Datos del archivo TSV cargados en el árbol.\n";
        } else {
            std::cerr << "Error al abrir el archivo.\n";
        }
    }
    void guardarExcel(std::ofstream &file, NodoArbolB<Silabo>* nodo) {
        if (nodo == nullptr) {
            return;
        }
        // Recorrer cada clave en el nodo actual y guardarla en el archivo
        for (int i = 0; i < nodo->getN(); i++) {
            const Silabo& silabo = nodo->getKey(i);
            file
                << silabo.getFacultad() << "\t"
                << silabo.getCarreras() << "\t"
                << silabo.getNombre() << "\t"
                << silabo.getCodigoClase() << "\t"
                << silabo.getRuta().toStdString() << "\t"
                << silabo.getEstado() << "\t"
                << silabo.getObservacion() << "\t"
                << silabo.getId() << "\t"
                << silabo.getNumRevisiones() << "\t"<< "\n";
        }

        for (int i = 0; i <= nodo->getN(); i++) {
            guardarExcel(file, nodo->getChild(i));
        }
    }



    void guardar() {
        std::ifstream file;
        file.open("silaboArbolB.xls");
        file.close();
        std::ofstream File("silaboArbolB.xls");
        if (File.is_open()) {
            File << "Facultad\tCarrera\tIngresado Por\tCodigo de Clase\tRuta\tEstado\tObservacion\tID\tNumero de Revisiones\n";
            guardarExcel(File,root);
            File.close();
            std::cout << "XLS exportado.\n";
        } else {
            std::cerr << "Error en el archivo.\n";
        }

    }


};



#endif // ARBOLB_H
