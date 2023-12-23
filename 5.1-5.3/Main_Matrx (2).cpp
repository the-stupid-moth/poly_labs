#include "Matrx.h"

int main()
{
	int choise = 0, i, j;
	long double n, answer;
	double* mas = nullptr;
	cout << "Insert Matrix\n" << endl <<
		"Isert number of rows:\n";
	cin >> i;
	cout << "Isert number of columns:\n";
	cin >> j;
	cout << "Isert elements:\n";
	Matrx mat(i, j);
	Matrx mat2;
	mat.input(i, j);
	while (choise != 10)
	{
		cout << "please, choise variant\n"
			<< "1 - print matrix to console\n"
			<< "2 - matrix addition\n"
			<< "3 - multiplying two matrices\n"
			<< "4 - matrix trace\n"
			<< "5 - matrix determinant\n"
			<< "6 - multiplying a matrix by a number\n"
			<< "7 - return (i,j) element\n"
			<< "8 - matrix addition through array\n"
			<< "9 - multiplying two matrices through array\n"
			<< "10 - exit\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
			mat.print();
			cout << "\n";
			break;
		case 2:
			cout << "Insert second Matrix\n" << endl <<
				"Isert number of rows:\n";
			cin >> i;
			cout << "Isert number of columns:\n";
			cin >> j;
			cout << "Isert elements:\n";
			mat2.input(i, j);
			mat.sum(mat2);
			cout << endl;
			break;
		case 3:
			cout << "Insert second Matrix\n" << endl <<
				"Isert number of rows:\n";
			cin >> i;
			cout << "Isert number of columns:\n";
			cin >> j;
			cout << "Isert elements:\n";
			mat2.input(i, j);
			mat.mult(mat2);
			cout << endl;
			break;
		case 4:
			answer = mat.trace();
			if (mat.get_num_of_rows() == mat.get_num_of_columns())
			{
				cout << answer << endl;
			}
			else
			{
				cout << "Error, Matrix is not square\n";
			}
			cout << endl;
			break;
		case 5:
			answer = mat.det();
			cout << "Determinant = " << answer << endl;
			cout << endl;
			break;
		case 6:
			cout << "Insert number" << endl;
			cin >> n;
			mat.mult_by_num(n);
			cout << endl;
			break;
		case 7:
			cout << "Insert i and j\n";
			cin >> i >> j;
			n = mat.get_element(i - 1, j - 1);
			cout << n << endl;
			cout << endl;
			break;
		case 8:
			if (mas != nullptr) delete[] mas;
			cout << "Insert second Matrix(array)\n" << endl <<
				"Isert number of rows:\n";
			cin >> i;
			cout << "Isert number of columns:\n";
			cin >> j;
			if (mat.get_num_of_rows() == i && mat.get_num_of_columns() == j)
			{
				mas = new double[i * j];
				cout << "Isert elements:\n";
				for (int l = 0; l < i * j; l++)
				{
					cin >> mas[l];
				}
				mat.sum(mas, i * j);
			}
			else
			{
				cout << "Error\n";
			}
			cout << endl;
			break;
		case 9:
			if (mas != nullptr) delete[] mas;
			cout << "Insert second Matrix(array)\n" << endl <<
				"Isert number of rows:\n";
			cin >> i;
			cout << "Isert number of columns:\n";
			cin >> j;
			if (mat.get_num_of_columns() == i)
			{
				mas = new double[i * j] {0};
				cout << "Isert elements:\n";
				for (int l = 0; l < i * j; l++)
				{
					cin >> mas[l];
				}
				mat.mult(mas, i * j);
			}
			else
			{
				cout << "Error\n";
			}
			cout << endl;
			break;
		case 10:
			break;
		default:
			return 0;
		}
	}
	return 0;
}