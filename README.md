
## 1. Description
  - Projet Table de Hachage (Hash table project)
  - Resoudre problème collision par double hachage(double-hashing), Quadratique Rehachage (Quadratic Probing), Lineair Rehachage (Linear Probing)a
## 2. Structure de répertoire
 - Fichier cle.h, infoassociee.h: Définir les deux types de données: Cle et InfoAssociee

 - Fichier element.h, element.cpp: Définir et implémenter class template Element pour stocker 1 élément dans la table de hachage 

 - Fichier hashtable.h, hashtable.cpp: Définir et implémenter class template TableDeHachage

 - Fichier data.txt: stocker des données pour tester le programme
	+ 1er ligne contient 3 nombres entiers: capacite, nombreRecords (nombre de cles-valeurs à inserer), nombreRequetes (nombre de cles pour rechercher)
	+ nombreRecords lignes suivantes contiennent nombreRecords cles-valeurs à inserer
	+ nombreRequetes lignes suivantes contiennent nombreRequetes cles pour rechercher

 - Fichier test.cpp:  
	+ compiler programme test performance 
	+ après compiler, il cree 3 fichiers performance_double_hachage.txt, performance_lineair_rehachage.txt, performance_quadratique_rehachage.txt 
	+ chaque fichier performance contient 2 partie: partie 1 (Insertion) contient le nombre records, le nombres records inserés avec succès et le temps total (ms) pour inserer les records. Partie 2 (Recherche) correspondant à linear re-hachage/quadratic re-hachage/double hachage, chaque linge dans cette partie est affiché sous forme de "nb" "Temps" comme décrit dans la feuille du TP5. 

 - Fichier main.cpp: compiler pour voir comment ca marche une table de hachage	

## 3. Les commandes pour makefile:
 - make: compiler fichier
 - make run: compiler le programme main.cpp
 - make run-test data=<nom_fichier>: lancer le programme qui permet de calculer efficacité de la table de hachage avec les données stockés dans fichier <nom_fichier> 
 - make clean: supprimmer les fichiers qui sont déjà compilés
