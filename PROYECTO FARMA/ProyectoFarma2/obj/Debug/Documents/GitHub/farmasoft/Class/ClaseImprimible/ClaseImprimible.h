#ifndef CLASEIMPRIMIBLE_H
#define CLASEIMPRIMIBLE_H
#include <iostream>
#include <vector>

using namespace std;

class ClaseImprimible {
    public:
        virtual ~ClaseImprimible() = default;

        virtual vector<vector<string> > getTabla() = 0;
        virtual void editar() = 0;
        virtual string getNombreArchivo() = 0;
        virtual string getTitulo() = 0;
        virtual void eliminar(int id, string archivo = "") = 0;
        virtual void setId(int id) = 0;
        virtual int getId() const = 0 ;
        virtual int contarRegistros() = 0;

        virtual void crearOrEditar() = 0;

        virtual void verFicha (int id) = 0;
        virtual bool existeId(int id) = 0;
        virtual void listar(bool conMenuInteractivo, bool conFicha = false);
};

#endif //CLASEIMPRIMIBLE_H
