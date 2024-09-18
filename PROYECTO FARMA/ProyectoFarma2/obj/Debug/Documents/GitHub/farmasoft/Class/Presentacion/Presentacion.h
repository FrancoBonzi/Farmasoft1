#ifndef PRESENTACION_H
#define PRESENTACION_H
#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"

using namespace std;

class Presentacion:public ClaseImprimiblePlantilla<Presentacion> {
    private:
        int id;
        char nombre[30] = "";

    public:
        int getId() const;
        const char *getNombre() const;
        void setNombre(const char *nombre);

        void setId(int id) override;
        vector<vector<string> > getTabla() override;
        string getNombreArchivo() override;
        string getTitulo() override;
        void verFicha (int id) override;
        void crearOrEditar() override;
};


#endif //PRESENTACION_H
