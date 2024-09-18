#include "Medicamento.h"
#include <cstring>
#include <algorithm>
#include <conio.h>


#include "../Droga/Droga.h"
#include "../Efecto/Efecto.h"
#include "../Marca/Marca.h"
#include "../MedicamentoDrogas/MedicamentoDrogas.h"
#include "../MedicamentoEfectos/MedicamentosEfectos.h"
#include "../Presentacion/Presentacion.h"

int Medicamento::getId() const { return id; }
int Medicamento::getMarcaId() { return marcaId; }
float Medicamento::getPrecio() { return precio; }
int Medicamento::getStock() const { return stock; }
const char *Medicamento::getUnidad() const { return unidad; }
int Medicamento::getPresentacionId() const { return presentacionId; }
Fecha Medicamento::getFechaCreacion() const { return fechaCreacion; }

string Medicamento::getMarcaNombre() {
    Marca marca = Marca();
    marca = marca.getRegistro(this->getMarcaId());
    return marca.getNombre();
}

string Medicamento::getPresentacionNombre() {
    Presentacion presentacion = Presentacion();
    presentacion = presentacion.getRegistro(this->getPresentacionId());
    return presentacion.getNombre();
}

string Medicamento::getEfectosNombres() {
    MedicamentosEfectos medicamentos_efectos = MedicamentosEfectos();
    medicamentos_efectos.setMedicamentoId(this->getId());
    return medicamentos_efectos.getEfectosPorMedicamentoId();
}

string Medicamento::getDrogasNombres() {
    MedicamentoDrogas medicamentos_drogas = MedicamentoDrogas();
    medicamentos_drogas.setMedicamentoId(this->getId());
    return medicamentos_drogas.getDrogasPorMedicamentoId();
}

void Medicamento::setId(const int id) { this->id = id; }
void Medicamento::setMarcaId(int marca) { this->marcaId, marca; }
void Medicamento::setPrecio(const float precio) { this->precio = precio; }
void Medicamento::setStock(const int stock) { this->stock = stock; }
void Medicamento::setFechaCreacion(const Fecha fechaCreacion) { this->fechaCreacion = fechaCreacion; }
void Medicamento::setPresentacionId(const int presentacionId) { this->presentacionId = presentacionId; }
void Medicamento::setUnidad(const char *unidad) { strcpy(this->unidad, unidad); }

vector<vector<string> > Medicamento::getTabla() {
    vector<vector<string> > final;
    final.push_back({"ID", "MARCA", "PRECIO", "UNIDAD", "PRESENTACION", "FECHA CREACION"});
    FILE *p = fopen("medicamentos.dat", "rb");
    if (p == nullptr) return final;
    int cantidadRegistros = this->contarRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        vector<string> aux;
        Medicamento medicamento = Medicamento();
        fseek(p, sizeof medicamento * i, 0);
        fread(&medicamento, sizeof(medicamento), 1, p);

        aux.push_back(to_string(medicamento.getId()));
        aux.push_back(medicamento.getMarcaNombre());
        aux.push_back("$" + to_string(medicamento.getPrecio()));
        aux.push_back(to_string(medicamento.getStock()));
        aux.push_back(medicamento.getUnidad());
        aux.push_back(medicamento.getPresentacionNombre());
        aux.push_back(medicamento.getFechaCreacion().getFechaConcatenada());
        final.push_back(aux);
    }

    fclose(p);
    return final;
}

void Medicamento::setFechaActual() {
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    fechaCreacion.setDia(now->tm_mday);
    fechaCreacion.setMes(now->tm_mon + 1);
    fechaCreacion.setAnio(now->tm_year + 1900);
}

void Medicamento::verFicha(int id) {
    system("cls");
    cout << "Vista de " << this->getTitulo() << endl << endl;

    cout << "Pulse 'ENTER' para salir" << endl << endl;

    int tecla;
    Medicamento medicamento = this->getRegistro(id);
    do {
        cout << "Numero de ID: " << medicamento.getId() << endl;
        cout << "Marca: " << medicamento.getMarcaNombre() << endl;
        cout << "Precio: $" << medicamento.getPrecio() << endl;
        // cout << "Stock: " << medicamento.getStock() << endl;
        cout << "Unidad: " << medicamento.getUnidad() << endl;
        cout << "Presentacion: " << medicamento.getPresentacionNombre() << endl;
        cout << "Efectos: " << medicamento.getEfectosNombres() << endl;
        cout << "Drogas: " << medicamento.getDrogasNombres() << endl;
        cout << "Fecha de creacion: " << medicamento.getFechaCreacion().getFechaConcatenada() << endl;

        while (!_kbhit());
        tecla = _getch();
    } while (tecla != 13);
}

string Medicamento::getNombreArchivo() {
    return "medicamentos.dat";
}

