#ifndef MARCA_H
#define MARCA_H
#include <string>
#include <vector>

#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"

using namespace std;

class Marca : public ClaseImprimiblePlantilla<Marca> {
    private:
        int id;
        char nombre[30] = "";

    public:
        int getId() const;
        const char *getNombre() const;
        void setNombre(const char *nombre);

        void setId(int id) override;
        vector<vector<string> > getTabla() override;
        void verFicha (int id) override;
        string getNombreArchivo() override;
        string getTitulo() override;
        void crearOrEditar() override;

        static bool YaExisteId(int id);
};


#endif //MARCA_H
