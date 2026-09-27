#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other){ (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositiveInteger(const std::string& str)
{
    std::size_t i;

    if (str.empty())
        return (false);
    i = 0;
    if (str[i] == '+')
        ++i;
    if (i == str.length())
        return (false);
    while (i < str.length())
    {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        ++i;
    }
    return (true);
}

std::vector<int> PmergeMe::parseInput(int argc, char **argv)
{
    std::vector<int> values;
    int i;

    if (argc < 2)
        throw std::runtime_error("Error");
    i = 1;
    while (i < argc)
    {
        std::string arg;
        char *end;
        long value;

        arg = argv[i];
        if (!isPositiveInteger(arg))
            throw std::runtime_error("Error");
        errno = 0;
        value = std::strtol(arg.c_str(), &end, 10);
        if (*end != '\0' || errno == ERANGE || value > INT_MAX || value <= 0)
            throw std::runtime_error("Error");
        values.push_back(static_cast<int>(value));
        ++i;
    }
    return (values);
}

void PmergeMe::printVector(const std::vector<int>& values, const std::string& msg)
{
    std::size_t i;

    std::cout << msg;
    for (i = 0; i < values.size(); ++i)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << values[i];
    }
    std::cout << std::endl;
}

void PmergeMe::run(int argc, char **argv)
{
    std::vector<int> input;
    std::vector<int> vectorValues;
    std::deque<int> dequeValues;
    clock_t start;
    clock_t end;
    double vectorTime;
    double dequeTime;

    input = parseInput(argc, argv);
    vectorValues.assign(input.begin(), input.end());
    dequeValues.assign(input.begin(), input.end());
    printVector(input, "Before: ");
    start = std::clock();
    mergeInsertionSort(vectorValues);
    end = std::clock();
    vectorTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    start = std::clock();
    mergeInsertionSort(dequeValues);
    end = std::clock();
    dequeTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    printVector(vectorValues, "After: ");
    std::cout << "Time to process a range of " << input.size()
        << " elements with std::vector : " << vectorTime << " us"
        << std::endl;
    std::cout << "Time to process a range of " << input.size()
        << " elements with std::deque : " << dequeTime << " us"
        << std::endl;
}
