#include <iostream>
#include <conio.h>
#include <windows.h> 
#include <locale.h>
#include "DatosdelUsuario.h"
#include "BasedeDatos.h"
#include <string>
#include "Playlist.h"

using namespace std;
using namespace System;

void Logo() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout << "\n";
	int logo[20][40] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

	for (int i = 0; i < 20; i++)
	{
		Console::SetCursorPosition(42, i+3);
		for (int j = 0; j < 40; j++)
		{
			if (logo[i][j] == 1)cout << char(220);
			else cout << " ";
		}
		cout << endl;
	}
	_sleep(500);
	Console::SetCursorPosition(53, 18);
	cout << "E X Í G E T E." << "\n";
	_sleep(750);
	Console::SetCursorPosition(54, 19);
	cout << "I N N O V A." << "\n";
	_sleep(750);
	Console::SetCursorPosition(57, 20);
	cout << "U P C" << "\n";
}

template<typename T>
bool Verificar(DatosdelUsuario<string>deseo, T tam,T &it)
{
	string n;		
	cin>>n;
	if ([&](string x)
		{
			for (int i = 0; i < tam; i++)
			{
				if (x==deseo.get(i))
				{
					it = i;
					return true;
				}
			}

		}(n)) return true;//n == deseo) return n;
	else
	{
		cout << "Nombre incorrecto ingrese otro por favor:"<<endl;
		return Verificar(deseo,tam,it);
	}
}

void Menu()
{
	cout << "---Menú---\n";
	cout << "1: Ingresar Datos del cliente : \n";
	cout << "2: Perfil del usuario         : \n";
	cout << "3: Búsqueda de canciones      : \n";
	cout << "4: Agregar canción a mi Playlist : \n";
	cout << "5: Eliminar canción de mi Playlist : \n";
	cout << "6: Mostrar Playlist : \n";
	cout << "x: Cerrar sesión.\n";
}
	

void Imprimir_datos(int tam,DatosdelUsuario<string> objNombre, DatosdelUsuario<int> objEdad, DatosdelUsuario<int> objDNI, DatosdelUsuario<string> objSexo)
{
	cout << "\n";
	cout << "Nombre(s) de Usuario(s)     Edad de Usuario      DNI de Usuario      Sexo de Usuario\n";
	for (int i = 0; i < tam; i++)
	{
		Console::SetCursorPosition(8, 3+i);
		cout << objNombre.get(i); 
		Console::SetCursorPosition(33, 3+i);
		cout << objEdad.get(i);
		Console::SetCursorPosition(53, 3+i);
		cout << objDNI.get(i); 
		Console::SetCursorPosition(74, 3+i);
		cout << objSexo.get(i);
		cout << endl;
		
	}	 	
}


void Imprimiento_perfil(DatosdelUsuario<string> obj_preferencias, int indice, string nuevo_nombre)
{
	
	cout << "\nPerfil de : " << nuevo_nombre<<endl;
	cout << "Generos de música preferidos : " << obj_preferencias.get(indice) << endl;
	cout << "\n";
}





