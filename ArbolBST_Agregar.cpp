#include <iostream>

// estrcutura contacto
struct Contacto {
    std::string nombre;
    std::string telefono;
    std::string redesSociales;
    std::string icono;
    std::string direccion;
};

// Nodo para manejar los contactos que tienen el mismo nombre
struct NodoLista {
    Contacto contacto;
    NodoLista* siguiente;

    NodoLista(const Contacto& c){
      contacto = c;
      siguiente = nullptr;
    }

};

struct NodoBST {
    Contacto contacto;
    NodoLista* listaEnlazada; // Para manejar contactos con el mismo nombre
    NodoBST* izquierda;
    NodoBST* derecha;

    NodoBST(const Contacto& c){
      contacto = c;
      listaEnlazada = nullptr;
      izquierda = nullptr;
      derecha = nullptr;
    }

};

class ArbolBTS {
private:
    NodoBST* raiz;

    //Insertar un contacto en el árbol de manera recursiva
    NodoBST* insertar(NodoBST* nodo, const Contacto& nuevoContacto) {
        if (nodo == nullptr) {
            // Crear un nuevo nodo si el nodo actual es nulo
            return new NodoBST(nuevoContacto);
        }

        //Clasificará los contactos alfabéticamente en función de sus nombres.
        int comparacion = nuevoContacto.nombre.compare(nodo->contacto.nombre);

        // Insertar en el subárbol izquierdo o derecho según la comparación
        if (comparacion < 0) {
            nodo->izquierda = insertar(nodo->izquierda, nuevoContacto);
        } else if (comparacion > 0) {
            nodo->derecha = insertar(nodo->derecha, nuevoContacto);
        } else {
            // En caso de que los nombres sean iguales, añadir a la lista enlazada
            NodoLista* nuevoNodoLista = new NodoLista(nuevoContacto);
            nuevoNodoLista->siguiente = nodo->listaEnlazada;
            nodo->listaEnlazada = nuevoNodoLista;
        }

        return nodo;
    }

public:
    // Constructor
    ArbolBTS() : raiz(nullptr) {}

    void agregarContacto(const Contacto& nuevoContacto) {
        raiz = insertar(raiz, nuevoContacto);
    }

};

