#include <iostream>
#include <string.h>
#include <fstream>
#include "Fun.h"
using namespace std;
int main() {
    int caso;
    bool accion=1;
    cout<<"Ingrese 1 para ingresar como administrador"<<endl;
    cout<<"Ingrese 2 para ingresar como usuario"<<endl;
    cout<<"Ingrese 0 para salir del programa"<<endl;
    cin>>caso;
    while(accion){
        if(caso==1){
            administrador ad1("");
            ad1.admin();
            cout<<"Ingrese 1 para ingresar como administrador"<<endl;
            cout<<"Ingrese 2 para ingresar como usuario"<<endl;
            cout<<"Ingrese 0 para salir del programa"<<endl;
            cin>>caso;
        }

        else if(caso==2){
            usuario ad2("","");
            ad2.interfaz_us();
            cout<<"Ingrese 1 para ingresar como administrador"<<endl;
            cout<<"Ingrese 2 para ingresar como usuario"<<endl;
            cout<<"Ingrese 0 para salir del programa"<<endl;
            cin>>caso;
        }
        else if(caso==0){
            cout<<"saliendo del programa"<<endl;
            accion=0;
        }
        else {
            cout<<"ingrese una opcion valida"<<endl;
            cout<<"Ingrese 1 para ingresar como administrador"<<endl;
            cout<<"Ingrese 2 para ingresar como usuario"<<endl;
            cout<<"Ingrese 0 para salir del programa"<<endl;
            cin>>caso;
        }
    }
}
