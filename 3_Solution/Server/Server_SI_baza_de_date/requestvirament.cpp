#include "requestvirament.h"
#include "requestvizualizare.h"
#include "requestlogin.h"
#include "DAL.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;
string extracttran(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}


string tranzactie(string input)
{
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);
	string verif;
	string copie;
	int id1 = stoi(extracttran(input));
	string id2 =(extracttran(input));

	
	

	int suma = stoi(extracttran(input));
	
	




		Tranzactii t1{ 0,id1,0,suma,"0"};
		if (db.createTranzactii(t1,id2)) {
			db.updatetranzactii();
			db.create10trans(id1);
			copie = "1";
		 }
		 else {
			copie = "0";
		}


		return copie;


}

void requestvirament::print(string v,string &r) const
{

	r=(tranzactie(v));
}
