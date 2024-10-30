#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct data
{
char id_registro[50];
char nombre[30];
char cedula[10];
int edad;
float peso;
float altura;
string genero;
};
int main(){
int number_persons;
cout <<"ingrese el numero de personas: ";
cin>> number_persons;
data personas [number_persons];
 for (int i = 0; i < number_persons; i++)
    { cout<< "persona: "<< i+1<<".\n";
      cout<< "id de registo: ";
      cin>>personas[i].id_registro;
      cout<< "Nombre: ";
      cin.ignore();
      cin.getline(personas[i].nombre,50);
      cout<< "Cedula: ";
      cin.getline(personas[i].cedula,20);
      cout<< "Edad: ";
      cin>>personas[i].edad;
      cout<< "Peso: ";
      cin>>personas[i].peso;
      cout<< "Altura: ";
      cin>>personas[i].altura;
      cout<< "Genero Masculino o Femenino: ";
      cin>>personas[i].genero;
      cin.ignore(100,'\n');
 }

 fstream codigo_binario("persona.dat", ios::out | ios::binary); 
 if(codigo_binario.is_open())
 { 
    codigo_binario.write(reinterpret_cast<char*>(personas),number_persons*sizeof(data));
    codigo_binario.close();
    cout<< "datos guardados en el arch: personas.dat \n";
 } else{
    cout << "no se pudo abrir el arch: ";

delete[]personas;
return 0;
 }
}