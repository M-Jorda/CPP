#include "easyfind.hpp"

using std::cout;
using std::cerr;
using std::endl;

template <typename T>
typename T::iterator	find(T &vec, int val)
{
	return (easyfind(vec, val));
}

template <typename T, typename F>
void	runner(std::string test, T &vec, int val, F func)
{
	try
	{
		cout << "Test: " << test << endl;
		typename T::iterator it = func(vec, val);
		cout << "Value found: "<< *it << endl;
		cout << "Pos: " << std::distance(vec.begin(), it) + 1 << endl;
	}
	catch(std::exception &e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;
}

int	main(void)
{
	std::vector<int> v;
	v.push_back(-42);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(42);

	std::vector<int> empty;
	std::list<int> lst;

	runner("Found", v, 42, find<std::vector<int> >);
	runner("Not found", v, 24, find<std::vector<int> >);
	runner("Empty", empty, 42, find<std::vector<int> >);
	runner("Double", v, 5, find<std::vector<int> >);
	runner("Negative", v, -42, find<std::vector<int> >);
	runner("Negative not found", v, -24, find<std::vector<int> >);
	runner("Not a vector", lst, 0, find<std::list<int> >);
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
