#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <stdio.h>
using namespace std;
#ifndef FUN_H
#define FUN_H


#endif // FUN_H

class usuario{
private:
    string clave;
    string cedula;
    string saldo;
public:
    usuario(string, string);
    bool verificar_us();
    void interfaz_us();
    void ver_saldo(int);
};

class administrador{
private:
    string clave;

public:
    administrador(string);
    bool adminconf();
    void interfaz();
    void add();
    void admin();

};

//esta funcion recibe un string de 1's y 0's
//para implentar el metodo de codificación 2
string mover(string h){

//string h="bienvenidos";
string hmod="";
int f=h.length();
int j=f-1;

for(int i=0;i<f ;i++){

    hmod+=h[i+j];

    if(j==f-1){
        j=-1;
    }
}

return hmod;
}

//esta funcion recibe un numero entero y un string de 1's y 0's
//para por medio de la funcion mover, implementar el
//metodo de codificación 2 en strings de longitud igual
//al numero entero recibido
string metodo2(int sed,string lel)
{
    string copylel=lel;
    int len=lel.length();

    string g="";
    int cont=0;
    int ini=0;

    while(cont<len/sed){

        cont++;

        g="";

        g.append(lel,ini,sed);

        g=mover(g);

        copylel.replace(ini,sed,g);

        ini=ini+sed;
    }

  if(len%sed!=0){

      g="";

      g.append(lel,ini,len%sed);

      g=mover(g);

      copylel.replace(ini,len%sed,g);

  }
return copylel;
}

//esta funcion es el constuctor de la clase administrador
//recibe un string y lo almacena en el atributo clave de la clase
administrador::administrador(string pass){

    clave=pass;

}

//esta funcion valida la identidad del administrador
//verificando si la clave ingresada coincide con la
//clave almacenada
bool administrador::adminconf(){
bool i;
string pass;
ifstream archivo;
archivo.open("../aplicacion/sudo.txt");

archivo>>pass;
if(pass==clave)
{
    i=1;
}

else
{
    i=0;
}
archivo.close();
return i;
}

//esta funcion recibe un valor entero ascii
//y retorna un string de 1's y 0's de longitud 8
string conversion(int decimal){

    string ascii;
    bool binario[8];

    for (int i = 0; i < 8; i++)
    {
        binario[i] = decimal % 2;
        decimal /= 2;
    }

    for (int i = 0; i<8 ; i++)
    {
       if(binario[i]==1){
           ascii.insert(0,"1");
       }

    else{
       ascii.insert(0,"0");
       }
    }
return ascii;
}

//esta funcion recibe un string de caracteres
//y entrega un string de 1's y 0's
string conver(string data){
    string bin;
    int letras=data.length();
    int letra;
    string save;

    for(int pos=letras-1; pos>=0 ;pos--)
    {
        letra= data[pos];
        //funcion que entrega un string con el valor binario de letra
        bin=conversion(letra);
        save.insert(0,bin);
    }
return save;
}

//esta funcion permite al administrador ingresar
//los datos del nuevo usuario y agregarlos a la "base de datos"
void administrador::add(){

    string ced;
    string cla;
    string saldo;

    system("cls");
    ofstream archivo;
    archivo.open("../aplicacion/usuarios.txt",ios::app);
    cout<<"ingresar un espacio va a hacer que se danie el programa"<<endl;
    cout<<"Escriba la cedula del usuario"<<endl;
    cin>>ced;
    system("cls");
    cout<<"Escriba la clave del usuario"<<endl;
    cout<<"ingresar un espacio va a hacer que se danie el programa"<<endl;
    cin>>cla;
    system("cls");
    cout<<"Escriba el saldo inicial del usuario"<<endl;
    cout<<"ingresar un espacio va a hacer que se danie el programa"<<endl;
    cin>>saldo;
    ced=conver(ced);
    cla=conver(cla);
    saldo=conver(saldo);
    ced=metodo2(4,ced);
    cla=metodo2(4,cla);
    saldo=metodo2(4,saldo);
    archivo<<ced<<" "<<cla<<" "<<saldo<<"\n";

    system("cls");

    cout<<"Accion realizada"<<endl;
    archivo.close();
}

