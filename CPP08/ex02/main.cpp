#include "MutantStack.hpp"

#include <list>

using std::cout;
using std::endl;

template <typename T, typename C>
static void isEmpty(MutantStack<T, C> &ms)
{
	cout << "Is" << (ms.empty() ? " " : "n't ") << "empty" << endl;
}

template <typename T, typename C>
static void	printstack(std::string name, MutantStack<T, C> &ms)
{
	cout << "Print Stack: " << endl;
	cout << name << endl;
	typename MutantStack<T, C>::iterator it = ms.begin();
	typename MutantStack<T, C>::iterator ite = ms.end();
	if (it != ite)
	{
		++it;
		--it;
	}
	while (it != ite)
	{
		typename MutantStack<T, C>::iterator next = it;
		++next;
		cout << *it << (next == ite ? "\n" : ", ");
		++it;
	}
	cout << endl;
}

template <typename T, typename C>
static void readContent(std::string name, MutantStack<T, C> &ms)
{
	if (!ms.empty())
	{
		cout << "Read Content: " << endl;
		cout << name << ": " << endl;
		cout << "top = " << ms.top() << ", size = " << ms.size() << endl;
		ms.pop();
		cout << "poped it" << endl; 
		cout << "top = " << ms.top() << ", size = " << ms.size() << endl << endl;
	}
}

template <typename T, typename C, typename F>
static void	useFunc(F func, MutantStack<T, C> &ms1, MutantStack<T, C> &ms2, MutantStack<T, C> &ms3)
{
	func("ms1", ms1);
	func("ms2", ms2);
	func("ms3", ms3);
}

template <typename T, typename C>
static void	addValue(MutantStack<T, C> &ms, T val1, T val2, T val3)
{
	ms.push(val1);
	ms.push(val2);
	ms.push(val3);
}

template <typename T, typename C>
static void	printStackValues(std::stack<T> stack, MutantStack<T, C> ms)
{
	cout << "Stack size: " << stack.size() << " / MutantStack size: " << ms.size() << endl;
	cout << "Print Stack Values" << endl;
	while (!stack.empty() && !ms.empty())
	{
		cout << "Stack top: " << stack.top() << endl;
		cout << "MutantStack top: " << ms.top() << endl;
		stack.pop();
		ms.pop();
	}
	cout << "Stack size: " << stack.size() << " / MutantStack size: " << ms.size() << endl << endl;
}

int main()
{
	MutantStack<int> ms1;
	isEmpty(ms1);
	addValue(ms1, 5, 42, 100);
	isEmpty(ms1);
	MutantStack<int> ms2;
	ms2 = ms1;
	MutantStack<int> ms3(ms1);
	cout << endl;
	useFunc(printstack<int, std::deque<int> >, ms1, ms2, ms3);
	useFunc(readContent<int, std::deque<int> >, ms1, ms2, ms3);
	MutantStack<int, std::list<int> > ls;
	addValue(ls, 0, 3, 5);
	printstack("list", ls);
	readContent("list", ls);
	addValue(ms1, 450, 4683, 4684845);
	std::stack<int> s(ms1);
	printStackValues(s, ms1);
}