#include "DAL.h"
#include "LinkedList.h"
#include <random>

bool DAL::createCARDURI(const CARDURI& CARDURI) {
    try {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, "INSERT INTO CARDURI(CVV,nr_card,data_expirare,id_cont) VALUES (?,?, ?,?);");


        stmt.bind(0, CARDURI.CVV.c_str());
        stmt.bind(1, CARDURI.nr_card.c_str());
        stmt.bind(2, CARDURI.data_expirari.c_str());
        stmt.bind(3, &CARDURI.id_cont);
     
        stmt.execute();
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}



bool DAL::deleteCARDURI(int id) {
    try {
    nanodbc::statement stmt(conn);
    nanodbc::prepare(stmt, R"(
            DELETE FROM CARDURI WHERE id_card= ?;
        )");

    stmt.bind(0, &id);

    nanodbc::result rez = stmt.execute();

    return rez.has_affected_rows();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}




/// //////////////////////////////////// //////////////////////////////////// /////////////////////////////////



bool DAL::createDEPOZITE(const DEPOZITE& DEPOZITE) {
    try {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, "INSERT INTO DEPOZITE(suma,id_cont) VALUES (?, ?);");


        stmt.bind(0, &DEPOZITE.suma);

        stmt.bind(1, &DEPOZITE.id_cont);
       
        stmt.execute();
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}



bool DAL::deleteDEPOZITE(int id) {
   try{
    nanodbc::statement stmt(conn);
    nanodbc::prepare(stmt, R"(
            DELETE FROM DEPOZITE WHERE id_depozit= ?;
        )");

    stmt.bind(0, &id);

    nanodbc::result rez = stmt.execute();


    return rez.has_affected_rows();
   }
   catch (const std::exception& e) {
       std::cerr << e.what() << '\n';
       return false;
   }
}




/// //////////////////////////////////// //////////////////////////////////// /////////////////////////////////


bool DAL::createIBANuri(const IBANuri& IBANuri) {
    try {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, "INSERT INTO IBANuri(id_cont,iban) VALUES (?, ?);");

       
   
        stmt.bind(0, &IBANuri.id_cont);
        stmt.bind(1, IBANuri.iban.c_str());
        stmt.execute();
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}



bool DAL::findIBANuri(string iban)
{
    try {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, "SELECT * FROM IBANuri WHERE iban = ?;");

        stmt.bind(0, iban.c_str());
        

        stmt.execute();
       
            nanodbc::result rez = stmt.execute();
            if (rez.next())
                return true;
            else
                return false;

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}


bool DAL::deleteIBANuri(int id) {
   try{
       nanodbc::statement stmt(conn);
    nanodbc::prepare(stmt, R"(
            DELETE FROM IBANuri WHERE id_iban = ?;
        )");

    stmt.bind(0, &id);

    nanodbc::result rez = stmt.execute();

    return rez.has_affected_rows();
   }
   catch (const std::exception& e) {
       std::cerr << e.what() << '\n';
       return false;
   }
}




/// //////////////////////////////////// //////////////////////////////////// /////////////////////////////////



bool DAL::createConturi(const Conturi& Conturi) {
    try {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, "INSERT INTO Conturi(nume, prenume, cnp, username, parola, nr_telefon, email) VALUES (?, ?, ?, ?, ?, ?, ?);");

        stmt.bind(0, Conturi.nume.c_str());
        stmt.bind(1, Conturi.prenume.c_str());
        stmt.bind(2, Conturi.cnp.c_str());
        stmt.bind(3, Conturi.username.c_str());
        stmt.bind(4, Conturi.parola.c_str());
        stmt.bind(5, Conturi.nr_telefon.c_str());
        stmt.bind(6, Conturi.email.c_str());

        stmt.execute();
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}


string DAL::create10trans(int id_c)
{try{
    LinkedList list;

    string final;
        nanodbc::statement stmt(conn);

         nanodbc::prepare(stmt, R"(



SELECT *
FROM Tranzactii AS T
INNER JOIN IBANuri as I
ON I.id_iban=T.id_iban1
INNER JOIN IBANuri as IA
ON IA.id_iban=T.id_iban2
INNER JOIN Conturi AS C
ON IA.id_cont=C.id_cont
WHERE I.id_cont=?;
         )");
         stmt.bind(0, &id_c);




         nanodbc::result result = stmt.execute();
         int i = 0;
         while (result.next())
         {   i++;
            int id_tranzactie=(result.get<int>(0));
            int id_iban1=(result.get<int>(1));
            int id_iban2=(result.get<int>(2));
            int suma=(result.get<int>(3));
             string cheie= result.get<std::string>(4);
             Tranzactii t4{ id_tranzactie,id_iban1,id_iban2,suma,cheie };
             
             list.insert(t4);
             
             if (i == 10)
                 break;
           


         }
         final=list.display(final);
         return final;

      
}
catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return "0";
}
    
}

