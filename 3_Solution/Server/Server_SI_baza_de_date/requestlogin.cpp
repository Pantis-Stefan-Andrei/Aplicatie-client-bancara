#include "requestlogin.h"
#include "DAL.h"
#include <iostream>
#include <string>
using namespace std;
string extractlog(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}

string login(string input)
{
	string copie;
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);

	string user = extractlog(input);
	string pass = extractlog(input);
	
	if (db.login( user, pass,copie))
		cout << "logare cu succes!";
	else
	{
		cout << "logare fara succes!";
		copie = "0";
	}
	db.disconnect();
	return copie;

	
}

void requestlogin::print(string v,string &r) const
{

		r=(login(v));
}
