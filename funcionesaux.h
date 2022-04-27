
#include<iostream>
#include<vector>
#include "BasedeDatos.h"
using namespace std;

vector<string> split(string str, string separador)
{
	int posInit = 0;
	int posFound = 0;
	string splitted;
	vector<string> results;

	while (posFound >= 0) {
		posFound = str.find(separador, posInit);
		splitted = str.substr(posInit, posFound - posInit);
		posInit = posFound + 1;
		results.push_back(splitted);
	}

	return results;
}