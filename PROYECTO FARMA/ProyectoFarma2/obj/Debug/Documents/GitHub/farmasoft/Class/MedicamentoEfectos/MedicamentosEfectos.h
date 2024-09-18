#ifndef MEDICAMENTOSEFECTOS_H
#define MEDICAMENTOSEFECTOS_H
#include <sstream>

#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"
#include "../Efecto/Efecto.h"


class MedicamentosEfectos : public ClaseImprimiblePlantilla<MedicamentosEfectos> {
    private:
        int id;
        int medicamentoId;
        int efectoId;

    public:
        int getId() const override { return id; };
        void setId(int id) override { this->id = id; };

        vector<vector<string> > getTabla() override {
            vector<vector<string> > aux;
            return aux;
        };

        string getNombreArchivo() override { return "medicamentoEfectos.dat"; };
        string getTitulo() override { return "Efectos de Medicamentos"; };


        int getMedicamentoId() const { return medicamentoId; };
        void setMedicamentoId(int id) { this->medicamentoId = id; };

        int getEfectoId() const { return efectoId; };
        void setEfectoId(int id) { this->efectoId = id; }


        string getEfectosPorMedicamentoId() {
            string nombresConcatenados;
            vector<int> efectosId;
            FILE *p = fopen("medicamentoEfectos.dat", "rb");
            if (p != nullptr) {
                MedicamentosEfectos medicamentoEfecto;
                while (fread(&medicamentoEfecto, sizeof(MedicamentosEfectos), 1, p) == 1) {
                    if (medicamentoEfecto.getMedicamentoId() == medicamentoId) {
                        efectosId.push_back(medicamentoEfecto.getEfectoId());
                    }
                }
                fclose(p);
            }

            p = fopen("efectos.dat", "rb");
            if (p != nullptr) {
                Efecto efectoActual;
                while (fread(&efectoActual, sizeof(Efecto), 1, p) == 1) {
                    for (int efectoId: efectosId) {
                        if (efectoId == efectoActual.getId()) {
                            if (!nombresConcatenados.empty()) {
                                nombresConcatenados += ", ";
                            }
                            nombresConcatenados += efectoActual.getNombre();
                        }
                    }
                }
                fclose(p);
            }
            return nombresConcatenados;
        }

        void eliminarEfectosPorMedicamentoId () {
            FILE *p = fopen("medicamentoEfectos.dat", "rb");
            if (p != nullptr) {
                MedicamentosEfectos medicamentoEfecto;
                while (fread(&medicamentoEfecto, sizeof(MedicamentosEfectos), 1, p) == 1) {
                    if (medicamentoEfecto.getMedicamentoId() == medicamentoId) {
                        medicamentoEfecto.eliminar(medicamentoEfecto.getId(), "medicamentoEfectos.dat");
                    }
                }
                fclose(p);
            }
        }

        void verFicha (int id) override {
                return;
        }
};


#endif //MEDICAMENTOSEFECTOS_H
