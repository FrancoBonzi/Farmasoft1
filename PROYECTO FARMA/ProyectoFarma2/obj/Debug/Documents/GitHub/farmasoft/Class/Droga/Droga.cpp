#include "Droga.h"
#include <cstring>

int Droga::getId() const { return id;}
const char *Droga::getNombre() const { return nombre;}

void Droga::setId(const int id) { this->id = id; }
void Droga::setNombre(const char *nombre) { strcpy(this->nombre, nombre); }

vector<vector<string> > Droga::getTabla() {
    vector<vector<string> > final;
    final.push_back({"ID", "NOMBRE"});
    FILE *p = fopen("drogas.dat", "rb");
    if (p == nullptr) return final;
    int cantidadRegistros = this->contarRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        vector<string> aux;
        Droga droga = Droga();
        fseek(p, sizeof droga * i, 0);
        fread(&droga, sizeof(droga), 1, p);

        aux.push_back(to_string(droga.getId()));
        aux.push_back(droga.getNombre());
        final.push_back(aux);
    }
    fclose(p);
    return final;
}

string Droga::getTitulo() {
    return "Drogas";
}

void Droga::verFicha (int id) {
    return;
}

string Droga::getNombreArchivo() {
    return "drogas.dat";
}

void Droga::crearOrEditar() {
    system("cls");
    cout << "Ingrese el nombre" << endl;
    cin >> nombre;
    ClaseImprimiblePlantilla::crearOrEditar();
    this->listar(true);
}
