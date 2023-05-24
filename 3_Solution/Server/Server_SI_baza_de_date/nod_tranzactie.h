#pragma once
#include "Tranzactii.h"
class nod_tranzactie
{
public:
    Tranzactii date;
    nod_tranzactie* next;

    // Constructor
    nod_tranzactie(Tranzactii value) : date(value), next(nullptr) {}
};

