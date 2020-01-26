#include <iostream>
#include <stdexcept>
//#include <cstring>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

typedef long long int llint;
typedef unsigned long long int ullint;

llint fibonacci(llint n)
{
    if(n < 0)
    {
        throw std::invalid_argument("Argument must be an integer greater or equal to one.");
    }
    llint * partial_results = new llint[n+1]; // 0, 1, ..., n
    partial_results[0]=0;
    partial_results[1]=1;
    for(ullint m = 2; m <= n; m++)
    {
        partial_results[m]=partial_results[m-1]+partial_results[m-2];
    }
    return partial_results[n];
}

int main(int argc, char ** argv)
{
    llint n;
    try{
        //n = atol(argv[1]);
        cout << "How many numbers: ";
        cin >> n;
        for (int m = 0; m <= n; m++)
            cout << "F(" << m << ")=" << fibonacci(m) << endl;
    }
    catch(std::exception & e){
        cerr << e.what() << endl;
    }
    return 0;
}