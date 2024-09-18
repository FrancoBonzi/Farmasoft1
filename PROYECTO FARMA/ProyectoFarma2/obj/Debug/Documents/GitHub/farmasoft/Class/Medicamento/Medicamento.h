#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include "../ClaseImprimible/ClaseImprimible.h"
#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"
#include "../Fecha/Fecha.h"

class Medicamento : public ClaseImprimiblePlantilla<Medicamento> {
    private:
        int id{};
        int marcaId{};
        int presentacionId = 0;
        char unidad[3] = "ml";
        int cantidad{};
        float precio = 0;
        int stock = 0;
        Fecha fechaCreacion;

    public:
        int getId() const override;
        int getMarcaId();
        float getPrecio();
        int getStock() const;
        const char *getUnidad() const;
        int getPresentacionId() const;
        Fecha getFechaCreacion() const;

        string getMarcaNombre ();
        string getPresentacionNombre ();
        string getEfectosNombres ();
        string getDrogasNombres ();

        void setId(int id) override;
        void setMarcaId(int marca);
        void setPresentacionId(int presentacionId);
        void setPrecio(float precio);
        void setStock(int stock);
        void setFechaCreacion(Fecha fechaCreacion);
        void setUnidad(const char *unidad);

        vector<vector<string> > getTabla() override;
        void setFechaActual();
        void verFicha (int id) override;
        string getNombreArchivo() override;
        string getTitulo() override;
        void eliminarDrogas();
        void eliminarEfectos();
        void eliminar(int id, string archivo) override;

        void crearOrEditar() override;
};
#endif //MEDICAMENTO_H
