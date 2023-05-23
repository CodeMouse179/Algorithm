#include <iostream>
#include <cmath>

bool is_prime(int number)
{
    if (number < 4) return number > 1;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0) return false;
    }
    return true;
}

bool is_prime_plusplus(int number)
{
    if (number < 4) return number > 1;
    for (int i = 2; i <= (int)std::sqrt(number); i++)
    {
        if (number % i == 0) return false;
    }
    return true;
}

int main()
{
    std::cout << "function: is_prime\n";
    for (int i = 2; i <= 10; i++)
    {
        if (is_prime(i))
        {
            std::cout << i << " is prime\n";
        }
        else
        {
            std::cout << i << " is not prime\n";
        }
    }
    std::cout << "\nfunction: is_prime_plusplus\n";
    for (int i = 2; i <= 10; i++)
    {
        if (is_prime_plusplus(i))
        {
            std::cout << i << " is prime\n";
        }
        else
        {
            std::cout << i << " is not prime\n";
        }
    }
    return 0;
}