string DAL::cautareid(const Conturi& Conturi)
{
   try{
        string rez;
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, "SELECT * FROM Conturi WHERE cnp=? AND  username = ? ;");

        stmt.bind(0, Conturi.cnp.c_str());
        stmt.bind(1, Conturi.username.c_str());

        nanodbc::result result = stmt.execute();
        while (result.next())
        {
            rez = to_string(result.get<int>(0)) + "_";
            

        }
      
        return rez;
   }
   catch (const std::exception& e) {
       std::cerr << e.what() << '\n';
       return "0";
   }
    
   
}



bool DAL::login( string l, string p,string& final)
{
    try {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, "SELECT * FROM Conturi WHERE username = ? AND parola = ?;");

        stmt.bind(0, l.c_str());
        stmt.bind(1, p.c_str());

        nanodbc::result result = stmt.execute();
        while (result.next())
        {
            final = to_string(result.get<int>(0)) + "_";
            final = final + result.get<std::string>(1) + "_";
            final = final + result.get<std::string>(2) + "_";
            final = final + result.get<std::string>(3) + "_";
            final = final + result.get<std::string>(4) + "_";
            final = final + result.get<std::string>(5) + "_";
            final = final + result.get<std::string>(6) + "_";
            final = final + result.get<std::string>(7) + "_";

        }
        if (final.length() == 0)
            return false;
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}




bool DAL::getConturiBy(int id, int ok, string verif, string & final)
{
    try {
        if (id == 1) {
            nanodbc::statement stmt(conn);
            if (ok == 0) {
                nanodbc::prepare(stmt, R"(
            SELECT * FROM Conturi ;
        )");
                nanodbc::result result = stmt.execute();


                while (result.next())
                {


                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + result.get<std::string>(1) + " ";
                    final = final + result.get<std::string>(2) + " ";
                    final = final + result.get<std::string>(3) + " ";
                    final = final + result.get<std::string>(4) + " ";
                    final = final + result.get<std::string>(5) + " ";
                    final = final + result.get<std::string>(6) + " ";
                    final = final + result.get<std::string>(7) + " ";
                    final = final + to_string(result.get<int>(8)) + "\n";

                }



            }
            else
            {
                int nr;

                nr = stoi(verif);

                nanodbc::prepare(stmt, R"(
           
SELECT *
FROM Conturi
WHERE id_cont = ?;
   
        )");
                stmt.bind(0, &nr);




                nanodbc::result result = stmt.execute();
                while (result.next())
                {


                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + result.get<std::string>(1) + " ";
                    final = final + result.get<std::string>(2) + " ";
                    final = final + result.get<std::string>(3) + " ";
                    final = final + result.get<std::string>(4) + " ";
                    final = final + result.get<std::string>(5) + " ";
                    final = final + result.get<std::string>(6) + " ";
                    final = final + result.get<std::string>(7) + " ";
                    final = final + to_string(result.get<int>(8)) + "\n";

                }
            }

            if (final.length() == 0)
            {
                final = "0";
                return false;
            }
            else
                return true;
        }
        else if (id == 2)

        {

            nanodbc::statement stmt(conn);
            if (ok == 0) {
                nanodbc::prepare(stmt, R"(
            SELECT * FROM IBANuri ;
        )");
                nanodbc::result result = stmt.execute(); \

                    while (result.next())
                    {


                        final = final + to_string(result.get<int>(0)) + " ";
                        final = final + to_string(result.get<int>(1)) + " ";
                        final = final + result.get<std::string>(2) + "\n";


                    }


                //    cout << "row\t";
                //for (short i = 0; i < result.columns(); ++i) {
                //    cout << result.column_name(i) << "\t";
                //}
                //cout << endl;

                //// Print rows
                //while (result.next()) {
                //    cout << result.position() << "\t";
                //    for (short i = 0; i < result.columns(); ++i) {
                //        cout << result.get<string>(i) << "\t";
                //    }
                //    cout << endl;
                //}

            }
            else
            {
                int nr;

                nr = stoi(verif);

                nanodbc::prepare(stmt, R"(
           
SELECT *
FROM IBANuri
WHERE id_cont=?;
   
        )");
                stmt.bind(0, &nr);




                nanodbc::result result = stmt.execute();
                while (result.next())
                {



                    final = final + result.get<std::string>(2) + "\n";


                }
            }

            if (final.length() == 0)
            {
                final = "0";
                return false;
            }
            else
                return true;
        }
        else if (id == 3)

        {

            nanodbc::statement stmt(conn);
            if (ok == 0) {
                nanodbc::prepare(stmt, R"(
            SELECT * FROM Tranzactii ;
        )");
                nanodbc::result result = stmt.execute();

                while (result.next())
                {
                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + to_string(result.get<int>(1)) + " ";
                    final = final + to_string(result.get<int>(2)) + " ";
                    final = final + to_string(result.get<int>(3)) + " ";
                    final = final + result.get<std::string>(4) + "\n";


                }




                //    cout << "row\t";
                //for (short i = 0; i < result.columns(); ++i) {
                //    cout << result.column_name(i) << "\t";
                //}
                //cout << endl;

                //// Print rows
                //while (result.next()) {
                //    cout << result.position() << "\t";
                //    for (short i = 0; i < result.columns(); ++i) {
                //        cout << result.get<string>(i) << "\t";
                //    }
                //    cout << endl;
                //}

            }
            else
            {
                int nr;

                nr = stoi(verif);

                nanodbc::prepare(stmt, R"(
           

SELECT C.nume,C.prenume,IA.iban,T.suma
FROM Tranzactii AS T
INNER JOIN IBANuri as I
ON I.id_iban=T.id_iban1
INNER JOIN IBANuri as IA
ON IA.id_iban=T.id_iban2
INNER JOIN Conturi AS C
ON IA.id_cont=C.id_cont
WHERE I.id_cont=?;
        )");
                stmt.bind(0, &nr);




                nanodbc::result result = stmt.execute();

                while (result.next())
                {
                    final = final + result.get<std::string>(0) + " ";
                    final = final + result.get<std::string>(1) + " ";
                    final = final + result.get<std::string>(2) + " ";
                    final = final + to_string(result.get<int>(3)) + "\n";



                }

            }

            if (final.length() == 0)
            {
                final = "0";
                return false;
            }
            else
                return true;
        }
        else if (id == 4)

        {

            nanodbc::statement stmt(conn);
            if (ok == 0) {
                nanodbc::prepare(stmt, R"(
            SELECT * FROM DEPOZITE ;
        )");
                nanodbc::result result = stmt.execute();


                while (result.next())
                {
                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + to_string(result.get<int>(1)) + " ";
                    final = final + to_string(result.get<int>(2)) + " ";
                    final = final + to_string(result.get<int>(3)) + "\n";



                }


            }
            else
            {
                int nr;

                nr = stoi(verif);

                nanodbc::prepare(stmt, R"(
           
SELECT *
FROM DEPOZITE
WHERE id_cont=?;
    
        )");
                stmt.bind(0, &nr);




                nanodbc::result result = stmt.execute();

                while (result.next())
                {
                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + to_string(result.get<int>(1)) + " ";
                    final = final + to_string(result.get<int>(2)) + " ";
                    final = final + to_string(result.get<int>(3)) + "\n";



                }
            }

            if (final.length() == 0)
            {
                final = "0";
                return false;
            }
            else
                return true;
        }
        else if (id == 5)

        {

            nanodbc::statement stmt(conn);
            if (ok == 0) {
                nanodbc::prepare(stmt, R"(
            SELECT * FROM CARDURI ;
        )");
                nanodbc::result result = stmt.execute();

                while (result.next())
                {


                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + result.get<std::string>(1) + " ";

                    final = final + result.get<std::string>(2) + " ";

                    final = final + result.get<std::string>(3) + " ";

                    final = final + to_string(result.get<int>(4)) + "\n";
                }




            }
            else
            {
                int nr;

                nr = stoi(verif);

                nanodbc::prepare(stmt, R"(
           
SELECT *
FROM CARDURI
WHERE id_cont=?;
   
        )");
                stmt.bind(0, &nr);




                nanodbc::result result = stmt.execute();

                while (result.next())
                {

                    final = final + result.get<std::string>(2) + " ";
                    final = final + result.get<std::string>(1) + " ";
                    final = final + result.get<std::string>(3) + "\n";

                }

            }


            if (final.length() == 0)
            {
                final = "0";
                return false;
            }
            else
                return true;
        }
        else if (id == 6)

        {

            nanodbc::statement stmt(conn);
            if (ok == 0) {
                nanodbc::prepare(stmt, R"(
            SELECT * FROM amenzi ;
        )");
                nanodbc::result result = stmt.execute();


                while (result.next())
                {
                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + result.get<std::string>(1) + " ";

                    final = final + result.get<std::string>(2) + " ";

                    final = final + result.get<std::string>(3) + " ";

                    final = final + to_string(result.get<int>(4)) + "\n";

                }

            }
            else
            {
                int nr;

                nr = stoi(verif);

                nanodbc::prepare(stmt, R"(
           
SELECT *
FROM amenzi
WHERE id_cont=?;
        )");
                stmt.bind(0, &nr);





                nanodbc::result result = stmt.execute();

                while (result.next())
                {
                    final = final + to_string(result.get<int>(0)) + " ";
                    final = final + result.get<std::string>(1) + " ";

                    final = final + result.get<std::string>(2) + " ";

                    final = final + result.get<std::string>(3) + " ";

                    final = final + to_string(result.get<int>(4)) + "\n";

                }
            }

            if (final.length() == 0)
            {
                final = "0";
                return false;
            }
            else
                return true;
        }




    }

    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}






bool DAL::deleteConturi(int id) {
   try{
    nanodbc::statement stmt(conn);
    nanodbc::prepare(stmt, R"(
            DELETE FROM Conturi WHERE id_cont = ?;
        )");

    stmt.bind(0, &id);

    nanodbc::result rez = stmt.execute();

    return rez.has_affected_rows();
   }
   catch (const std::exception& e) {
       std::cerr << e.what() << '\n';
       return false;
   }
}




/// //////////////////////////////////// //////////////////////////////////// /////////////////////////////////



bool DAL::createTranzactii(const Tranzactii& Tranzactii,string& ib2) {
   
    try {
        int iban1, iban2;

        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, R"(
           SELECT id_iban FROM IBANuri
            where id_cont=?;
        )");


        stmt.bind(0, &Tranzactii.id_iban1);


        nanodbc::result result = stmt.execute();
        while (result.next())
        {

            iban1 = result.get<int>(0);


        }


        nanodbc::statement stmt2(conn);
        nanodbc::prepare(stmt2, R"(
           SELECT id_iban FROM IBANuri
            where iban=?;
        )");


        stmt2.bind(0, ib2.c_str());


        nanodbc::result result2 = stmt2.execute();
        while (result2.next())
        {

            iban2 = result2.get<int>(0);


        }

        nanodbc::statement stmt3(conn);
        nanodbc::prepare(stmt3, R"(
            INSERT INTO Tranzactii(id_iban1,id_iban2,suma,cheie) VALUES (?,?,?,?);
        )");


        stmt3.bind(0, &iban1);
        stmt3.bind(1, &iban2);
        stmt3.bind(2, &Tranzactii.suma);
        stmt3.bind(3, Tranzactii.cheie.c_str());

        nanodbc::result rez = stmt3.execute();

        return rez.has_affected_rows();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}
