#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct data
{int id_registro;
char nombre[35];
char cedula[9];
int edad;
float peso;
float altura;
string genero;
};
int main(){
int number_persons;
cout <<"ingrese el numero de persoas:";
cin.ignore();
cin>> number_persons;
data personas [number_persons];
 for (int i = 0; i < number_persons; i++)
    { cout<< "persona"<< i+1<<".\n";
      cout<< "id de; registo";
      cin>>personas[i].id_registro;
      cout<< "nombre"<< endl;
      cin.getline(personas[i].nombre,35);
      cout<< "cedula"<< endl;
      cin.getline(personas[i].cedula,9);
      cout<< "edad";
      cin>>personas[i].edad;
      cout<< "peso";
      cin>>personas[i].peso;
      cout<< "altura";
      cin>>personas[i].altura;
      cout<< "genero Masculino o Femenino";
      cin>>personas[i].genero;
 }

 fstream codigo_binario("persona.dat", ios::out | ios::binary); 
 if(codigo_binario.is_open())
 { 
    codigo_binario.write(reinterpret_cast<char*>(personas),number_persons*sizeof(data));
    codigo_binario.close();
    cout<< "datos guardados en el arc: personas.dat \n";
 } else{
    cout << "no se pudo abri el arc";

delete[]personas;
return 0;
 }
}
