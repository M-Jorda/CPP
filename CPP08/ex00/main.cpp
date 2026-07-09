#include "easyfind.hpp"

using std::cout;
using std::cerr;
using std::endl;

int	main(int argc, char **argv)
{
	int v[2, 4, 42, 24];
	try
	{
		std::vector<int>::iterator it = easyfind(v, 42);
		cout << *it << endl;
	}
	catch(std::exception &e)
	{
		cerr << e.what() << endl;
	}
	
}

/*   Les cas de test à couvrir pour prouver que ça ne crash jamais :

  1. Valeur présente dans un vector<int> → vérifier que l'itérateur retourné pointe bien sur la bonne valeur.
  2. Valeur absente → doit lever l'exception, catchée proprement, pas de crash.
  3. Conteneur vide (vector<int> sans éléments) → begin() == end() direct, donc doit throw, à catcher.
  4. Valeurs dupliquées (ex: {1, 3, 3, 5}, chercher 3) → vérifie que tu récupères bien la première occurrence.
  5. Autre type de conteneur, par ex. std::list<int> → pour prouver que le template n'est pas limité à vector (bon point pour la
  correction 42, on te demandera souvent ça).
  6. Valeurs négatives / zéro → juste pour vérifier qu'il n'y a pas de piège genre confusion avec une sentinelle.
  7. (Bonus) Modifier via l'itérateur retourné (puisque c'est un itérateur non-const) pour montrer que le conteneur d'origine est
  bien modifiable — ça illustre pourquoi la fonction prend T& et pas const T&. */
