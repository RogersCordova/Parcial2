#include <iostream>
using namespace std;

float calcularpromedio(int nota[]){
	
	float suma =nota[0]+nota[1]+nota[2]+nota[3];
	float promedio = suma/4;
	return promedio;
}


main(){
int id;
string nombre,apellidos;
int nota[4];	


	string x;
	do {
		cout<<"Ingresa el id del estudiante "<<endl;
		cin>>id;
		cout<<"Ingresa el nombre del estudiante "<<endl;
		cin>>nombre;
		cout<<"ingrese el apellido del estudiante "<<endl;
		cin>>apellidos;
		cout<<"ingrese las 4 notas del estudiante "<<endl;
			for(int i=0;i<4;i++){
			cout<<"Ingrese la nota "<<i+1<<endl;
			cin>>nota[i];
			}
			float promedio = calcularpromedio(nota);
			cout<<"El promedio del allunmo fue "<<promedio<<endl;
			
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
