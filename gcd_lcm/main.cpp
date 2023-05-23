#include <iostream>

int gcd(int a, int b)
{
    while (true)
    {
        int temp = a % b;
        if (temp == 0) return b;
        a = b;
        b = temp;
    }
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    std::cout << gcd(10, 5) << "\n";
    std::cout << lcm(10, 3) << "\n";
    return 0;
}