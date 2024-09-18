#include "Efecto.h"
#include <string.h>

int Efecto::getId() const {
    return id;
}

const char *Efecto::getNombre() const {
    return nombre;
}

void Efecto::setId(int id) {
    this->id = id;
}

void Efecto::setNombre(const char *nombre) {
    strcpy(this->nombre, nombre);
}


void Efecto::verFicha (int id) {
    return;
}

vector<vector<string> > Efecto::getTabla() {
    vector<vector<string> > final;
    final.push_back({"ID", "NOMBRE"});
    FILE *p = fopen("efectos.dat", "rb");
    if (p == nullptr) return final;
    int cantidadRegistros = this->contarRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        vector<string> aux;
        Efecto efecto = Efecto();
        fseek(p, sizeof efecto * i, 0);
        fread(&efecto, sizeof(efecto), 1, p);
        aux.push_back(to_string(efecto.getId()));
        aux.push_back(efecto.getNombre());
        final.push_back(aux);
    }
    fclose(p);
    return final;
}

string Efecto::getNombreArchivo() {
    return "efectos.dat";
}

string Efecto::getTitulo() {
    return "Efectos";
}

void Efecto::crearOrEditar() {
    system("cls");
    cout << "Ingrese el nombre: ";
    cin >> this->nombre;
    ClaseImprimiblePlantilla::crearOrEditar();
    this->listar(true);

}
