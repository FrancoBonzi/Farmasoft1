#include "MovimientoIngreso.h"
#include <cstring>
#include <ctime>
// GET
int MovimientoIngreso::getId() const {
    return id;
}

int MovimientoIngreso::getMedicamento_Id() const {
    return medicamentoId;
}

int MovimientoIngreso::getEmpleado_Id() const {
    return empleadoId;
}


int MovimientoIngreso::getLote() const {
    return lote;
}

int MovimientoIngreso::getCantidad() const {
    return cantidad;
}

Fecha MovimientoIngreso::getFechaCreacion() const {
    return fechaCreacion;
}

Fecha MovimientoIngreso::getFechaVencimiento() const {
    return fechaVencimiento;
}

//SET
void MovimientoIngreso::setId(int id) {
    this->id = id;
}

void MovimientoIngreso::setMedicamento_Id(int medicamentoId) {
    this->medicamentoId = medicamentoId;
}


void MovimientoIngreso::setLote(int lote) {
    this->lote = lote;
}

void MovimientoIngreso::setEmpleado_Id(int empleadoId) {
    this->empleadoId = empleadoId;
}

void MovimientoIngreso::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void MovimientoIngreso::setFechaCreacion(const Fecha& fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}

void MovimientoIngreso::setFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    fechaCreacion.setDia(now->tm_mday);
    fechaCreacion.setMes(now->tm_mon + 1); // Los meses son desde 0 a 11
    fechaCreacion.setAnio(now->tm_year + 1900); // Años desde 1900
}

vector<vector<string> > MovimientoIngreso::getTabla() {
    vector<vector<string> > final;
    final.push_back({"ID EMPLEADO","ID MEDICAMENTO", "LOTE","CANTIDAD","FECHA"});
    FILE *p = fopen("MovimientoIngresos.dat", "rb");
    if (p == nullptr) return final;
    int cantidadRegistros = this->contarRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        vector<string> aux;
        MovimientoIngreso movimientoingreso = MovimientoIngreso();
        fseek(p, sizeof movimientoingreso * i, 0);
        fread(&movimientoingreso, sizeof(movimientoingreso), 1, p);
        aux.push_back(to_string(movimientoingreso.getEmpleado_Id()));
        aux.push_back(to_string(movimientoingreso.getMedicamento_Id()));
        aux.push_back(to_string(movimientoingreso.getLote()));
        aux.push_back(to_string(movimientoingreso.getCantidad()));
        aux.push_back(movimientoingreso.getFechaCreacion().getFechaConcatenada());
        final.push_back(aux);
    }
    fclose(p);
    return final;
}

string MovimientoIngreso::getNombreArchivo() {
    return "MovimientoIngresos.dat";
}

string MovimientoIngreso::getTitulo() {
    return "Movimientos de Ingreso";
}

void MovimientoIngreso::verFicha (int id) {
    return;
}

void MovimientoIngreso::crearOrEditar() {
    system("cls");
    cout << "Ingrese el ID del empleado" << endl;
    cin >>this-> empleadoId;

    system("cls");
    cout << "Ingrese el ID del medicamento" << endl;
    cin >>this-> medicamentoId;

    system("cls");
    cout << "Ingrese el lote" << endl;
    cin >>this-> lote;

    system("cls");
    cout << "Ingrese la cantidad" << endl;
    cin >>this-> cantidad;

    setFechaActual();

    ClaseImprimiblePlantilla::crearOrEditar();
    this->listar(true);
}
