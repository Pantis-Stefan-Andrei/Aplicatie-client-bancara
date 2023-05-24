#pragma once
#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <nanodbc.h>
#include "amenzi.h"
#include "CARDURI.h"
#include "Conturi.h"
#include "DEPOZITE.h"
#include "IBANuri.h"
#include "Tranzactii.h"
using namespace std;

class DAL {
private:
    nanodbc::connection conn;

    
public:
        DAL(const string connectionString) : conn(connectionString) {}
        ~DAL(){}
        bool createConturi(const Conturi& Conturi);
        bool getConturiBy(int id,int ok, string verif, string & final);
        string cautareid(const Conturi& Conturi);
        string create10trans(int id);
        bool updateConturi(const Conturi& Conturi);
        bool login( string l, string p,string &final);
        bool deleteConturi(int id);
        bool createTranzactii(const Tranzactii& Tranzactii,string & iban2);
        string getTranzactiiById( int id1, int suma, string iban);
        bool updateTranzactii(const Tranzactii& Tranzactii);
        bool updatetranzactii();
        bool deleteTranzactii(int id);
        bool createamenzi(const amenzi& amenzi);
        bool deleteamenzi(int id);
        bool createIBANuri(const IBANuri& IBANuri);
        IBANuri getIBANuriById(int id);
        bool updateIBANuri(const IBANuri& IBANuri);
        bool findIBANuri(string iban);
        bool deleteIBANuri(int id);
        bool createDEPOZITE(const DEPOZITE& DEPOZITE);
        DEPOZITE getDEPOZITEById(int id);
        bool updateDEPOZITE(const DEPOZITE& DEPOZITE);
        bool deleteDEPOZITE(int id);
        bool createCARDURI(const CARDURI& CARDURI);
        CARDURI getCARDURIById(int id);
        bool updateCARDURI(const CARDURI& CARDURI);
        bool deleteCARDURI(int id);
        void disconnect();
        //vector<amenzi> getamenzisByEmail(const std::string& email);
};

