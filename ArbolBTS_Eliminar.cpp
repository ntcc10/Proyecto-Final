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

    //Eliminar un Node del arbol de manera recursiva
    NodoBST* eliminarPorNombre(NodoBST* nodo, const std::string& nombreContacto) {
        if (nodo == nullptr) {
            // El contacto no se encontró, no se realiza ninguna acción
            return nullptr;
        }

        // Comparar el nombre del contacto en el nodo actual con el nombre que se busca
        int comparacion = nombreContacto.compare(nodo->contacto.nombre);

        // Buscar en el subárbol izquierdo o derecho según la comparación
        if (comparacion < 0) {
            nodo->izquierda = eliminarPorNombre(nodo->izquierda, nombreContacto);
        } else if (comparacion > 0) {
            nodo->derecha = eliminarPorNombre(nodo->derecha, nombreContacto);
        } else {
            // Se encontró el contacto, realizar la eliminación
            if (nodo->listaEnlazada != nullptr) {
                // Eliminar la lista enlazada si existe
                borrarListaEnlazada(nodo->listaEnlazada);
            }

            // Caso 1: Nodo sin hijos o con un solo hijo
            if (nodo->izquierda == nullptr) {
                NodoBST* temp = nodo->derecha;
                delete nodo;
                return temp;
            } else if (nodo->derecha == nullptr) {
                NodoBST* temp = nodo->izquierda;
                delete nodo;
                return temp;
            }

            // Caso 2: Nodo con dos hijos, encontrar el sucesor inmediato (mínimo en el subárbol derecho)
            NodoBST* sucesor = encontrarMinimo(nodo->derecha);

            // Copiar el contenido del sucesor al nodo actual
            nodo->contacto = sucesor->contacto;

            // Eliminar el sucesor
            nodo->derecha = eliminarPorNombre(nodo->derecha, sucesor->contacto.nombre);
        }

        return nodo;
    }

    // Método privado para encontrar el nodo con el valor mínimo en un subárbol
    NodoBST* encontrarMinimo(NodoBST* nodo) {
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    // Método privado para borrar la lista enlazada asociada a un nodo
    void borrarListaEnlazada(NodoLista* lista) {
        while (lista != nullptr) {
            NodoLista* temporal = lista;
            lista = lista->siguiente;
            delete temporal;
        }
    }

public:
    // Constructor
    ArbolBTS() : raiz(nullptr) {}

    void agregarContacto(const Contacto& nuevoContacto) {
        raiz = insertar(raiz, nuevoContacto);
    }

    void eliminarContacto(const std::string& nombreContacto) {
        raiz = eliminarPorNombre(raiz, nombreContacto);
    }

};
