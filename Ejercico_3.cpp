#include <iostream>
using namespace std;

const char *nombre_archivo="notas.dat";

void Crear();
void Actualizar();
void Leer();
void Borrar();

struct Estudiante{
	
	int id;
	char nombre[50];
	char apellidos[50];
	float nota[];	
};
float calcularpromedio(int nota[]){
	
	float suma =nota[0]+nota[1]+nota[2]+nota[3];
	float promedio = suma/4;
	return promedio;
}
main(){
	 int opcion;
    cout<<"1.------Crear--------"<<endl;
    cout<<"2.------Actualizar--------"<<endl;
    cout<<"3.------Leer--------"<<endl;
    cout<<"4.------Borrar--------"<<endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Opcion 1 seleccionada." << endl;
            Crear();
            break;
        case 2:
            cout << "Opcion 2 seleccionada." << endl;
            Actualizar();
            break;
       	 case 3:
            cout << "Opcion 3 seleccionada." << endl;
            Leer();
            break;
        case 4:
            cout << "Opcion 4 seleccionada." << endl;
            Borrar();
            break;
        default:
            cout << "Opcion no válida." << endl;
    }
	
		
	
	
	system("pause");
}
void Crear(){
	FILE* archivo=fopen(nombre_archivo,"a+b");
	char res;
	int nota[4];
	Estudiante  estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese le ID ";
		cin>>estudiante.id;
		cin.ignore();
		cout<<"Ingrese nombre ";
		cin.getline(estudiante.nombre,50);
		cout<<"Ingrese apellido ";
		cin.getline(estudiante.apellidos,50);
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
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea ingresar otro estudiante S/N ";
		cin>>res;
	}while(res=='s' || res=='S');
	Leer();
	fclose(archivo);
}

void Actualizar(){
	FILE* archivo=fopen(nombre_archivo,"r+b");
	Estudiante  estudiante;
	int id=0;
	int nota[4];
	cout<<"Ingrese la posicion del archivo que quiere actualizar "<<endl;
	cin>>id;
	id-1;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
		fflush(stdin);
		cout<<"Ingrese ID ";
		cin>>estudiante.id;
		cin.ignore();
		cout<<"Ingrese nombre ";
		cin.getline(estudiante.nombre,50);
		cout<<"Ingrese apellido ";
		cin.getline(estudiante.apellidos,50);
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
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	
	Leer();
	fclose(archivo);
	
}



void Leer(){
	system("cls");
	FILE* archivo=fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo=fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"_________________________________________________"<<endl;
	cout<<"id"<<"|"<<"ID"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"NOTA1"<<"|"<<"NOTA2"<<"|"<<"NOTA3"<<"|"<<"NOTA4"<<endl;
	do{
		
		cout<<id<<"|"<<estudiante.id<<"|"<<estudiante.nombre<<"|"<<estudiante.apellidos<<"|"<<estudiante.nota[1]<<"|"<<estudiante.nota[2]<<"|"<<estudiante.nota[3]<<"|"<<estudiante.nota[4]<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id += 1;
	}while(feof(archivo)==0);
	fclose(archivo);
	
}

void Borrar(){
const char *nombre_archivo_temp ="archivo2.dat";
FILE* archivo=fopen(nombre_archivo,"rb");
FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
Estudiante estudiante;
int id=0,id_n=0;
cout<<"Ingrese el id a borrar "<<endl;
cin>>id;

while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
	if(id_n!=id){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
	}
	id_n++;
}
fclose(archivo);
fclose(archivo_temp);
archivo=fopen(nombre_archivo,"rb");
archivo_temp=fopen(nombre_archivo_temp,"wb");
while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
}
fclose(archivo);
fclose(archivo_temp);
Leer();
}





