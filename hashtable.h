#ifndef _HASH_TABLE
#define _HASH_TABLE

#include <iostream>
#include <cstdio>
#include <cstring>
#include "element.h"

template<class K, class V>
class TableDeHachage {
private:
    Element<K, V>** table;
    int* etat; // -1: deleted, 0: empty, 1: used
    int capacite; //la taille maximum de la table
    int nombreItems; //nombre d'items dans table de hachage
    unsigned int (*hashFonction)(const K &); //Fonction pointer pour stocker hash fonction choisi par utilisateur, 1er para est cle, 2eme para est taille de la table
    unsigned int (*essaiFonction)(const K &, unsigned int); //Fonction pointeur pour stocker quel essai fonction qu'utiliseur choisi: linear? quadratic? double?; 1er para est cle, 2eme est i-eme d'essai 

public:
    TableDeHachage(
        int capacite = 1000000,
        unsigned int (*essaiFonc)(const K &, unsigned int) = &TableDeHachage<K, V>::defaultEssaiFonction,
        unsigned int (*hashFonc)(const K &) = &TableDeHachage<K, V>::defaultHash);
    ~TableDeHachage();

    static unsigned int defaultHash(const K &);
    static unsigned int defaultEssaiFonction(const K &, unsigned int);

    bool suppression(const K &);
    bool insertion(const K &, const V &);
    V *recherche(const K &) const;
    void modifier(const K &, const V &);
    void affichage();
};

#include "hashtable.cpp"
#endif