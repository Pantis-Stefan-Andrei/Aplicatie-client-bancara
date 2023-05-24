#include "requestvizualizare.h"
#include "requestlogin.h"
#include "DAL.h"
#include <iostream>
#include <string>
using namespace std;
string extractnumber(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}

string vizualizare(string input)
{
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);
	int ok = 0;
	string verif,final;
	if (input.size() > 5)
		ok = 1;
	
	int nr2 = stoi(extractnumber(input));

	if (ok == 1)
		verif = extractnumber(input);
	
	db.getConturiBy(nr2, ok, verif,  final);
	

		

	return final;

}

void requestvizualizare::print(string v,string &r) const
{

	r=(vizualizare(v));
}
