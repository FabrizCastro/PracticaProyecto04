#pragma once
#include "Canciones.h"

class Playlist
{
private :

	int n;
	Canciones** arreglo;

public :

	Playlist()
	{
		
		n = 0;
		arreglo = new Canciones*[n];

	}

	~Playlist()
	{

	}

	template<typename T>
	void Insertarcancion(T m)
	{
		Canciones** auxiliar = new Canciones * [n + 1];

		for (int i = 0; i < n; i++)
		{
			auxiliar[i] = arreglo[i];
		}

		auxiliar[n] = m;
		[=](int a) {n = n + a; }(1); //lambda

		arreglo = auxiliar;

	}

	void Mostrar_playlist()
	{
		Console::SetCursorPosition(8, 2);
		cout << "Cancion";
		Console::SetCursorPosition(35, 2);
		cout << "Autor";
		Console::SetCursorPosition(63, 2);
		cout << "Duración";
		cout << "\n";

		for (int i = 0; i < n; i++)
		{
			arreglo[i]->cambiar_indice(i);
			arreglo[i]->Mostrar_detalles();

		}
	}

	void Eliminar_enposicion(string nombre)// nombredela cancion para eliminarla
	{
		Canciones** auxiliar;
		auxiliar = new Canciones * [n - 1];

		int indice;
		bool finded = false;

		for (int i = 0; i < n; i++)
		{
			if (arreglo[i]->gettitulo() == nombre)
			{
				indice = i;
				finded = true;
			}
		}

		if (finded == false)
		{
			cout << "No se encontró la canción en la PlayList :( ";
		}

		for (int i = 0; i < indice; i++)
		{
			auxiliar[i] = arreglo[i];
				
		}
		for (int i = indice; i <n; i++)
		{
			auxiliar[i] = arreglo[i + 1];
		}

		if (finded == true)
		{
			cout << "La canción se ha eliminado correctamente :) ";
		}



		n = n-1;
		arreglo = auxiliar;



	}

	int retonar_n()
	{
		return n;
	}


};

