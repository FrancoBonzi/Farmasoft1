#ifndef MEDICAMENTOSDROGAS_H
#define MEDICAMENTOSDROGAS_H
#include <sstream>

#include "../ClaseImprimible/ClaseImprimiblePlantilla.h"
#include "../Droga/Droga.h"


class MedicamentoDrogas : public ClaseImprimiblePlantilla<MedicamentoDrogas> {
    private:
        int id;
        int medicamentoId;
        int drogaId;

    public:
        int getId() const override { return id; };
        void setId(int id) override { this->id = id; };

        vector<vector<string> > getTabla() override {
            vector<vector<string> > aux;
            return aux;
        };

        string getNombreArchivo() override { return "medicamentoDrogas.dat"; };
        string getTitulo() override { return "Drogas de Medicamentos"; };


        int getMedicamentoId() const { return medicamentoId; };
        void setMedicamentoId(int id) { this->medicamentoId = id; };

        int getDrogaId() const { return drogaId; };
        void setDrogaId(int id) { this->drogaId = id; }


        string getDrogasPorMedicamentoId() {
            string nombresConcatenados;
            vector<int> drogasId;
            FILE *p = fopen("medicamentoDrogas.dat", "rb");
            if (p != nullptr) {
                MedicamentoDrogas medicamentoDrogas;
                while (fread(&medicamentoDrogas, sizeof(MedicamentoDrogas), 1, p) == 1) {
                    if (medicamentoDrogas.getMedicamentoId() == medicamentoId) {
                        drogasId.push_back(medicamentoDrogas.getDrogaId());
                    }
                }
                fclose(p);
            }

            p = fopen("drogas.dat", "rb");
            if (p != nullptr) {
                Droga drogaActual;
                while (fread(&drogaActual, sizeof(Droga), 1, p) == 1) {
                    for (int drogaId: drogasId) {
                        if (drogaId == drogaActual.getId()) {
                            if (!nombresConcatenados.empty()) {
                                nombresConcatenados += ", ";
                            }
                            nombresConcatenados += drogaActual.getNombre();
                        }
                    }
                }
                fclose(p);
            }
            return nombresConcatenados;
        }

        void eliminarDrogasPorMedicamentoId() {
            FILE *p = fopen("medicamentoDrogas.dat", "rb");
            if (p != nullptr) {
                MedicamentoDrogas medicamentoDrogas;
                while (fread(&medicamentoDrogas, sizeof(MedicamentoDrogas), 1, p) == 1) {
                    if (medicamentoDrogas.getMedicamentoId() == medicamentoId) {
                        medicamentoDrogas.eliminar(medicamentoDrogas.getId(), "medicamentoDrogas.dat");
                    }
                }
                fclose(p);
            }
        }

        void verFicha(int id) override {
            return;
        }
};

#endif //MEDICAMENTOSDROGAS_H
