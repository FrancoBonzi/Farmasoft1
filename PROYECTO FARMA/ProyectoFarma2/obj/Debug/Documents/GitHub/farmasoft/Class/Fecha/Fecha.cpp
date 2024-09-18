#include "Fecha.h"

#include <ctime>
#include <iostream>
#include <cstring>
#include <sstream>

//Devuelve true si el a�o recibido es bisiesto.
bool Fecha::esbisiesto(int a) {
    bool bisiesto = false;
    if (a % 4 == 0)
        bisiesto = true;
    if ((a % 100 == 0) && (a % 400 != 0))
        bisiesto = false;
    return bisiesto;
}

//Muestra la fecha en formato n�mero. Ej.:  15/10/2008
void Fecha::MostrarFecha() {
    cout << dia << "/" << mes << "/" << anio << endl;
} //�Qu� modificaci�n habr�a que hacer para que siempre muestre DD/MM/AAAA?


//Muestra la fecha indicando en texto el d�a y el mes.Ej.: Lunes 1 de enero de 1900
void Fecha::MostrarFechaTexto() {
    char mmes[12][10];
    strcpy(mmes[0], "Enero");
    strcpy(mmes[1], "Febrero");
    strcpy(mmes[2], "Marzo");
    strcpy(mmes[3], "Abril");
    strcpy(mmes[4], "Mayo");
    strcpy(mmes[5], "Junio");
    strcpy(mmes[6], "Julio");
    strcpy(mmes[7], "Agosto");
    strcpy(mmes[8], "Septiembre");
    strcpy(mmes[9], "OCtubre");
    strcpy(mmes[10], "Noviembre");
    strcpy(mmes[11], "Diciembre");


    int cantdias = NumeroSerie() - 1; //cantidad de d�as transcurridos desde 01/01/1900
    //El 01/01/1900 fue Lunes
    int numerodia = cantdias % 7;

    char mdia[7][10];
    strcpy(mdia[0], "Lunes");
    strcpy(mdia[1], "Martes");
    strcpy(mdia[2], "Miercoles");
    strcpy(mdia[3], "Jueves");
    strcpy(mdia[4], "Viernes");
    strcpy(mdia[5], "S�bado");
    strcpy(mdia[6], "Domingo");

    cout << endl << mdia[numerodia] << " " << dia << " de " << mmes[mes - 1] << " de " << anio << endl;
}

//Devuelve la cantidad de d�as transcurridos desde el 01/01/1900
int Fecha::NumeroSerie() {
    int cont = 0, i;
    for (i = 1900; i < anio; i++)
        if (esbisiesto(i)) cont++;
    int vmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31}, suma = 0;
    if (esbisiesto(anio)) vmes[1] = 29;
    for (int i = 0; i < mes - 1; i++) suma += vmes[i];
    int cantdias = (anio - 1900) * 365 + cont + suma + dia;
    return cantdias;
}

string Fecha::getFechaConcatenada() {
    stringstream ss;
    ss << dia << "/" << mes << "/" << anio;
    return ss.str();
}

bool Fecha::operator>(Fecha &obj) {
    if (NumeroSerie() > obj.NumeroSerie())
        return true;
    return false;
}

bool Fecha::operator==(Fecha &obj) {
    if (NumeroSerie() == obj.NumeroSerie())
        return true;
    return false;
}

void Fecha::NumeroSerieaFecha(int ns) {
    int suma = 0, dia_adicional, suma_ant;
    int anio_real = 1900;
    while (ns > suma) {
        dia_adicional = (esbisiesto(anio_real) ? 1 : 0);
        suma_ant = suma;
        suma += 365 + dia_adicional;
        anio_real++;
    }
    anio = anio_real - 1;
    //Cantidad de d�as pasados desde anio
    int dias_anio_actual = ns - suma_ant, i = 0;
    int vmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31};
    if (esbisiesto(anio)) vmes[1] = 29;
    suma = 0;
    while (dias_anio_actual > suma) suma += vmes[i++];
    mes = i;
    dia = dias_anio_actual - (suma - vmes[i - 1]);
}

void Fecha::operator +=(int masdias) {
    int ns = NumeroSerie() + masdias;
    NumeroSerieaFecha(ns);
}

istream &operator>>(istream &entra, Fecha &f) {
    cout << "Ingrese el dia: ";
    entra >> f.dia;
    cout << "Ingrese el mes: ";
    entra >> f.mes;
    cout << "Ingrese el a�o: ";
    entra >> f.anio;
    return entra;
}

ostream &operator<<(ostream &sale, Fecha &f) {
    cout << "Dia: ";
    sale << f.dia << endl;
    cout << "Mes: ";
    sale << f.mes << endl;
    cout << "A�o: ";
    sale << f.anio << endl;
    return sale;
}

Fecha Fecha::operator+(int masdias) {
    Fecha aux;
    int ns = NumeroSerie() + masdias;
    aux.NumeroSerieaFecha(ns);
    return aux;
}

int Fecha::operator -(Fecha &obj) {
    return NumeroSerie() - obj.NumeroSerie();
}
