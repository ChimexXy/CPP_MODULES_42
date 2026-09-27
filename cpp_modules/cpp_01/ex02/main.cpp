#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "Memory adress of str : " << &str << std::endl;
	std::cout << "Memory adress held by strPTR : " << &strPTR << std::endl;
	std::cout << "Memory adress held by strREF : " << &strREF << std::endl;
	std::cout << "The value of str : " << str << std::endl;
	std::cout << "The value pointed to by strPTR : " << *strPTR << std::endl;
	std::cout << "THe value pointed to by strREF : " << strREF << std::endl;

}