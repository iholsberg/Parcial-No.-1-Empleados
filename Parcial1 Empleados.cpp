#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
int menu(){
	int x;
	system("cls");

	cout<<"--------Welcome--------"<<endl<<endl;
	cout<<"1.Empleado a Ingresar: "<<endl;
	cout<<"2.Empleado a Verificar: "<<endl;
	cout<<"3.Empleado a Buscar: "<<endl;
	cout<<"4.Empleado a Modificar: "<<endl;
	cout<<"5.Empleado a Eliminar: "<<endl;
	cout<<"6.Exit "<<endl;
	cout<<"-----------------------"<<endl;
	cout<<"Selecione la Opcion a Utilizar: ";
	cin>>x;
	return x;
	
}

bool verificacion(string ID){
 ifstream leer ("archivo.dat", ios::in);
 string Id;
 string nom;
 string Ape;
 string pues;
 int suel;
 int boni;
 int suma;
 leer>>ID;
 while(!leer.eof()){
  leer>>Ape;
  leer>>nom;
  leer>>pues;
  leer>>suel;
  leer>>boni;
  leer>>suma;
  if(ID == ID){
   cout<<"\n\n\tError: Registro se Encuentra Duplicado.\n\n";
   system("pause");
   leer.close();
   return false;
  }
  leer>>ID;
 }
   leer.close();
   return true; 
}
void Ingresar_Dato(ofstream &es) {
	system("cls");
	string ID;
	string Ape;
	string nom;
	string pues;
	int suel;
	int boni;
	int suma;
	es.open("archivo.dat", ios::out| ios::app);
	cout<<"ID: ";
	cin>>ID;
	cout<<"Apellido: ";
	cin>>Ape;
	cout<<"Nombre: ";
	cin>>nom;
	cout<<"Puesto: ";
	cin>>pues;
	cout<<"Sueldo: ";
	cin>>suel;
	cout<<"Bonificacion: ";
	cin>>boni;
	suma = suel + boni;
	cout<<"La totalidad del sueldo es:  "<<suma<<endl;
	
	if(verificacion(ID))
		es<<ID<<" "<<Ape<<" "<<nom<<" "<<pues<<" "<<suel<<" "<<boni<<" "<<suma<<"\n";
	es.close();
	}

void Verificar_Registros(ifstream &Lec){
	system("cls");
	string Id;
 	string nom;
 	string Ape;
 	string pues;
 	int suel;
 	int boni;
 	int suma;
 	Lec.open("archivo.dat", ios::in);
 	if(Lec.is_open()){
	 	cout<<"-------Registro Almancenado-------"<<endl<<endl;
	 	Lec>>Id;
	 	while(!Lec.eof()){
			Lec>>Ape;
			Lec>>nom;
			Lec>>pues;
			Lec>>suel;
			Lec>>boni;
			Lec>>suma;
			cout<<"-ID: "<<Id<<endl;
			cout<<"-Nombre: "<<nom<<endl;
			cout<<"-Apellido: "<<Ape<<endl;
			cout<<"-Puesto: "<<pues<<endl;
			cout<<"-Sueldo: "<<suel<<endl;
			cout<<"-Bonificacion: "<<boni<<endl;
			cout<<"-Sueldo a Recibir: "<<suma<<endl;
			cout<<"----------------------"<<endl;
			Lec>>Id;
		 }
		 Lec.close();
	}else
		cout<<"Error"<<endl;
	 system("pause");
}



