#include "Presentacion.h"

#include <string.h>

int Presentacion::getId() const {
    return id;
}

const char *Presentacion::getNombre() const {
    return nombre;
}

void Presentacion::setId(int id) {
    this->id = id;
}

void Presentacion::setNombre(const char *nombre) {
    strcpy(this->nombre, nombre);
}

vector<vector<string> > Presentacion::getTabla() {
    vector<vector<string> > final;
    final.push_back({"ID", "NOMBRE"});
    FILE *p = fopen("presentaciones.dat", "rb");
    if (p == nullptr) return final;
    int cantidadRegistros = this->contarRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        vector<string> aux;
        Presentacion presentacion = Presentacion();
        fseek(p, sizeof presentacion * i, 0);
        fread(&presentacion, sizeof(presentacion), 1, p);
        aux.push_back(to_string(presentacion.getId()));
        aux.push_back(presentacion.getNombre());
        final.push_back(aux);
    }
    fclose(p);
    return final;
}

string Presentacion::getNombreArchivo() {
    return "presentaciones.dat";
}

string Presentacion::getTitulo() {
    return "Presentaciones";
}

void Presentacion::verFicha(int id) {
    return;
}

void Presentacion::crearOrEditar() {
    system("cls");
    cout << "Ingrese el nombre: ";
    cin >> this->nombre;
    ClaseImprimiblePlantilla::crearOrEditar();
    this->listar(true);
}
