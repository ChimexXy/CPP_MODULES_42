#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename tamp, typename F>
void iter(tamp* array, size_t length, F func)
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif