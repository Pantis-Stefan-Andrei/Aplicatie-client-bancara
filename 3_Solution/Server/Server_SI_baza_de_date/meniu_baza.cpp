#include "meniu_baza.h"
#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <odbcss.h>
#include "DAL.h"
#include "getter.h"
#include "Factory.h"
#include <string>
using namespace std;
using namespace FactoryRequest;


string meniu_baza::deschidere(string buf){
	std::string connection_string = "Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=POO;Trusted_Connection=yes;";

	DAL db(connection_string);
	//string val="1_Cortel_Vulcanizare_5023738299_Cortel.Vulcanizare_1234_0721312321_asdasd@yahaoo.com_civil_500_0_";
	string val = buf;
	//string val = "2_1_";
	//string val = "2_1_2_";
	//string val = "2_2_2_";
	//string val = "4_3_2_";
	//string val = "3_8_9_500_adasdsa12wda_";
	//string val = "6_trecere-pietoni_calacat o persoana_5/16/2023_2_";
	//string val = "7_4_";
	getter var;
	string raspuns;
	int first_n = var.getfirstnumber(val);
	if (first_n == 1)
	{
		//inregistrare(val, db);
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::inregistrare);
		R1->print(val, raspuns);

	}
	else if (first_n == 2)
	{
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::vizualizare);
		R1->print(val, raspuns);
	}
	else if (first_n == 3)
	{
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::virament);
		R1->print(val, raspuns);
	}
	else if (first_n == 4)
	{
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::rdelete);
		R1->print(val, raspuns);
	}
	else if (first_n == 5)
	{
		//login(val,db);
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::login);
		R1->print(val, raspuns);
	}
	else if (first_n == 6)
	{
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::amenda);
		R1->print(val, raspuns);
	}
	else if (first_n == 7)
	{
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::deschidere);
		R1->print(val, raspuns);
	}
	else if (first_n == 8)
	{
		irequest* R1 = FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest::card);
		R1->print(val, raspuns);
	}

	return raspuns;

	
}


