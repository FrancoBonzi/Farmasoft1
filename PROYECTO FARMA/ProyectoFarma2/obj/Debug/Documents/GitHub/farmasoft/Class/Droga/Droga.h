#ifndef DROGA_H_INCLUDED
#define DROGA_H_INCLUDED
#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"
#include "../Fecha/Fecha.h"

class Droga : public ClaseImprimiblePlantilla<Droga> {
    private:
        int id;
        char nombre[15] = "";

    public:
        typedef ClaseImprimible super;
        int getId() const;
        const char *getNombre() const;
        Fecha getFechaCreacion() const;

        void setNombre(const char *nombre);
        void setFechaCreacion(Fecha fechaCreacion);

        void setId(int id) override;
        vector<vector<string> > getTabla() override;
        string getTitulo() override;
        void verFicha (int id) override;
        string getNombreArchivo() override;
        void crearOrEditar() override;
};


#endif // DROGA_H_INCLUDED
