// C++ program to find
// Roots of a quadratic equation
#include <iostream>
#include <math.h>
using namespace std;
// Prints roots of quadratic equation ax*2 + bx + c
void findRoots(int a, int b, int c)
{
    // If a is 0, then equation is not quadratic
    if (a == 0)
    {
        cout << "Invalid";
        return;
    }
    // Formulae to calculate D
    int d = b * b - 4 * a * c;
    // Formulae to calculate
    // square root of D
    double sqrt_val = sqrt(abs(d));
    // Conditons for checking root
    if (d > 0)
    {
        cout << "Roots are real and different \n";
        cout << (double)(-b + sqrt_val) / (2 * a) << "\n"
             << (double)(-b - sqrt_val) / (2 * a);
    }
    else if (d == 0)
    {
        cout << "Roots are real and same \n";
        cout << -(double)b / (2 * a);
    }
    else
    {
        cout << "Roots are complex \n";
        cout << -(double)b / (2 * a) << " + i"
             << sqrt_val / (2 * a) << "\n"
             << -(double)b / (2 * a) << " - i"
             << sqrt_val / (2 * a);
    }
}

int main()
{

    int a = 1, b = 4, c = 4;
    findRoots(a, b, c);
    return 0;
}