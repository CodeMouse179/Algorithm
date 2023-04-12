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

integer __factorial(integer number)
{
    if (number < 0) return -1;
    if (number == 1 || number == 0) return 1;
    return __factorial(number - 1) * number;
}

int main()
{
    integer result_ = factorial(-5);
    integer result0 = factorial(0);
    integer result1 = factorial(5);
    integer result2 = factorial(20);
    std::cout << result_ << "\n";
    std::cout << result0 << "\n";
    std::cout << result1 << "\n";
    std::cout << result2 << "\n";

    integer result3 = __factorial(-5);
    integer result4 = __factorial(0);
    integer result5 = __factorial(5);
    integer result6 = __factorial(20);
    std::cout << result3 << "\n";
    std::cout << result4 << "\n";
    std::cout << result5 << "\n";
    std::cout << result6 << "\n";
    return 0;
}