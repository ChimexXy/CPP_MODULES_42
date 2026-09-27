#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    std::string filename;
    std::string s1;
    std::string s2;
    std::string line;

    if (ac == 4)
    {
        filename = av[1];
        s1 = av[2];
        s2 = av[3];

        if (s1.empty())
        {
            std::cout << "s1 is empty" << std::endl;
            return 1;
        }

        std::ifstream infile(filename.c_str());
        if (!infile.is_open())
        {
            std::cout << "cannot open input file" << std::endl;
            return 1;
        }

        std::ofstream outfile((filename + ".replace").c_str());
        if (!outfile.is_open())
        {
            std::cout << "cannot create output file" << std::endl;
            return 1;
        }

        while (std::getline(infile, line))
        {
            size_t pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
            outfile << line;
            if (!infile.eof())
                outfile << std::endl;
        }

        infile.close();
        outfile.close();
    }
    else
        std::cout << "set the valid arguments" << std::endl;
    return 0;
}
