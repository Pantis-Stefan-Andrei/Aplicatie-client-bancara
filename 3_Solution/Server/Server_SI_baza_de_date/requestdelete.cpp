#include "requestdelete.h"
#include "requestregister.h"
#include "DAL.h"
#include <iostream>
#include <string>
using namespace std;
string extractdel(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}

string rdelete(string input)
{
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);
	string copie;
	int nr = stoi(extractdel(input));
	int nr2 = stoi(extractdel(input));
	
	if (nr == 1)
	{
		if (db.deleteConturi(nr2) == true)
			copie = "1";
		else
			copie = "0";
	}
	if (nr == 2)
	{
		
		if (db.deleteDEPOZITE(nr2) == true)
			copie = "1";
		else
			copie = "0";
	}
	if (nr == 3)
	{

		if (db.deleteIBANuri(nr2) == true)
			copie = "1";
		else
			copie = "0";
	}
	if (nr == 4)
	{


		if (db.deleteTranzactii(nr2) == true)
			copie = "1";
		else
			copie = "0";
		
	}
	if (nr == 5)
	{
		if (db.deleteamenzi(nr2) == true)
			copie = "1";
		else
			copie = "0";

		
	}
	if (nr == 6)
	{
		if (db.deleteCARDURI(nr2) == true)
			copie = "1";
		else
			copie = "0";



	}

	return copie;


}


void requestdelete::print(string v,string &r) const
{

	r=(rdelete(v));
}
