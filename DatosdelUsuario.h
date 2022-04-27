#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
 
using namespace std;



template<typename T>
class DatosdelUsuario
{
private:

	T* arreglo;
	int cantidad;
	int tam;//tamanio

public:

	DatosdelUsuario();
	~DatosdelUsuario();
	
	void set_tam(int nuevo);
	void Agregardatos(const T& obj);
	T& get(int indice);
	void set_arreglo(int indice, T obj);
	
};

template <typename T>
void DatosdelUsuario<T> ::set_tam(int nuevo)
{
	tam = nuevo;
	arreglo = new T[tam];
}



template <typename T>
DatosdelUsuario<T>::DatosdelUsuario()
{	
	tam = 0;
	cantidad = 0;
	//arreglo = new T();
}
template <typename T>
DatosdelUsuario<T>::~DatosdelUsuario()
{

}

template <typename T>
void DatosdelUsuario<T>::Agregardatos(const T& obj)
{	
#pragma region
	/*T* auxiliar = new T[cantidad + 1];

	for (int i = 0; i < cantidad; i++)
	{
		auxiliar[i] = arreglo[i];
	}

	auxiliar[cantidad] = obj;

	cantidad = cantidad + 1;
	
	/*if (cantidad < tam)
	{
		arreglo[cantidad++] = obj;

	}

	arreglo = auxiliar;*/
#pragma endregion

	if (cantidad < tam)
	{
		arreglo[cantidad++] = obj;
	}

}

template<class T>
T& DatosdelUsuario<T>::get(int indice)
{
	return arreglo[indice];
}

template<class T>
void DatosdelUsuario<T>::set_arreglo(int indice, T obj)
{	
	arreglo[indice] = obj;

}
