#include "requestregister.h"
#include "requestdeschidere.h"
#include "requestcard.h"
#include <iostream>
#include <string>
using namespace std;
string extract(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}

string inregistrare(string input)
{
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);
	string copie;
	string nume = extract(input);
	if (nume == "~")
	{
		int suma = stoi(extract(input));
		int id_client= stoi(extract(input));
		DEPOZITE dd{0,suma,0,id_client};
		if(db.createDEPOZITE(dd))
		{
			copie = "1";
		}
		else
		{
			copie = "0";
		}
	}
	else
	{
		string prenume = extract(input);
		string cnp = extract(input);
		string user = extract(input);
		string pass = extract(input);
		string nr_t = extract(input);
		string email = extract(input);

		Conturi c2{ 1,nume,prenume,cnp,user,pass,nr_t,email };
		string v;
		v = "_";
		if (db.createConturi(c2))
		{
			copie = "1";
			cout << "inregistrare cu succes!";
		}
		else
		{
			copie = "0";
			cout << "inregistrare fara succes!";
		}
		if (copie == "1")
		{
			string r;
			requestdeschidere a;
			requestcard card;
			v = v + db.cautareid(c2);
			a.print(v, r);
			card.print(v, r);
		}
	}

	db.disconnect();
	return copie;

}


void requestregister::print(string v,string &r) const
{

	r=(inregistrare(v));
	
}
