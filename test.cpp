#include <fstream>
#include <chrono>
#include <climits>
#include <iomanip>
#include "cle.h"
#include "infoassociee.h"
#include "hashtable.h"

unsigned int lineairRehachage(const Cle &key, unsigned int i)
{
    return i;
}

unsigned int quadratiqueRehachage(const Cle &key, unsigned int i)
{
    return i*i;
}

unsigned int doubleHachage(const Cle &key, unsigned int i)
{
    return i * (99991 - (key % 99991)); //99991 est "prime" <= taille de la table
}

void lireInput(int& capacite,
                int &nombreRecords,
                int &nombreRequetes,
                Cle *&cles,
                InfoAssociee *&valeurs,
                Cle *&requetes)
{
    std::cin >> capacite >> nombreRecords >> nombreRequetes;
    cles = new Cle[nombreRecords];
    valeurs = new InfoAssociee[nombreRecords];
    requetes = new Cle[nombreRequetes];

    for (int i = 0; i < nombreRecords; i++)
        std::cin >> cles[i] >> valeurs[i];
    
    for (int i = 0; i < nombreRequetes; i++)
        std::cin >> requetes[i];
}

void tester(int& capacite,
                int nombreRecords,
                int nombreRequetes,
                Cle *cles,
                InfoAssociee *valeurs,
                Cle *requetes,
                unsigned int (*essaiFonction)(const Cle &, unsigned int),
                std::string nomDeFichier) 
{
    std::ofstream os(nomDeFichier);
    TableDeHachage<Cle, InfoAssociee> ht(capacite, essaiFonction);

    std::cerr << "Commencer inserer data:\n";

    int nombreDeSucces = 0;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < nombreRecords; i++)
        nombreDeSucces += ht.insertion(cles[i], valeurs[i]) ? 1 : 0;
    auto end = std::chrono::steady_clock::now();

    os << "Insertion\n";
    os << "    Nombre records:   " << nombreRecords << "\n";
    os << "    Nombre de succes: " << nombreDeSucces << "\n";
    os << "    Temps:            " <<
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " (ms) \n";
    
    os << "\n";
    os << "Recherche\n";
    os << "    nb        temps\n";

    std::cerr << "Commencer rechercher cles:\n";
    int nombreItems = 0;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            nombreDeSucces += ht.recherche(cles[i*1000 + j]) != NULL ? 1 : 0;
        }
        nombreItems = (i + 1) * 1000;
        end = std::chrono::steady_clock::now();
        double temps = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        os << std::fixed << std::setw(7) << nombreItems << "   " << 
            std::setprecision(2) << std::setw(10) << 1.0*temps/nombreItems << " (ns) \n";
    }
    os.close();
}

int main()
{
    int capacite, nombreRecords, nombreRequetes;
    Cle *cles, *requetes;
    InfoAssociee* valeurs;

    std::cerr << "Commencer lire data\n";
    lireInput(capacite, nombreRecords, nombreRequetes, cles, valeurs, requetes);
    std::cerr << "Finir lire data\n";

    std::cerr << "Commencer tester linear re-hachage\n";
    tester(capacite, nombreRecords, nombreRequetes, cles, valeurs, requetes, lineairRehachage, "performance_lineair_rehachage.txt");
    std::cerr << "Finir tester linear re-hachage\n";

    std::cerr << "Commencer tester quadratic re-hachage\n";
    tester(capacite, nombreRecords, nombreRequetes, cles, valeurs, requetes, quadratiqueRehachage, "performance_quadratique_rehachage.txt");
    std::cerr << "Finir tester quadratic re-hachage\n";

    std::cerr << "Commencer tester double hachage\n";
    tester(capacite, nombreRecords, nombreRequetes, cles, valeurs, requetes, doubleHachage, "performance_double_hachage.txt");
    std::cerr << "Finir tester double hachage\n";

    delete []cles;
    delete []requetes;
    delete []valeurs;
    return 0;
}