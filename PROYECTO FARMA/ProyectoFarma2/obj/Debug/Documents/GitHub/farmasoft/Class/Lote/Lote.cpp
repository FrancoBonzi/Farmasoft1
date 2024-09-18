#include "Lote.h"
#include <cstring>

//GET
int Lote::getmedicamentoId() const {
    return medicamentoId;
}

int Lote::getingresoId() const {
    return ingresoId;
}

int Lote::getcantidadRestante() const {
    return cantidadRestante;
}

Fecha Lote::getfechaVencimiento() const {
    return fechaVencimiento;
}
//SET
void Lote::setmedicamentoId(int medicamentoId) {
    this->medicamentoId = medicamentoId;
}

void Lote::setingresoId(int ingresoId) {
    this->ingresoId = ingresoId;
}

void Lote::setcantidadRestante(int cantidadRestante) {
    this->cantidadRestante = cantidadRestante;
}

void Lote::setfechaVencimiento(const Fecha& fechaVencimiento) {
    this->fechaVencimiento = fechaVencimiento;
}
