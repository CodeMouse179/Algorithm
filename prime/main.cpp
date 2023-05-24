#include <iostream>
#include <cmath>
#include <cstring>

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

#define new_prime_array(arr_name, number)           \
    bool __##arr_name[number + 1];                  \
    __new_prime_array(__##arr_name, number + 1);    \

void __new_prime_array(bool* arr, int len)
{
    std::memset(arr, true, sizeof(bool) * len);
    for (int i = 2; i <= (int)std::sqrt(len); i++)
    {
        if (arr[i])
        {
            for (int j = i + i; j < len; j += i)
            {
                arr[j] = false;
            }
        }
    }
}

#define show_prime_array(arr_name, number)          \
    __show_prime_array(__##arr_name, number + 1);   \

void __show_prime_array(bool* arr, int len)
{
    for (int i = 2; i < len; i++)
    {
        if (arr[i]) std::cout << i << " is prime\n";
        else std::cout << i << " is not prime\n";
    }
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

    std::cout << "\ninput a number: ";
    int number;
    std::cin >> number;
    new_prime_array(prime_array, number);
    show_prime_array(prime_array, number);

    return 0;
}