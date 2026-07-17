#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

using std::cout;
using std::endl;

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
	cout << "Creation of a mutant stack" << endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
{
	cout << "Creation of a copy of mutant stack" << endl;
	this->c = other->c;
}

template <typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other)
	{
		cout << "Assignation of a copy of mutant stack" << endl;
		this->c = other->c;
	}
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	cout << "Destruction of the mutant stack" << endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
{
	return (this->c.end());
}

#endif