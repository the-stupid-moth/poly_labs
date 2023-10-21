#include <iostream>

void triangle(int number)
{
	for (int i = 0; i <= number; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << j;
		}
		std::cout << std::endl;
	}
}

int factorial(int n)
{
	int nol = 1;
	for (int i = 1; i <= n; i++) {
		nol *= i;
	}
	return nol;
}

void task1()
{
	int triangle_number;
	std::cout << "Task 1\n" << std::endl <<
		"Insert your number:" << std::endl;
	std::cin >> triangle_number;
	triangle(triangle_number);
	std::cout << std::endl;
}

void task2()
{
	double num, result = 1;
	std::cout << "Task 2\n " << "Insert your number:"; 
	std::cin >> num;

	for (int k = 0; k <= num; k++)
	{    
		if (k == 0)
		{
			std::cout << 1 << " ";
		}
		else 
		{
			std::cout << result * ((num - k + 1)/ k) << " ";
			result = result * ((num - k + 1) / k);		
		}
	}
	std::cout << std::endl;
}

void task3()
{
	int counter = 0, summ = 0;
	char input;
	std::cout << "Task 3" << std::endl <<
		"Input numbers, finishing with !" << std::endl;
	std::cin >> input;
	while (input != '!') {
		summ += (input - 48);
		counter++;
		std::cin >> input;
	}
	std::cout << "Your average number is " << double(summ) / counter << std::endl << std::endl;
}

int main()
{
	int input;
	while (true) {
		std::cout << "Insert 1 to check task number 1" << std::endl <<
			"Insert 2 to check task number 2" << std::endl <<
			"Insert 3 to check task number 3" << std::endl <<
			"Insert anything else to shut down" << std::endl;
		std::cin >> input;
		switch (input) {
			case 1:
			{
				task1();
				break;
			}
			case 2:
			{
				task2();
				break;
			}
			case 3:
			{
				task3();
				break;
			}
			default:
			{
				return 0;
			}
		}
	}
}