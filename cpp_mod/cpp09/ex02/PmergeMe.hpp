#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <string>
# include <vector>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>

class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static bool isPositiveInteger(const std::string& str);
    static void printVector(const std::vector<int>& values, const std::string& msg);

    template <typename Container>
    static typename Container::iterator binaryPosition(Container& container, int value)
    {
        typename Container::iterator begin;
        typename Container::iterator end;
        typename Container::iterator mid;

        begin = container.begin();
        end = container.end();
        while (begin < end)
        {
            mid = begin + (end - begin) / 2;
            if (*mid < value)
                begin = mid + 1;
            else
                end = mid;
        }
        return (begin);
    }

public:
    static std::vector<int> parseInput(int argc, char **argv);
    static void run(int argc, char **argv);

    template <typename Container>
    static void mergeInsertionSort(Container& container)
    {
        Container bigger;
        Container smaller;
        std::size_t i;

        if (container.size() <= 1)
            return;
        i = 0;
        while (i + 1 < container.size())
        {
            if (container[i] > container[i + 1])
            {
                bigger.push_back(container[i]);
                smaller.push_back(container[i + 1]);
            }
            else
            {
                bigger.push_back(container[i + 1]);
                smaller.push_back(container[i]);
            }
            i += 2;
        }
        if (i < container.size())
            smaller.push_back(container[i]);
        mergeInsertionSort(bigger);
        for (i = 0; i < smaller.size(); ++i)
            bigger.insert(binaryPosition(bigger, smaller[i]), smaller[i]);
        container = bigger;
    }
};

#endif