#ifndef LOTE_H
#define LOTE_H
#include <string>
#include "../Fecha/Fecha.h"

class Lote {

    public:
        int medicamentoId;
        int ingresoId;
        int cantidadRestante;
        Fecha fechaVencimiento;

        int getmedicamentoId() const;
        int getingresoId() const;
        int getcantidadRestante() const;
        Fecha getfechaVencimiento() const;

        void setmedicamentoId(int medicamentoId);
        void setingresoId(int ingresoId);
        void setcantidadRestante(int cantidadRestante);
        void setfechaVencimiento(const Fecha& fechaVencimiento);
};


#endif //LOTE_H
