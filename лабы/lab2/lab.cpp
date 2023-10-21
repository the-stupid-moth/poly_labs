#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void task1()
{
  cout << "Задание 1\n" << "До какого числа вы хотите треугольник?" << endl;
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++)
  {
    for (int m = 0; m <= i; m++)
    {
      cout << m;
    }
    cout << endl;
  }
}
void task2()
{
  short n;
  float answer;
  answer = 1;
  cout << "Задание 2\n" << "Введите число меньше 100" << endl;
  cin >> n;
  for (short k = 0; k <= n; k++)
  {
    if (k == 0)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << (answer * (n - k + 1) / k) << "\n";
      answer = (answer * (n - k + 1) / k);
    }
  }
  return;
}
void task3()
{
  double count, input, s = 0;
  count = 0;
  cout << "Введите число\n" << endl;
  cin >> input;
  while (input != 0)
  {
    count += 1;
    s += input;
    cout << "Введите число" << endl;
    cin >> input;
  }
  cout << s / count << endl;
  return;
}

int main()
{
  setlocale(LC_ALL, "Russian");
  int choise = 0;
  while (true)
  {
    cout << "Что вы хотите выполнить?\n"
      << "1 задание\n"
      << "2 задание\n"
      << "3 задание\n";
    cin >> choise;
    switch (choise)
    {
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