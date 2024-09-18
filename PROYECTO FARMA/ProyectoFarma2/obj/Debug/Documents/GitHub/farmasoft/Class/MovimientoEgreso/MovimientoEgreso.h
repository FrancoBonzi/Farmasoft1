#ifndef MOVIMIENTOEGRESO_H
#define MOVIMIENTOEGRESO_H
#include <string>
#include "../Fecha/Fecha.h"
#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"

class MovimientoDeEgreso : public ClaseImprimiblePlantilla<MovimientoDeEgreso> {
    public:
        int id;
        int clienteId;
        int empleadoId;
        int medicamentoId;
        int loteId;
        int metodoPagoId;
        int cantidad;
        float total;
        Fecha fechaCreacion;

        int getId() const override;
        int getCliente_Id() const;
        int getEmpleado_Id() const;
        int getMedicamento_Id() const;
        int getLote_Id() const;
        int getMetodo_Pago_Id() const;
        int getCantidad() const;
        float getTotal_neto() const;
        float getTotal_bruto() const;
        int getDescuento() const;
        Fecha getFechaCreacion() const;


        void setId(int id) override;
        void setCliente_Id(int clienteId);
        void setEmpleado_Id(int empleadoId);
        void setMedicamento_Id(int medicamentoId);
        void setLote_Id(int loteId);
        void setMetodo_Pago_Id(int metodoPagoId);
        void setCantidad(int cantidad);
        void setTotal(float total);

        void setFechaCreacion(const Fecha &fechaCreacion);

        void setTotal_neto(float Total_neto);
        void setTotal_bruto(float Total_bruto);
        void setDescuento(int Descuento);

        void setFechaActual();
        vector<vector<string> > getTabla() override;
        string getNombreArchivo() override;
        void verFicha (int id) override;
        string getTitulo() override;
        void crearOrEditar() override;
        void modificarStock();
};


#endif // MOVIMIENTOEGRESO_H