std::string encryptString(const std::string& message, int key) {
    std::string encryptedMessage = message;

    for (char& c : encryptedMessage) {
        // Encrypt each character by adding the key
        c += key;
    }

    return encryptedMessage;
}

int generateRandomKey(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
bool DAL::updatetranzactii() {
    try {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, R"(
            SELECT id_tranzactie,id_iban1,id_iban2,suma from Tranzactii;
        )");

   

        nanodbc::result rez = stmt.execute();
        vector<int> nr;
        vector<string> a;
        while (rez.next())
        {
            int id1 = rez.get<int>(0);
            string final = to_string(rez.get<int>(1))+"_";

            final = final+ to_string(rez.get<int>(2))+"_";
            final = final + to_string(rez.get<int>(3)) + "_";

            nr.push_back(id1);


            
            int minKey = 1;
            int maxKey = 1000;
            int Key = generateRandomKey(minKey, maxKey);


            string verif = encryptString(final, Key);
            a.push_back(verif);
         

        }
        for (int i = 0; i < a.size(); i++)
        {
            nanodbc::statement stmt2(conn);
            nanodbc::prepare(stmt2, R"(
            update Tranzactii
            set cheie = ?
            where id_tranzactie=?;
        )");
            stmt2.bind(0, a[i].c_str());
            stmt2.bind(1, &nr[i]);
            nanodbc::result rez2 = stmt2.execute();
        }
        return rez.has_affected_rows();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}




string DAL::getTranzactiiById(int id1,int suma,string iban) {
   try{
    int iban1, iban2;
    string final;
    nanodbc::statement stmt(conn);
    nanodbc::prepare(stmt, R"(
           SELECT id_iban FROM IBANuri
            where id_cont=?;
        )");


    stmt.bind(0, &id1);


    nanodbc::result result = stmt.execute();
    while (result.next())
    {

        iban1 = result.get<int>(0);


    }


    nanodbc::statement stmt2(conn);
    nanodbc::prepare(stmt2, R"(
           SELECT id_iban FROM IBANuri
            where iban=?;
        )");


    stmt2.bind(0, iban.c_str());


    nanodbc::result result2 = stmt2.execute();
    while (result2.next())
    {

        iban2 = result2.get<int>(0);
        
    }
    final = to_string(iban1) + "_" + to_string(iban2) + "_" + to_string(suma) + "_";

    return final;
   }
   catch (const std::exception& e) {
       std::cerr << e.what() << '\n';
       return "0";
   }
}


bool DAL::deleteTranzactii(int id) {
    nanodbc::statement stmt(conn);
    nanodbc::prepare(stmt, R"(
            DELETE FROM Tranzactii WHERE id_tranzactie = ?;
        )");

    stmt.bind(0, &id);

    nanodbc::result rez = stmt.execute();

    return rez.has_affected_rows();
}




/// //////////////////////////////////// //////////////////////////////////// /////////////////////////////////

bool DAL::createamenzi(const amenzi& amenzi) {
 
    try{
  
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, R"(
            INSERT INTO amenzi(nume, descriere,data_primirii, id_cont,valoare) VALUES (?, ?, ?,?,?)
        )");

        stmt.bind(0, amenzi.nume.c_str());
        stmt.bind(1, amenzi.descriere.c_str());
        stmt.bind(2, amenzi.data_primirii.c_str());
        stmt.bind(3, &amenzi.id_cont);
        stmt.bind(4, &amenzi.valoare);


        nanodbc::result rez = stmt.execute();

        return rez.has_affected_rows();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
    }


bool DAL::deleteamenzi(int id) {
        nanodbc::statement stmt(conn);
        nanodbc::prepare(stmt, R"(
            DELETE FROM amenzi WHERE id_amenda = ?;
        )");

        stmt.bind(0, &id);

        nanodbc::result rez = stmt.execute();

        return rez.has_affected_rows();
    }





void DAL::disconnect() {
    if (conn.connected()) {
        conn.disconnect();
        conn.deallocate();
    }
}


