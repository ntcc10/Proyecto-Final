// En caso de que dos contactos tengan el mismo nombre, se deben manejar utilizando listas enlazadas.
struct NodoLista {

    Contacto contacto;
    NodoLista* siguiente;

    NodoLista(const Contacto& c){
      contacto = c;
      siguinete = nullptr;
    }

};


// Nodo para el árbol de búsqueda binaria (BST)
struct NodoBST {

    Contacto contacto;
    NodoLista* listaEnlazada; // Dos Contactos tengan el mismo nombre
    NodoBST* izquierda;
    NodoBST* derecha;

    NodoBST(const Contacto& c){
        contacto = c;
        listaEnlazada = nullptr;
        izquierda = nullptr;
        derecha = nullptr;
    } 
};

class ArbolBTS{
  private:
    NodoBST raiz;

  public:
    ArbolBTS(){
      raiz = nullptr;
    }
};
