#pragma once
#include "nod_tranzactie.h"
class LinkedList
{
private:
    nod_tranzactie* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
       nod_tranzactie* current = head;
        while (current != nullptr) {
            nod_tranzactie* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert a new element at the beginning of the list
    void insert(Tranzactii value) {
       nod_tranzactie* newNode = new nod_tranzactie(value);
        newNode->next = head;
        head = newNode;
    }

    // Print the list
    string display(string file) {
        nod_tranzactie* current = head;
        while (current != nullptr) {
            file = file + to_string(current->date.id_iban1) + " ";
            file = file + to_string(current->date.id_iban2) + " ";
            file = file + to_string(current->date.suma) + "\n";
            current = current->next;
        }
        return file;
    }
};