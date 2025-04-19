#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
    T *_elements;
    unsigned int _size;

public:
    // Default constructor: creates an empty array
    Array() : _elements(NULL), _size(0) {}

    // Constructor with size parameter
    Array(unsigned int n) : _size(n)
    {
        _elements = new T[n]();
    }

    // Copy constructor
    Array(const Array &other) : _elements(NULL), _size(0)
    {
        *this = other;
    }

    // Destructor
    ~Array()
    {
        if (_elements)
            delete[] _elements;
    }

    // Assignment operator
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            if (_elements)
                delete[] _elements;

            _size = other._size;
            _elements = new T[_size];

            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = other._elements[i];
        }
        return *this;
    }

    // Subscript operator
    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::exception();
        return _elements[index];
    }

    // Const subscript operator
    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::exception();
        return _elements[index];
    }

    // Size function
    unsigned int size() const
    {
        return _size;
    }
};

#endif