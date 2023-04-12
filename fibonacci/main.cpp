#include <iostream>

int fibonacci(int number)
{
    if (number < 3) return 1;
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << "...\n";
    return 0;
}