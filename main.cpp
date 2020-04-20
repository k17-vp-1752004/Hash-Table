#include "cle.h"
#include "infoassociee.h"
#include "hashtable.h"

void insertion(TableDeHachage<Cle, InfoAssociee> &ht, Cle cle, InfoAssociee valeur)
{
    std::cout << "Inserer {" << cle << ", " << valeur << "}: ";
    if (ht.insertion(cle, valeur))
    {
        std::cout << "succes\n";
    }
    else
    {
        std::cout << "echec\n";
    }
}

unsigned int utilisateurEssai(const Cle &key, unsigned int i)
{
    return i*i;
}

int main()
{
    TableDeHachage<Cle, InfoAssociee> ht(10, utilisateurEssai, TableDeHachage<Cle, InfoAssociee>::defaultHash);
    insertion(ht, 10, 1.2);
    insertion(ht, 12, 1.3);
    insertion(ht, 13, 1.4);
    insertion(ht, 14, 1.5);
    insertion(ht, 16, 1.6);
    insertion(ht, 18, 1.7);
    insertion(ht, 20, 2.1);
    ht.modifier(20, 100);

    InfoAssociee* info = ht.recherche(13);
    if (info != NULL)
        std::cout << "Cle " << 13 << " a valeur " << *info << "\n";
    else
        std::cout << "Cle " << 13 << " a introuvable\n";
    
    std::cout << "Supprimer cle 13\n";
    ht.suppression(13);

    info = ht.recherche(13);
    if (info != NULL)
        std::cout << "Cle " << 13 << " a valeur " << *info << "\n";
    else
        std::cout << "Cle " << 13 << " a introuvable\n";

    insertion(ht, 11, 2.2);
    
    ht.affichage();

    return 0;
}