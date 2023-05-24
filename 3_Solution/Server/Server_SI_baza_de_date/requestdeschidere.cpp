#include "requestdeschidere.h"
#include "DAL.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
string extractiban(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}
string createiban() 
{
	string iban;
	const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int length = 16;
	std::string randomString;

	std::srand(std::time(nullptr)); 

	for (int i = 0; i < length; ++i) {
		int randomIndex = std::rand() % chars.length();
		randomString += chars[randomIndex];
	}
	string firstpart = "RO50";
	string secondpart = "RDPB";
	iban = firstpart + secondpart + randomString;

	return iban;

}

string criban(string input)
{
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);
	int ok = 0;
	
	string copie;
	string iban = createiban();
	int nr2 = stoi(extractiban(input));
	while (db.findIBANuri(iban) != false)
	{
		iban = createiban();
	}

	
	IBANuri i2{ 3,nr2,iban};
	 if (db.createIBANuri(i2)) {
		 copie = "1";
	 }
	 else {
		 copie = "0";
	 }
	

	return copie;



}

void requestdeschidere::print(string v, string &r) const
{

	r=(criban(v));
}
