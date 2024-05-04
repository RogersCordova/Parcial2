#include <iostream>
using namespace std;

struct Estudiante{
	int id;
    string nombre;
    string apellido;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
	
};


main(){
	float *nota1,*nota2,*nota3,*nota4;
	Estudiante e;
	nota1 = &e.nota1;
	nota2 = &e.nota2;
	nota3 = &e.nota3;
	nota4 = &e.nota4;

	
string x;
	 do{
	 	cout<<"ingresa el nombre del alumno"<<endl;
	 	cin>>e.id;
	 	cout<<"ingresa el nombre del alumno"<<endl;
	 	cin>>e.nombre;
	 	cout<<"ingresa el apellido del alumno"<<endl;
	 	cin>>e.apellido;
	 	cout<<"ingresa la nota 1 del alumno"<<endl;
	 	cin>>e.nota1;
	 	cout<<"ingresa la nota 2 del alumno"<<endl;
	 	cin>>e.nota2;
	 	cout<<"ingresa la nota 3 del alumno"<<endl;
	 	cin>>e.nota3;
	 	cout<<"ingresa la nota 4 del alumno"<<endl;
	 	cin>>e.nota4;
		float suma;
		suma = *nota1+*nota2+*nota3+*nota4;
		float promedio;
		promedio = suma/4;
		cout<<"El promedio es "<<promedio<<endl;
			if (promedio>60){
				cout<<"Aprobado"<<endl;
			}else{
				cout<<"No aprobado"<<endl;
			}
		cout<<"Quieres agregar otro alunmo S/N "<<endl;
		cin>>x;
		
	} while (x == "s" || x =="S" );
	
		
	
	
system("pause");	
}
