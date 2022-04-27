#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;	
using namespace System;

class Canciones
{
private:

	string titulo;
	string autor;
	float minutos;
	int indice;


public:

	Canciones() {}
	~Canciones() {}

	Canciones(string titulo, string autor)
	{
		
		minutos = rand() % 300 + 200;
		this->titulo = titulo;
		this->autor = autor;	
		

	}


	string gettitulo()
	{
		return titulo; 
	}

	template<typename T>
	void settitulo(T new_titulo)
	{
		titulo = new_titulo;
	}

	template<typename T>
	T getautor()
	{
		return autor;
	}

	void setautor(string newautor)
	{
		autor = newautor;
	}

	void cambiar_indice(int indice)
	{
		this->indice = indice;
	}



	void Mostrar_detalles()
	{
		
		auto fMinutos = [](float x) {return x = (x)/100; }(minutos);

		Console::SetCursorPosition(8,4+indice);
		cout << titulo;
		Console::SetCursorPosition(35,4+indice);
		cout << autor;
		Console::SetCursorPosition(63,4+indice);
		cout << fMinutos;
		


	}




};

