#include "Marca.h"

#include <string.h>

int Marca::getId() const {
    return id;
}

const char *Marca::getNombre() const {
    return nombre;
}

void Marca::setId(int id) {
    this->id = id;
}

void Marca::setNombre(const char *nombre) {
    strcpy(this->nombre, nombre);
}

vector<vector<string> > Marca::getTabla() {
    vector<vector<string> > final;
    final.push_back({"ID", "NOMBRE"});
    FILE *p = fopen("marcas.dat", "rb");
    if (p == nullptr) return final;
    int cantidadRegistros = this->contarRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        vector<string> aux;
        Marca marca = Marca();
        fseek(p, sizeof marca * i, 0);
        fread(&marca, sizeof(marca), 1, p);
        aux.push_back(to_string(marca.getId()));
        aux.push_back(marca.getNombre());
        final.push_back(aux);
    }
    fclose(p);
    return final;
}

void Marca::verFicha (int id) {
    return;
}

string Marca::getNombreArchivo() {
    return "marcas.dat";
}

string Marca::getTitulo() {
    return "Marcas";
}

void Marca::crearOrEditar() {
    system("cls");
    cout << "Ingrese el nombre: ";
    cin >> this->nombre;
    ClaseImprimiblePlantilla::crearOrEditar();
    this->listar(true);
}

bool Marca::YaExisteId(int id) {
    Marca marca;
    FILE *p = fopen("marcas.dat", "rb");
    if (p == NULL) return false;
    while (fread(&marca, sizeof(marca), 1, p)) {
        if (marca.getId() == id) {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
