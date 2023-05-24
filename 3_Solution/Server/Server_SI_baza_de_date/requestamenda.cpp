#include "requestamenda.h"
#include "DAL.h"
#include <iostream>
#include <string>
using namespace std;
string extractamenda(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}

string amenda(string input)
{
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);
	
	string nume = extractamenda(input);
	if (nume == "~")
	{
		int id2 = stoi(extractamenda(input));
		if (db.deleteamenzi(id2)) {
			return "1";
		}
		else {
			return "0";
		}
	}
	string descriere = extractamenda(input);
	string data_primirii = extractamenda(input);
	int id = stoi(extractamenda(input));
	int valoare = stoi(extractamenda(input));


	amenzi a1{ 0,nume,descriere,data_primirii,id ,valoare};
	if (db.createamenzi(a1)) {
		return "1";
	}
	else {
		return "0";
	}
	



}

void requestamenda::print(string v,string &r) const
{

	r=(amenda(v));
}
