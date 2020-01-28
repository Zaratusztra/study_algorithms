#include <iostream>
#include <string>

int factorial_recursion(int n, int current)
{
    if (n == 1)
        return current;
    factorial_recursion(n-1, current*n);
}

int factorial(int n)
{
    return factorial_recursion(n, 1);
}

int main(int argc, char ** argv)
{
    std::string arg = std::string(argv[1]);

    try
    {
        std::cout << factorial(std::stoi(arg)) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
