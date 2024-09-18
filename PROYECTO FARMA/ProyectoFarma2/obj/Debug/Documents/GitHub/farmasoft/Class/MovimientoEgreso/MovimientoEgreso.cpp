#include "MovimientoEgreso.h"
#include <cstring>
#include <ctime>
#include "../Fecha/Fecha.h"
#include "../Medicamento/Medicamento.h"



int MovimientoDeEgreso::getId() const {
    return id;
}

int MovimientoDeEgreso::getCliente_Id() const {
    return clienteId;
}

int MovimientoDeEgreso::getEmpleado_Id() const {
    return empleadoId;
}

int MovimientoDeEgreso::getMedicamento_Id() const {
    return medicamentoId;
}

int MovimientoDeEgreso::getLote_Id() const {
    return loteId;
}


int MovimientoDeEgreso::getCantidad() const {
    return cantidad;
}


Fecha MovimientoDeEgreso::getFechaCreacion() const {
    return fechaCreacion;
}

void MovimientoDeEgreso::setId(int id) {
    this->id = id;
}

void MovimientoDeEgreso::setCliente_Id(int clienteId) {
    this->clienteId = clienteId;
}

void MovimientoDeEgreso::setEmpleado_Id(int empleadoId) {
    this->empleadoId = empleadoId;
}

void MovimientoDeEgreso::setMedicamento_Id(int medicamentoId) {
    this->medicamentoId = medicamentoId;
}

void MovimientoDeEgreso::setLote_Id(int loteId) {
    this->loteId = loteId;
}


void MovimientoDeEgreso::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void MovimientoDeEgreso::setTotal(float total) {
    this->total = total;
}

void MovimientoDeEgreso::setFechaCreacion(const Fecha& fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}

void MovimientoDeEgreso::setFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    fechaCreacion.setDia(now->tm_mday);
    fechaCreacion.setMes(now->tm_mon + 1); // Los meses son desde 0 a 11
    fechaCreacion.setAnio(now->tm_year + 1900); // Años desde 1900
}



vector<vector<string> > MovimientoDeEgreso::getTabla() {
    vector<vector<string> > final;
    final.push_back({"ID CLIENTE", "ID EMPLEADO","ID MEDICAMENTO", "LOTE","CANTIDAD","FECHA"});
    FILE *p = fopen("MovimientoDeEgreso.dat", "rb");
    if (p == nullptr) return final;
    int cantidadRegistros = this->contarRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        vector<string> aux;
        MovimientoDeEgreso movimientodeegreso = MovimientoDeEgreso();
        fseek(p, sizeof movimientodeegreso * i, 0);
        fread(&movimientodeegreso, sizeof(movimientodeegreso), 1, p);
        aux.push_back(to_string(movimientodeegreso.getCliente_Id()));
        aux.push_back(to_string(movimientodeegreso.getEmpleado_Id()));
        aux.push_back(to_string(movimientodeegreso.getMedicamento_Id()));
        aux.push_back(to_string(movimientodeegreso.getLote_Id()));
        aux.push_back(to_string(movimientodeegreso.getCantidad()));
        aux.push_back(movimientodeegreso.getFechaCreacion().getFechaConcatenada());
        final.push_back(aux);
    }
    fclose(p);
    return final;
}


string MovimientoDeEgreso::getNombreArchivo() {
    return "MovimientoDeEgreso.dat";
}

void MovimientoDeEgreso::verFicha (int id) {
    return;
}

string MovimientoDeEgreso::getTitulo() {
    return "Movimientos de Egreso";
}

void MovimientoDeEgreso::crearOrEditar() {
    system("cls");
    cout << "Ingrese el ID del cliente" << endl;
    cin >>this-> clienteId;

    system("cls");
    cout << "Ingrese el ID del empleado" << endl;
    cin >>this-> empleadoId;

    system("cls");
    cout << "Ingrese el ID del medicamento" << endl;
    cin >>this-> medicamentoId;

    system("cls");
    cout << "Ingrese el ID del lote" << endl;
    cin >>this-> loteId;

    system("cls");
    cout << "Ingrese la cantidad" << endl;
    cin >>this-> cantidad;

    setFechaActual();
    ClaseImprimiblePlantilla::crearOrEditar();
    this->listar(true);
}



// void MovimientoDeEgreso::modificarStock() {
//     string archivoMed = Medicamento().getNombreArchivo();
//     int cantRegistrosMedicamento = archivoMed.contarRegistros();
//     Medicamento regMedicamento;
//
//     for (int i = 0; i < cantRegistrosMedicamento; ++i) {
//         regMedicamento = archivoMed.leerRegistro(i);
//         if (regMedicamento.getId() == medicamentoId) {
//             int nuevoStock = regMedicamento.getStock() - cantidad;
//             if (nuevoStock < 0) nuevoStock = 0; //
//             regMedicamento.setStock(nuevoStock);
//             archivoMed.escribirRegistro(regMedicamento, i);
//             return;
//         }
//     }
// }
