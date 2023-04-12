#include <cstdint>
#include <iostream>

#ifndef integer
#define integer std::int64_t
#endif

integer factorial(integer number)
{
    if (number < 0) return -1;
    integer result = 1;
    for (integer i = 2; i <= number; i++) 
    {
        result *= i;
    }
    return result;
}

int main()
{
    integer result1 = factorial(5);
    integer result2 = factorial(20);
    std::cout << result1 << "\n";
    std::cout << result2 << "\n";
    return 0;
}