#ifndef MOVIMIENTOINGRESO_H
#define MOVIMIENTOINGRESO_H
#include <string>
#include "../Fecha/Fecha.h"
#include "../ClaseImprimible/ClaseImprimible.h"
#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"


class MovimientoIngreso : public ClaseImprimiblePlantilla<MovimientoIngreso>{
    public:
    int id;
    int medicamentoId;
    int empleadoId;
    int cantidad;
    int lote;
    Fecha fechaCreacion;
    Fecha fechaVencimiento;

    int getId() const override;
    int getMedicamento_Id() const;
    int getEmpleado_Id() const;
    int getCantidad() const;
    int getLote() const;
    Fecha getFechaCreacion() const;
    Fecha getFechaVencimiento() const;


    void setId(int id) override;
    void setMedicamento_Id(int medicamentoId);
    void setEmpleado_Id(int empleadoId);
    void setCantidad(int cantidad);
    void setLote(int lote);

    void setFechaCreacion(const Fecha& fechaCreacion);

    void setFechaActual();
    void setFechaVencimiento(const Fecha& fechaVencimiento);



    vector<vector<string> > getTabla() override;
    string getNombreArchivo() override;
    string getTitulo() override;
    void verFicha (int id) override;
    void crearOrEditar() override;

};


#endif // MOVIMIENTOINGRESO_H

