#include <iostream>
#include <string>

typedef long long unsigned int ullint;

ullint factorial_recursion(ullint, ullint); //This is auxilary function. You will see :)

ullint factorial(ullint n)
{
    return factorial_recursion(n, 1);
}


ullint factorial_recursion(ullint n, ullint current)
{
    if (n == 1)
        return current;
    return factorial_recursion(n-1, current*n);
}


int main(int argc, char ** argv)
{
    const char *err_msg = "An error has occured: probably incorrect value was given as an argument";

    std::string arg = std::string(argv[1]);

    try
    {
        std::cout << factorial(std::stoi(arg)) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << err_msg << std::endl;
    }

    return 0;
}