string Medicamento::getTitulo() {
    return "Medicamentos";
}

void Medicamento::eliminarDrogas () {
    MedicamentoDrogas medicamentos_drogas = MedicamentoDrogas();
    medicamentos_drogas.setMedicamentoId(this->getId());
    medicamentos_drogas.eliminarDrogasPorMedicamentoId();
}

void Medicamento::eliminarEfectos () {
    MedicamentosEfectos medicamentos_efectos = MedicamentosEfectos();
    medicamentos_efectos.setMedicamentoId(this->getId());
    medicamentos_efectos.eliminarEfectosPorMedicamentoId();
}

void Medicamento::eliminar(int id, string archivo) {
    this->setId(id);
    this->eliminarDrogas();
    this->eliminarEfectos();
    ClaseImprimiblePlantilla::eliminar(id);
}

void Medicamento::crearOrEditar() {
    bool esMarcaValida = false;
    while (!esMarcaValida) {
        system("cls");
        cout << "Creacion de Medicamento" << endl << endl;
        cout << "Seleccione una marca" << endl;
        Marca marca = Marca();
        cout << endl;
        marca.listar(false);
        cout << endl;
        cin >> marcaId;

        if (marca.existeId(marcaId)) {
            esMarcaValida = true;
        } else {
            system("cls");
            cout << "El ID ingresado no es valido, intentelo de nuevo." << endl;
            system("pause");
        }
    }

    float precioTemporal = 0;
    while (precioTemporal < 1) {
        system("cls");
        cout << "Creacion de Medicamento" << endl << endl;
        cout << "Ingrese el Precio" << endl;
        cin >> precioTemporal;

        if (precioTemporal < 0) {
            cout << "Debe ser un valor mayor a 0!" << endl;
            system("pause");
        }
    }
    precio = precioTemporal;

    system("cls");
    cout << "Creacion de Medicamento" << endl << endl;
    cout << "Ingrese la unidad (debe ser maximo 3 caracteres)" << endl;
    cin >> unidad;

    bool esPresentacionValida = false;
    while (!esPresentacionValida) {
        system("cls");
        cout << "Creacion de Medicamento" << endl << endl;
        cout << "Ingrese la presentacion" << endl;
        Presentacion presentacion = Presentacion();
        cout << endl;
        presentacion.listar(false);
        cout << endl;
        cin >> presentacionId;

        if (presentacion.existeId(presentacionId)) {
            esPresentacionValida = true;
        } else {
            system("cls");
            cout << "El ID ingresado no es valido, intentelo de nuevo." << endl;
            system("pause");
        }
    }

    int input = 1;
    vector<int> efectos;
    while (input != 0) {
        system("cls");
        cout << "Creacion de Medicamento" << endl << endl;
        cout << "Ingrese el/los efecto, 0 para continuar" << endl;
        Efecto efecto = Efecto();
        efecto.listar(false);
        cin >> input;

        if (input != 0) {
            if (efecto.existeId(input)) {
                auto iterador = find(efectos.begin(), efectos.end(), input);
                if (iterador == efectos.end()) {
                    efectos.push_back(input);
                }
            } else {
                system("cls");
                cout << "El ID ingresado no es valido, intentelo de nuevo." << endl;
                system("pause");
            }
        }
    }

    input = 1;
    vector<int> drogas;
    while (input != 0) {
        system("cls");
        cout << "Creacion de Medicamento" << endl << endl;
        cout << "Ingrese las drogas que contenga el medicamento, 0 para continuar" << endl;
        Droga droga = Droga();
        droga.listar(false);
        cin >> input;

        if (input != 0) {
            if (droga.existeId(input)) {
                auto iterador = find(efectos.begin(), efectos.end(), input);
                if (iterador == efectos.end()) {
                    drogas.push_back(input);
                }
            } else {
                system("cls");
                cout << "El ID ingresado no es valido, intentelo de nuevo." << endl;
                system("pause");
            }
        }
    }

    MedicamentosEfectos medicamentosEfecto = MedicamentosEfectos();
    for (int efectoId: efectos) {
        medicamentosEfecto.setId(0);
        medicamentosEfecto.setEfectoId(efectoId);
        medicamentosEfecto.setMedicamentoId(this->obtenerUltimoId() + 1);
        medicamentosEfecto.crearOrEditar();
    }

    MedicamentoDrogas medicamentoDrogas = MedicamentoDrogas();
    for (int drogaId: drogas) {
        medicamentoDrogas.setId(0);
        medicamentoDrogas.setDrogaId(drogaId);
        medicamentoDrogas.setMedicamentoId(this->obtenerUltimoId() + 1);
        medicamentoDrogas.crearOrEditar();
    }

    setFechaActual();

    ClaseImprimiblePlantilla::crearOrEditar();
    this->listar(true, true);
}
