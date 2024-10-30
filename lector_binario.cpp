#include<iostream>
#include<fstream>
using namespace std;

struct data{

char id_registro[50];
char nombre[30];
char cedula[10];
int edad;
float peso;
float altura;
char genero;
};

int main(){
fstream codigo_binario("persona.dat", ios::out | ios::binary);
if (codigo_binario.is_open()){
    cout<< 'No se puede abrir el archivo personas.dat \n';
    return 1;
}
codigo_binario.seekg(0, ios::end);
int fileSize = codigo_binario.tellg();
codigo_binario.seekg(0,ios::beg);
int number_persons = fileSize / sizeof(data);
data*personas = new data[number_persons];
codigo_binario.read(reinterpret_cast<char*>(personas), fileSize);
codigo_binario.close();

for(int i =0; i < number_persons; i++){

cout<<"Persona" << i+1 << ":\n";
cout << "id_de_registro: "<<personas[i].id_registro<<"\n";
cout << "Nombre: "<<personas[i].nombre<<"\n";
cout << "Cedula: "<<personas[i].cedula<<"\n";
cout << "Edad: "<<personas[i].edad<<"\n";
cout << "Peso: "<<personas[i].peso<<"\n";
cout << "Altura: "<<personas[i].altura<<"\n";
cout << "Genero: "<<personas[i].genero<<"\n";
cin.ignore(100,'\n');
}
delete[]personas;
return 0;
}