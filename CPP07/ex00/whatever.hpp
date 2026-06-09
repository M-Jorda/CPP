#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T &t1, T &t2)
{
	T	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template <typename T>
T const	&min(T const &a, T const &b)
{
	return ((a < b) ? a : b);
}

template <typename T>
T const	&max(T const &a, T const &b)
{
	return ((a > b) ? a : b);
}

#endif