int main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "Spanish");
	//1
	string nombre;
	
	int edad;
	int DNI;
	string sexo;
	int tam = 0;
	DatosdelUsuario<string>objNombre;
	DatosdelUsuario<int>objEdad;
	DatosdelUsuario<int>objDNI;
	DatosdelUsuario<string>objSexo;
	int veces = 1;

	//2
	int i;
	string nuevo_nombre;
	string preferencias;

	DatosdelUsuario<string>objpreferencias;
	int indice = 0;

	string DatosUsuario;
	BasedeDatos* objarchivo = new BasedeDatos();

	//3 
	string cancion;


	//4
	Playlist* arr = new Playlist();
	string nombre_cancion;
	string nombre_autor;

	//5
	string nombre_cancion_eliminar;


	string autor = "flow";
	char opcion;

	Logo();
	_sleep(2700);
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	do
	{
		do
		{
			Menu();
			cin >> opcion;
			opcion = tolower(opcion);

		} while (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4' && opcion != '5' && opcion != '6' && opcion != 'x');

		if (opcion != 'x')
		{
			switch (opcion)
			{
			case '1':

				cout << "Ingresa el numeros de usuarios a ingresar : ";
				cin >> tam;

				objNombre.set_tam(tam);
				objEdad.set_tam(tam);
				objDNI.set_tam(tam);
				objSexo.set_tam(tam);

				while (veces <= tam)
				{
					DatosUsuario = "";
					cout << "Ingresa el nombre : ";
					cin >> nombre;
					objNombre.Agregardatos(nombre);


					do
					{

						cout << "Ingresa la edad   : ";
						cin >> edad;

					} while (edad < 5 || edad >= 100);
					objEdad.Agregardatos(edad);

					do
					{

						cout << "Ingresa el DNI    : ";
						cin >> DNI;
					} while (DNI <= 10000000 || DNI >= 100000000);
					objDNI.Agregardatos(DNI);


					cout << "Ingresa el sexo   : ";
					cin >> sexo;
					objSexo.Agregardatos(sexo);

					cout << endl;

					//almacenar datos
					DatosUsuario = DatosUsuario + nombre + " " + to_string(edad) + " " + to_string(DNI) + " " + sexo;
					objarchivo->EscribirDatosUsuarios(DatosUsuario);

					veces++;
				}

				system("cls");
				Imprimir_datos(tam, objNombre, objEdad, objDNI, objSexo);

				system("pause");
				system("cls");

				break;


			case '2':

				cout << "Hola, ¿Cuál es tu nombre? "; 

				
					if (Verificar(objNombre,tam,i))
					{
						cout << " Hola " << objNombre.get(i) << " con DNI : " << objDNI.get(i);
						indice = i;
						cout << "\n";
					}

				


				cout << "¿Cuáles son tus géneros preferidos? (Separalos con un \"-\") : ";
				cin >> preferencias;

				objpreferencias.set_tam(tam);
				objpreferencias.set_arreglo(indice, preferencias);


				Imprimiento_perfil(objpreferencias, indice, objNombre.get(i));
				system("pause");
				system("cls");

				break;


			case '3':

				system("cls");
				cout << "Ingresa cancion"<<endl;
				cin.ignore();
				getline(cin,cancion);
				cout << objarchivo->LeerCanciones(cancion)<<endl;
				system("pause");
				system("cls");

				break;

			case '4': // Agrega
				system("cls");
				cout << "¿Qué hay de nuevo " << nuevo_nombre << " ?\n";
				cout << "Ingresa la cancion que quieres agregar a tu playlist :) : \n";
				cin.ignore();
				getline(cin, nombre_cancion);

				// Comprobando si la canción existe dentro de la base de datos : 
				cout<<objarchivo->LeerCanciones(nombre_cancion)<<endl;

				if (objarchivo->retornar_cancion())
				{
					autor = objarchivo->retornar_autor();

					arr->Insertarcancion(new Canciones(nombre_cancion, autor));
					cout << "Se añadió la cancion a la Playlist\n";

				}

			

				
				system("pause");
				system("cls");
				
				break;


			case '5': // Elimina

				system("cls");
				cout << "Ingresa el nombre de la canción para eliminar de la PlayList : ";
				cin.ignore();
				getline(cin, nombre_cancion_eliminar);
				arr->Eliminar_enposicion(nombre_cancion_eliminar);
				system("pause");
				system("cls");
				
				break;	


			case '6': //Muestra

				system("cls");
				cout << "Playlist de " << nuevo_nombre << " tiene "<<arr->retonar_n()<< " canciones "<<endl;
				arr->Mostrar_playlist();
				cout << endl;
				system("pause");
				system("cls");
				break;
			}





		}

	} while (opcion != 'x');




	system("pause");
	return 0;

}