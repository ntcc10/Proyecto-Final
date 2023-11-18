#include <iostream>
#include <vector>
using namespace std;

// Definición de la estructura de un contacto
struct Contacto {
    std::string nombre;
    std::string telefono;
    std::string redesSociales;
    std::string icono;
    std::string direccion;
};

class LibretaContactos {

private:
    // Lista de contactos en la libreta
    std::vector<Contacto> contactos;

    
public:

    // Agrega un nuevo contacto a la libreta
    void AgregarContacto(Contacto c) {
        contactos.push_back(c);
        cout << "Contacto agregado exitosamente." << endl;
    }


};

int main() {
    LibretaContactos libreta;

    // Crear un nuevo contacto
    Contacto nuevoContacto;
    nuevoContacto.nombre = "Isabela";
    nuevoContacto.telefono = "123456789";
    nuevoContacto.redesSociales = "@isabela";
    nuevoContacto.icono = "isabela.png";
    nuevoContacto.direccion = "123 calle 170";

    // Agregar el nuevo contacto a la libreta
    libreta.AgregarContacto(nuevoContacto);

    return 0;
}


