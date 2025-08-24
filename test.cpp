// // #include <iostream>

// // int main(int ac, char **av)
// // {
// // 	// if (ac != 1)
// // 	// 	return 0;
// // 	std::cout << "Hello world" << std::endl;

// // 	int num;
// // 	std::cin>>num;
// // 	if (std::cin.fail())
// // 	{
// // 		std::cout << "invalid input retry" << std::endl;
// // 		std::cin.clear();
// // 		std::cin>>num;
// // 	}
// // 	std::cout<< "num = " << num << std::endl;

// // 	char c;
// // 	std::cin>>c;
// // 	std::cout<< "c = " << c << std::endl;
// // 	return (0);
// // }


#include <iostream>
#include <limits>

int check(char *num)
{
	int i = 0;
	if(!num)
		return (0);
	for (i = 0; num[i]; i++)
	{
		if(!(num[i] >= '0' && num[i] <= '9'))
			return (1);
	}
	return (0);
}

using namespace std;

int main()
{
	int num;

	while (1) {
		cout << "Enter a valid number: herre " << endl;
		cin >> num;

		if (!cin.fail())
			break; // input successful, exit loop

		// input failed
		cout << "Invalid input. Try again.\n";

		cin.clear(); // fix error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove garbage
	}

	cout << "You entered: " << num << endl;

	return 0;
}