//esta funcion muestra el menú del administrador y
//le permite seleccionar la accion a realizar
void administrador::interfaz()
{
    int a=1;

    while(a!=2){
        system("cls");
        cout<<"Escriba el numero de una de las siguientes opciones"<<endl;
        cout<<"(1)Agregar un usuario"<<endl;
        cout<<"(2)Salir"<<endl;
        cout<<"opcion: ";
        cin>>a;

        if(a==1){
        add();
    }

    else{
        if(a==2){
            system("cls");
            cout<<"Saliendo..."<<endl;
            a=2;
        }

        else{
            system("cls");
            cout<<"opcion no valida"<<endl;
        }
    }
 }
}

//esta funcion le permite al administrador ingresar
//la contraseña para validar su identidad
void administrador::admin()
{
    int a=0;
    string con;
    administrador ad1(con);
    cout<<"escriba la contrasena:"<<endl;

    while(a==0)
    {
        cin>>con;
        con= conver(con);
        con= metodo2(4,con);
        administrador ad1(con);
        a=ad1.adminconf();
    if(a==0)
    {
        system("cls");
        cout<<"contrasenia invalida vuelva a intentarlo:" <<endl;
    }

    }
    system("cls");
    ad1.interfaz();

}

//esta funcion corresponde al constructor de la clase usuario
usuario::usuario(string ced, string password){
    cedula=ced;
    clave=password;
}

//esta funcion recibe un numero entero y lo regresa como un string
string decimal_a_string(int numero){
    int divisor=1;
    string n;
    string num;
      while(numero/(divisor*10)>0)
      {
        divisor=divisor*10;
      }

      while(divisor>=1)
      {
        n=numero/divisor+'0';
        num.append(n);
        numero=numero%divisor;
        divisor=divisor/10;
      }
      return num;
}

//esta funcion recibe un string, descodifica el metodo 2 y retorna
//la descodificacion
string invmover(string h){


string hmod="";
int f=h.length();
int j=1;

for(int i=0;i<f ;i++){

    hmod+=h[i+j];

    if(i==2){
        j=-3;

    }

}
return hmod;
}

//esta funcion recibe un string y un entero para, con la ayuda de
//invmover descodificar bloques de strings de longitud
//igual al entero recibido
string invmetodo2(int sed,string lel){

    string copylel=lel;
    int len=lel.length();

    string g="";
    int cont=0;
    int ini=0;

    while(cont<len/sed){

        cont++;

        g="";

        g.append(lel,ini,sed);

        g=invmover(g);

        copylel.replace(ini,sed,g);

        ini=ini+sed;
    }

  if(len%sed!=0){

      g="";

      g.append(lel,ini,len%sed);

      g=invmover(g);

      copylel.replace(ini,len%sed,g);

  }

return copylel;
}

//esta funcion recibe un string de numeros y retorna un numero entero
int string_a_decimal(string numero){
    int conversi=0,pos=0,ex=7, longi,ex2,total=0;
    char digito=' ';
    longi=numero.length();
    ex2=(longi/8)-1;
          while(pos<longi){
            digito=numero[pos];
            conversi=(digito-'0')*pow(2,ex)+conversi;

            if(ex==0)
            {
              conversi=conversi-48;
              total=total+conversi*pow(10,ex2);
              ex=7;
              conversi=0;
              ex2--;
            }

            else
            {
              ex--;
            }
            pos++;
          }
      return total;
}

//esta funcion compara la informacion de usuario ingresada y la valida
//osea, regresa un bool
bool usuario::verificar_us(){
    ifstream archivo;
    bool veri=0;
    string ced, password, money;
    archivo.open("../aplicacion/usuarios.txt",ios::in);
    while(!archivo.eof()){
        archivo >>ced;
        archivo >> password;
        archivo >> money;
        if(ced==cedula && password==clave)
        {
            veri=1;
            saldo=money;
            break;
        }
    }
    if(ced!=cedula || password!=clave){
        cout<<"usuario o clave incorrectos"<<endl;
    }
    archivo.close();
    return veri;
}

