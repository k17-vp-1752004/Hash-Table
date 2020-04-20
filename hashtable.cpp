#ifndef _HASH_TABLE
#include "hashtable.h"
#else

template<class K, class V>
TableDeHachage<K, V>::TableDeHachage(
    int capacite,
    unsigned int (*essaiFonc)(const K &, unsigned int),
    unsigned int (*hashFonc)(const K &))
{
    this->capacite = capacite;
    this->nombreItems = 0;

    this->table = new Element<K, V> *[this->capacite];
    this->etat = new int[this->capacite];
    std::memset(this->table, 0, this->capacite * sizeof(Element<K, V> *));
    std::memset(this->etat, 0, this->capacite * sizeof(int));

    this->hashFonction = hashFonc;
    this->essaiFonction = essaiFonc;
}

template<class K, class V>
unsigned int TableDeHachage<K, V>::defaultHash(const K &cle)
{
    return cle;
}

template<class K, class V>
unsigned int TableDeHachage<K, V>::defaultEssaiFonction(const K & cle, unsigned int i)
{
    return i;
}

template<class K, class V>
bool TableDeHachage<K, V>::suppression(const K &cle)
{
    unsigned int hash = this->hashFonction(cle);
    unsigned int indice = hash % this->capacite;
    int turn = 0;
    while (this->etat[indice] != 0 && turn < this->capacite)
    {
        if (this->table[indice]->cle == cle)
        {
            if (this->etat[indice] == 1)
            {
                delete this->table[indice];
                this->etat[indice] = -1;
                this->nombreItems--;
                return true;
            }
            return false; // found, but deleted
        }
        turn++;
        indice = (hash + this->essaiFonction(cle, turn)) % capacite;
    }
    return false;
}

template<class K, class V>
bool TableDeHachage<K, V>::insertion(const K &cle, const V &valeur)
{
    unsigned int hash = this->hashFonction(cle);
    unsigned int indice = hash % this->capacite;
    int turn = 0; //nombre d'essais
    while (this->etat[indice] == 1 && turn < this->capacite)
    {
        if (this->table[indice]->cle == cle)
        {
            this->table[indice]->valeur = valeur;
            return true;
        }
        turn++;
        indice = (hash + this->essaiFonction(cle, turn)) % capacite;
    }
    if (turn >= this->capacite)
        return false;
    this->etat[indice] = 1;
    this->table[indice] = new Element<K, V>(cle, valeur);
    this->nombreItems++;
    return true;
}

template<class K, class V>
V *TableDeHachage<K, V>::recherche(const K &cle) const
{
    unsigned int hash = this->hashFonction(cle);
    unsigned int indice = hash % this->capacite;
    int turn = 0; 
    while (this->etat[indice] != 0 && turn < this->capacite)
    {
        if (this->etat[indice] == 1 && this->table[indice]->cle == cle)
            return &(this->table[indice]->valeur);
        turn++;
        indice = (hash + this->essaiFonction(cle, turn)) % capacite;
    }
    return NULL;
}

template<class K, class V>
void TableDeHachage<K, V>::modifier(const K & cle, const V &valeur)
{
    V* info = this->recherche(cle);
    if (info != NULL)
    {
        *info = valeur;
    }
}

template<class K, class V>
void TableDeHachage<K, V>::affichage()
{
    for (int i = 0; i < this->capacite; i++) {
        if (this->etat[i] == 1) {
            std::cout << "Index " << i << ": " << this->table[i]->cle << "    " << this->table[i]->valeur << "\n";
        }
    }
}

template<class K, class V>
TableDeHachage<K, V>::~TableDeHachage()
{
    for (int i = 0; i < this->capacite; i++) {
        if (this->etat[i] == 1) {
            delete this->table[i];
        }
    }
    delete this->etat;
    delete this->table;
}

#endif