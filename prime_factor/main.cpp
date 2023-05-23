#include <iostream>
#include <vector>

std::vector<int> prime_factor(int number)
{
    std::vector<int> factors;
    int i = 2;
    while (i <= number)
    {
        if (number % i == 0)
        {
            factors.push_back(i);
            number = number / i;
        }
        else
        {
            i++;
        }
    }
    return factors;
}

int main()
{
    std::vector<int> factors = prime_factor(90);
    for (int i = 0; i < factors.size(); i++)
    {
        std::cout << factors[i] << " ";
    }
    return 0;
}