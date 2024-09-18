#ifndef EFECTO_H
#define EFECTO_H
#include <vector>

#include "../ClaseImprimible/ClaseImprimible.h"
#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"

using namespace std;

class Efecto : public ClaseImprimiblePlantilla<Efecto> {
    private:
        int id;
        char nombre[30] = "";
    public:
        int getId() const;
        const char *getNombre() const;
        void setNombre(const char *nombre);
        void verFicha (int id) override;

        void setId(int id) override;
        vector<vector<string> > getTabla() override;
        string getNombreArchivo() override;
        string getTitulo() override;
        void crearOrEditar() override;
};

#endif //EFECTO_H
