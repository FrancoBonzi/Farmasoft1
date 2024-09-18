#ifndef MENU_H
#define MENU_H
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

#include "../Droga/Droga.h"
#include "../Efecto/Efecto.h"
#include "../Marca/Marca.h"
#include "../Medicamento/Medicamento.h"
#include "../Presentacion/Presentacion.h"
#include "../MovimientoEgreso/MovimientoEgreso.h"
#include "../MovimientoIngreso/MovimientoIngreso.h"

using namespace std;

class Menu {
    public:
        void imprimir(const int opcionSeleccionada, vector<string> opciones) {
            int tamanio = opciones.size();
            system("cls");
            cout << "FARMASOFT\n\n";
            for (int i = 0; i < tamanio; ++i) {
                if (i == opcionSeleccionada) {
                    cout << "\033[7m";
                    cout << opciones[i];
                    cout << "\033[0m";
                } else {
                    cout << opciones[i];
                }
                cout << "\n";
            }
        }

        int imprimirMenu(vector<string> opciones) {
            int opcionSeleccionada = 0;
            char tecla;
            int tamanio = opciones.size();

            do {
                imprimir(opcionSeleccionada, opciones);

                while (!_kbhit());
                tecla = _getch();

                switch (tecla) {
                    case 72: {
                        // FLECHA PARA ARRIBA
                        opcionSeleccionada = (opcionSeleccionada + tamanio - 1) % tamanio;
                        break;
                    }
                    case 80: {
                        // FLECHA PARA ABAJO
                        opcionSeleccionada = (opcionSeleccionada + 1) % tamanio;
                        break;
                    }
                    case 13: // ENTER
                        return opcionSeleccionada;
                    default:
                        break;
                }
            } while (tecla != 13);

            return 0;
        }

        void imprimirMenuPrincipal() {
            vector<string> nuevasOpciones = {
                "MEDICAMENTOS", "EFECTOS", "DROGAS", "MARCAS", "PRESENTACIONES", "MOVIMIENTOS DE INGRESOS",
                "MOVIMIENTOS DE EGRESOS"
            };
            int listadoOpcion = this->imprimirMenu(nuevasOpciones);
            switch (listadoOpcion) {
                case 0: {
                    Medicamento medicamento;
                    medicamento.listar(true, true);
                    break;
                }
                case 1: {
                    Efecto efecto;
                    efecto.listar(true);
                    break;
                }
                case 2: {
                    Droga droga;
                    droga.listar(true);
                    break;
                }
                case 3: {
                    Marca marca;
                    marca.listar(true);
                    break;
                }
                case 4: {
                    Presentacion presentacion;
                    presentacion.listar(true);
                    break;
                }
                case 5: {
                    MovimientoIngreso movimientoIngreso;
                    movimientoIngreso.listar(true);
                    break;
                }
                case 6: {
                    MovimientoDeEgreso movimientoEgreso;
                    movimientoEgreso.listar(true);
                    break;
                }
                default:
                    break;
            }
        }
};


#endif // MENU_H
