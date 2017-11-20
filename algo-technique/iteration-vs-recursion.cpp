#include <iostream>
#include <iomanip>
using namespace std;

namespace Execution
{
    static unsigned long long counter = 1;

    struct LinearTrace {
        ~LinearTrace()
        {
            std::cout << ")";
        }
        LinearTrace(unsigned const n)
        {
            std::cout << "(";
            std::cout << "" << std::right << std::setw(2) << std::setfill('0') << Execution::counter++ << ":" << n << "";
        }
    };
}

namespace Recursion
{
    unsigned factorial(unsigned n)
    {
        if (n == 1) return n;
        else return n * factorial(n - 1);
    }

    unsigned fibonacci(unsigned n)
    {
        Execution::LinearTrace TracerOnStack(n);
        if (n <= 1) return n;
        else return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

namespace Iteration
{
    unsigned factorial(unsigned n)
    {
        unsigned F = 1;
        for (unsigned k = 1; k <= n; k++) F *= k;
        return F;
    }

    unsigned fibonacci(unsigned n)
    {
        unsigned I = 0, J = 1;
        unsigned F = I + J;
        for (unsigned k = 2; k <= n; k++) {
            F = I + J; I = J; J = F;
        }
        return F;
    }
};

int main()
{
    Recursion::fibonacci(5);
    std::cout << std::endl;
}

