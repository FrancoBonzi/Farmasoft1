#include "ClaseImprimible.h"

#include <conio.h>

#include "../Efecto/Efecto.h"
#include "../Menu/Menu.h"

void ClaseImprimible::listar(bool conMenuInteractivo, bool conFicha) {
    int tecla = 0;
    bool opcionCorrecta = false;
    vector<vector<string> > items = this->getTabla();
    do {
        if (conMenuInteractivo) {
            system("cls");
            cout << "FARMASOFT" << endl << endl;
            cout << this->getTitulo() << endl << endl;

            string concat = "1. Crear | ";
            if (conFicha) {
                concat += "2. Ver ficha |";
            }
            concat += " 3. Editar | 4. Borrar | 5. Volver";
            cout << concat << endl << endl;
        }

        for (vector<string> &row: items) {
            for (string &col: row) {
                col.resize(25, ' ');
                cout << col << " ";
            }
            cout << endl;
        }

        cout << endl << "Se han encontrado " << this->contarRegistros() << " registros" << endl << endl;

        if (conMenuInteractivo) {
            while (!_kbhit());
            tecla = _getch();
        }

        if (tecla == 49 || (conFicha && tecla == 50) || tecla == 51 || tecla == 52 || tecla == 53) {
            opcionCorrecta = true;
        }
    } while (conMenuInteractivo && !opcionCorrecta);

    if (conMenuInteractivo) {
        switch (tecla) {
            case 49: {
                this->setId(0);
                this->crearOrEditar();
                break;
            };
            case 50: {
                system("cls");
                int id;
                cout << this->getTitulo() << endl << endl;
                cout << "Ingrese el ID del que registro que desea ver, o 0 para volver" << endl << endl;
                this->listar(false);
                cout << endl;
                cin >> id;

                if (id == 0) {
                    this->listar(true, conFicha);
                    break;
                }

                this->verFicha(id);
                this->listar(true, conFicha);
                break;
            }

            case 51: {
                bool opcionCorrecta = false;
                int id;
                while (!opcionCorrecta) {
                    system("cls");
                    cout << "Ingrese el ID del que registro que desea editar, o 0 para volver" << endl << endl;
                    this->listar(false);
                    cout << endl;
                    cin >> id;

                    if (id == 0) {
                        this->listar(true, conFicha);
                        break;
                    }

                    if (this->existeId(id)) {
                        opcionCorrecta = true;
                    } else {
                        system("cls");
                        cout << "El ID no existe, intentelo de nuevo" << endl << endl;
                        system("pause");
                    }
                }
                this->setId(id);
                this->crearOrEditar();
                this->listar(true, conFicha);
                break;
            }
            case 52: {
                bool opcionCorrecta = false;
                int id;
                while (!opcionCorrecta) {
                    system("cls");
                    cout << "Ingrese el ID del que registro que desea eliminar, o 0 para volver" << endl << endl;
                    this->listar(false, conFicha);
                    cout << endl;
                    cin >> id;

                    if (id == 0) {
                        this->listar(true, conFicha);
                        break;
                    }

                    if (this->existeId(id)) {
                        opcionCorrecta = true;
                    } else {
                        system("cls");
                        cout << "El ID no existe, intentelo de nuevo" << endl << endl;
                        system("pause");
                    }
                }
                this->eliminar(id);
                this->listar(true, conFicha);
                break;
            }
            case 53: {
                system("cls");
                Menu menu = Menu();
                menu.imprimirMenuPrincipal();
                break;
            }
            case 54: {
                system("cls");
                Menu menu = Menu();
                menu.imprimirMenuPrincipal();
                break;
            }
            default: break;
        }
    }
}
