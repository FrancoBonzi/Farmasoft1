#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;
class Fecha {
    private:
        int dia;
        int mes;
        int anio;
        bool esbisiesto(int);
        void NumeroSerieaFecha(int);
    public:
        Fecha(int d = 0, int m = 0, int a = 0) {
            dia = d;
            mes = m;
            anio = a;
        };
        int getDia() { return dia; }
        int getMes() { return mes; }
        int getAnio() { return anio; }
        void setDia(int d) { dia = d; }
        void setMes(int m) { mes = m; };
        void setAnio(int a) { anio = a; }
        void MostrarFecha();
        void MostrarFechaTexto();
        int NumeroSerie();
        string getFechaConcatenada();
        static string getFechaTexto;
        bool operator >(Fecha &);
        bool operator ==(Fecha &);
        Fecha operator+(int);
        int operator -(Fecha &);
        void operator +=(int);
        friend istream &operator>>(istream &, Fecha &);
        friend ostream &operator<<(ostream &, Fecha &);
};

#endif //FECHA_H

