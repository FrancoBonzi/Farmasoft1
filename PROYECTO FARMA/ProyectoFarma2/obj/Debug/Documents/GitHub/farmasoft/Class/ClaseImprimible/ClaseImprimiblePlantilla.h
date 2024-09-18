#ifndef CLASEIMPRIMIBLEPLANTILLA_H
#define CLASEIMPRIMIBLEPLANTILLA_H

#include "ClaseImprimible.h"
#include <type_traits>

template<typename T>
class ClaseImprimiblePlantilla : public ClaseImprimible {
    public:
        int contarRegistros() override {
            FILE *archivo = fopen(this->getNombreArchivo().c_str(), "rb");
            if (archivo != nullptr) {
                fseek(archivo, 0, SEEK_END);
                long int tamanoArchivo = ftell(archivo);
                int tamanoRegistro = sizeof(T);
                int cantidadRegistros = tamanoArchivo / tamanoRegistro;
                fclose(archivo);
                return cantidadRegistros;
            }
            return 0;
        }

        int obtenerUltimoId() {
            FILE *archivo = fopen(this->getNombreArchivo().c_str(), "rb");
            if (archivo != nullptr) {
                fseek(archivo, -sizeof(T), SEEK_END);
                T registroUltimo;
                fread(&registroUltimo, sizeof(T), 1, archivo);
                int ultimoId = registroUltimo.getId();
                fclose(archivo);
                return (ultimoId > 100000 || ultimoId < 0) ? 0 : ultimoId;
            }
            return 0;
        }

        bool existeId(int id) override {
            FILE *archivo = fopen(this->getNombreArchivo().c_str(), "rb");
            if (archivo == nullptr) {
                return false;
            }

            T registro;
            while (fread(&registro, sizeof(T), 1, archivo)) {
                if (registro.getId() == id) {
                    fclose(archivo);
                    return true;
                }
            }

            fclose(archivo);
            return false;
        }

        T getRegistro(int id) {
            T claseFallida = T();
            FILE *archivo = fopen(this->getNombreArchivo().c_str(), "rb");
            if (archivo == nullptr) {
                std::cerr << "Error al abrir el archivo." << std::endl;
                return claseFallida;
            }

            T registro;
            while (fread(&registro, sizeof(T), 1, archivo)) {
                if (registro.getId() == id) {
                    fclose(archivo);
                    return registro;
                }
            }

            fclose(archivo);
            return claseFallida;
        }

        void crearOrEditar() override {
            //Si tengo un ID asignado, es porque quiero editar
            if (static_cast<T *>(this)->getId()) return this->editar();

            static_cast<T *>(this)->setId(obtenerUltimoId() + 1);
            FILE *p = fopen(this->getNombreArchivo().c_str(), "ab");
            if (p != nullptr) {
                fwrite(static_cast<T *>(this), sizeof(T), 1, p);
                fclose(p);
            }
        }

        void editar() override {
            FILE *p = fopen(this->getNombreArchivo().c_str(), "rb+");
            if (p == nullptr) {
                cerr << "No se pudo abrir el archivo." << endl;
                return;
            }

            int cantidadRegistros = this->contarRegistros();
            T registro;

            for (int i = 0; i <= cantidadRegistros; ++i) {
                fseek(p, i * sizeof(T), SEEK_SET);
                fread(&registro, sizeof(T), 1, p);

                if (registro.getId() == this->getId()) {
                    fseek(p, i * sizeof(T), SEEK_SET);
                    fwrite(static_cast<T *>(this), sizeof(T), 1, p);
                    break;
                }
            }
            fclose(p);
        }

        void eliminar(int id, string archivo = "") override {
            archivo = !archivo.empty()  ? archivo : this->getNombreArchivo();
            FILE *p = fopen(archivo.c_str(), "rb");
            if (p == nullptr) {
                cerr << "No se pudo abrir el archivo." << endl;
                return;
            }

            vector<T> registros;
            T registro;
            while (fread(&registro, sizeof(T), 1, p)) {
                if (registro.getId() != id) {
                    registros.push_back(registro);
                }
            }
            fclose(p);

            p = fopen(archivo.c_str(), "wb");
            if (p == nullptr) {
                cerr << "No se pudo abrir el archivo." << endl;
                return;
            }

            for (const T &reg: registros) {
                fwrite(&reg, sizeof(T), 1, p);
            }
            fclose(p);
        }
};

#endif //CLASEIMPRIMIBLEPLANTILLA_H
