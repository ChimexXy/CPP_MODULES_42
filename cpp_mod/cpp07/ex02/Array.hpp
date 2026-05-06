#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    T*           _data;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(Array const& other);
    Array& operator=(Array const& other);
    ~Array();

    T&           operator[](unsigned int index);
    T const&     operator[](unsigned int index) const;
    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds";
        }
    };
};

#include "Array.tpp"

#endif