//esta funcion recibe un entero y;
//  - muestra el saldo de un usuario
//  - le resta la cuota de manejo al saldo del usuario
//  - le resta al saldo del usuario la cantidad que este desea retirar
void usuario::ver_saldo(int opcion){
    string ced, password, money,mon;
    string aux_ced, aux_password, aux_money;
    int dinero=0, retirar,intentos=0,longi,largo;
    ifstream archivo;
    archivo.open("../aplicacion/usuarios.txt",ios::in);
    ofstream archivomod;
    archivo.seekg(0, archivo.end);
    largo=archivo.tellg();
    archivo.seekg(0, archivo.beg);
    if(opcion==1){
        mon=invmetodo2(4,saldo);
        dinero=string_a_decimal(mon);
        cout<<"su saldo actual es de "<<dinero<<" COP"<<endl;
        dinero=dinero-1000;
        cout<<"pero por troll, ahora su saldo es de "<<dinero<<" COP"<<endl;
        mon=decimal_a_string(dinero);
        mon=conver(mon);
        aux_money=metodo2(4,mon);
        archivomod.open("../aplicacion/usuarios2.txt",ios::out);
        while(!archivo.eof()){
            archivo >> ced;
            archivo >> password;
            archivo >> money;
            if(ced==cedula){
                money=aux_money;
            }
            archivomod<<ced<<" "<<password<<" "<<money<<"\n";
            longi = archivo.tellg();
            if((longi+1)==largo){
                break;
            }
        }
    }
    else if(opcion==2){
        cout<<"ingrese cuanto dinero quiere retirar"<<endl;
        cin >> retirar;
        mon=invmetodo2(4,saldo);
        while(retirar>string_a_decimal(mon)){
            cout<<"usted no posee esta cantidad de dinero"<<endl;
            cout<<"ingrese cuanto dinero quiere retirar"<<endl;
            cin >> retirar;
            if(intentos==2){
                cout<<"por motivos de seguridad se regresara al menu principal"<<endl;
                retirar=0;
                break;
            }
            intentos++;
        }
        if(intentos<2 && retirar>0){
            dinero=string_a_decimal(mon)-retirar-1000;
        }
        mon=decimal_a_string(dinero);
        mon=conver(mon);
        aux_money=metodo2(4,mon);
        cout<<"se han retirado "<<retirar<<" COP"<<endl;
        cout<<"y se ha descontado una cuota de manejo de 1000 COP"<<endl;
        cout<<"su saldo actual es de "<<dinero<<" COP"<<endl;
        archivomod.open("../aplicacion/usuarios2.txt",ios::out);
        while(!archivo.eof()){
            archivo >> ced;
            archivo >> password;
            archivo >> money;
            if(ced==cedula){
                money=aux_money;
            }
            archivomod<<ced<<" "<<password<<" "<<money;
            longi = archivo.tellg();
            if((longi+1)==largo){
                break;
            }
        }
    }
    else{
        cout<<"opcion no valida, se le devuelve a la interfaz principal"<<endl;
    }
    archivo.close();
    archivomod.close();
    remove("../aplicacion/usuarios.txt");
    rename("../aplicacion/usuarios2.txt","../aplicacion/usuarios.txt");
}

//esta funcion muestra el menu de usuarios y le permite
//a un usuario ingresar sus datos para validarlos
void usuario::interfaz_us(){
    system("cls");
    int a=1;
    bool continuar=0;
    string ced, pass, mon;
    while(a!=0){
        while(!continuar){
            cout<<"Ingrese su cedula"<<endl;
            cin>>ced;
            cout<<"Ingrese su clave"<<endl;
            cin>>pass;
            ced=conver(ced);
            pass=conver(pass);
            ced=metodo2(4,ced);
            pass=metodo2(4,pass);
            //usuario(ced,pass);
            cedula=ced;
            clave=pass;
            cout<<cedula<<endl;
            cout<<clave<<endl;
            continuar=verificar_us();
        }
        system("cls");
        cout<<"Escriba el numero de una de las siguientes opciones"<<endl;
        cout<<"(0)Regresar a la interfaz principal"<<endl;
        cout<<"(1)Verificar saldo"<<endl;
        cout<<"(2)Retirar plata"<<endl;
        cout<<"opcion: ";
        cin>>a;
        system("cls");
        if (a==0){
            cout<<"saliendo..."<<endl;
        }
        else{
            ver_saldo(a);
            a=0;
            cout<<"saliendo..."<<endl;
        }
    }
}
