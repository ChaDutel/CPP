#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{

//---------------------------------------------------- My Tests ----------------------------------------------------
	std::cout << "---------------------------------------------------- My Tests ----------------------------------------------------\n\n";

	Array<int> Test(8);

	int i = Test.size();
	std::cout << "Test size is : " << i << std::endl;

    srand(time(NULL));
	Array<int> TestBis = Test;
	std::cout << "TestBis size is : " << TestBis.size() << std::endl;
	for (unsigned int j = 0; j < TestBis.size(); j++)
	{
		const int value = rand();
		TestBis[j] = value;
	}

	Array<int> TestCp(TestBis);
	std::cout << "TestCp size is : " << TestCp.size() << " and its values are : "<< std::endl;
	for (unsigned int j = 0; j < TestCp.size(); j++)
		std::cout << " " << TestCp[j];
	std::cout << std::endl;

	Array<int> TestEmpty;

	i = TestEmpty.size();
	std::cout << "\nTestEmpty size is : " << i << std::endl;

	Array<std::string> TestString(9);
	std::cout << "TestString size is : " << TestString.size() << std::endl;
	std::string	str = "Hello";
	std::cout << "TestTring string is : ";
	for (unsigned int j = 0; j < TestString.size() && str[j]; j++)
	{
		TestString[j] = str[j];
		std::cout << TestString[j];
	}
	std::cout << std::endl;


//---------------------------------------------------- Main Tests ----------------------------------------------------
	std::cout << "\n\n---------------------------------------------------- Main Tests ----------------------------------------------------\n\n";

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