void Buscar_El_Dato(ifstream &Lec){
	system("cls");
	Lec.open("registro.dat", ios::in);
	string ID, Ape, nom, pues, IDaux;
	int suel, boni, suma;
	bool encontrado = false;
	cout<<"Digite la ID: ";
	cin>>IDaux;
	Lec>>ID;
	while(! Lec.eof() && !encontrado){	
		Lec>>ID;
		Lec>>Ape;
		Lec>>nom;
		Lec>>pues;
		Lec>>suel;
		Lec>>boni;
		Lec>>suma;
		if(ID == IDaux){
			cout<<"ID: "<<ID<<endl;
			cout<<"Nombre: "<<nom<<endl;
			cout<<"Apellido: "<<Ape<<endl;
			cout<<"Puesto: "<<pues<<endl;
			cout<<"Sueldo: "<<suel<<endl;
			cout<<"Bonificacin: "<<boni<<endl;
			cout<<"Sueldo Total: "<<suma<<endl;
			cout<<"----------------------"<<endl;
			encontrado = true;
		}	
		Lec>>ID;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"No Existe"<<endl<<endl;
	system("pause");
}

void Modificar_Texto(ifstream &Lec){
	system("cls");
 	string Ape;
 	string ID;
	string nom;
	string pues;
	int suel;
	int boni;
	int suma;
	string IDaux;
	string Apeaux;
	string nomaux;
	string puesaux;
	int suelaux;
	int boniaux;
	int sumaux;
	Lec.open("archivo.dat", ios::in);
	ofstream aux("auxiliar.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Dato a Modificar--------------------"<<endl;
		cout<<"Ingrese dato ID:  ";
		cin>>IDaux;
		Lec>>ID;
		while(!Lec.eof()){
		  	Lec>>Ape;
			Lec>>nom;
			Lec>>pues;
			Lec>>suel;
			Lec>>boni;
			if(ID == IDaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese el apellido: ";
				cin>>Apeaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese el Nombre: ";
				cin>>nomaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingres el Puesto: ";
				cin>>puesaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese el Sueldo: ";
				cin>>suelaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese la bonificacion: ";
				cin>>boniaux;
			
				sumaux = suelaux + boniaux;
				aux<<ID<<" "<<Apeaux<<" "<<nomaux<<" "<<puesaux<<" "<<suelaux<<" "<<boniaux<<" "<<sumaux<<"\n";
				cout<<"--------------------------------------"<<endl;
			}else{
				suma = suel + boni;
				aux<<ID<<" "<<Ape<<" "<<nom<<" "<<pues<<" "<<suel<<" "<<boni<<" "<<suma<<"\n";
			}
			
			
			Lec>>ID;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
		
	}else 
		cout<<"Error"<<endl;
	remove ("archivo.dat");
	rename("auxiliar.dat", "archivo.dat");
}

void Eliminar_Registro(ifstream &Lec){
	system("cls");
 	string Ape;
 	string ID;
	string nom;
	string pues;
	int suel;
	int boni;
	int suma;
	string IDaux;
	string Apeaux;
	string nomaux;
	string puesaux;
	int suelaux;
	int boniaux;
	int sumaux;
	Lec.open("archivo.dat", ios::in);
	ofstream aux("auxiliar.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------ID a Modificar--------------------"<<endl;
		cout<<"Ingrese id:  ";
		cin>>IDaux;
		Lec>>ID;
		while(!Lec.eof()){
		  	Lec>>Ape;
			Lec>>nom;
			Lec>>pues;
			Lec>>suel;
			Lec>>boni;
			Lec>>suma;
			if(ID == IDaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"------Existosamente ha Sido Eliminado-----"<<endl;
				Sleep(1500);
				cout<<"--------------------------------------"<<endl;
			}else{
				aux<<ID<<" "<<Ape<<" "<<nom<<" "<<pues<<" "<<suel<<" "<<boni<<" "<<suma<<"\n";
				
			}
			
			Lec>>ID;
			Lec>>nom;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"Error"<<endl;
	remove ("archivo.dat");
	rename("auxiliar.dat", "archivo.dat");	
	
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		
		system("cls");
		op = menu();
		switch(op){
			case 1:
				Ingresar_Dato(Esc);
			break;
			case 2:
				Verificar_Registros(Lec);
			break;
			case 3:
				Buscar_El_Dato(Lec);
			break;
			case 4:
				Modificar_Texto(Lec);
			break;
			case 5:
				Eliminar_Registro(Lec);
			break;	
		}	
	}while(op != 6);
	return 0;
}
