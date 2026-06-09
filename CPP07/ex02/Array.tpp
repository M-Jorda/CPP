#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _data(NULL), size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), size(n)
{

}

Array::Array(const Array &other)
{

}

Array Array::&operateur=(const Array &other)
{

}

Array::~Array()
{

}

T	Array::&operateur[](unsigned int n)
{

}

unsigned int	Array::size() const
{

}

#endif
