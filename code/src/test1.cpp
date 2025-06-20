#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/**
 * @brief Calculates the accumulated deposit amount using compound interest.
 *
 * @param P Initial deposit amount.
 * @param r Annual interest rate (as a fraction, e.g., 0.09 for 9%).
 * @param n Number of years.
 * @return double Accumulated amount after n years.
 */
double deposit(double P, double r, int n)
{
    return P * pow(1 + r, n);
}

/**
 * @brief Entry point of the program.
 * Reads initial deposit, interest rate (in percent), and number of years.
 * Calculates and prints the accumulated amount rounded to two decimal places.
 */
int main()
{
    double P, rate;
    int n;
    cin >> P >> rate >> n;
    double r = rate / 100.0;
    double S = deposit(P, r, n);
    cout << fixed << setprecision(2) << S << "\n";
    return 0;
}