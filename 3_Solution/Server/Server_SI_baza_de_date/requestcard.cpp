#include "requestcard.h"
#include "DAL.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
using namespace std;
string extractidcont(string& input)
{
	size_t firstUnderscore = input.find("_");
	size_t secondUnderscore = input.find("_", firstUnderscore + 1);
	std::string extractedString = input.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
	input.erase(firstUnderscore, secondUnderscore - 1);
	return extractedString;
}





std::string generateCardNumber()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, 9);

    std::string cardNumber;
    for (int i = 0; i < 16; ++i)
    {
        cardNumber += std::to_string(dis(gen));

        if ((i + 1) % 4 == 0 && i < 15)
            cardNumber += " ";
    }

    return cardNumber;
}


std::string generateCVV()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(100, 999);

    return std::to_string(dis(gen));
}







string createcard(string input)
{
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";
	DAL db(connection_string);
	int ok = 0;

	int id = stoi(extractidcont(input));

    std::srand(static_cast<unsigned int>(std::time(nullptr)));


    std::string cardNumber = generateCardNumber();


    std::string cvv = generateCVV();
    CARDURI card{0,cvv,cardNumber,"21/5/2028",id};
    if (db.createCARDURI(card))
    {
        return "1";
    }
    else
        return "0";

}

void requestcard::print(string v, string& r) const
{

	r = (createcard(v));
}
