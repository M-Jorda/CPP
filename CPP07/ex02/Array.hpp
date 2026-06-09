#ifndef ARRAY_HPP
# define ARRAY_HPP

class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operateur=(const Array &other);
		~Array();

		T				&operateur[](unsigned int n);
		unsigned int	size() const;

	private:
		T				*_data;
		unsigned int	_size;
}

# include "Array.tpp"

#endif
