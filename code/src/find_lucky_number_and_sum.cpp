#include <iostream>
using namespace std;

/**
 * @brief Checks if a 6-digit ticket number is "happy" (sum of first three digits equals sum of last three digits).
 *
 * @param num The 6-digit ticket number.
 * @param sum1 Reference to int where the sum of the first three digits will be stored.
 * @param sum2 Reference to int where the sum of the last three digits will be stored.
 * @return true if the ticket is happy, false otherwise.
 */
bool ticket(int num, int &sum1, int &sum2);

int main()
{
    int num, sum1, sum2;
    cin >> num;
    if (ticket(num, sum1, sum2))
        cout << "HAPPY " << sum1 << " " << sum2 << "\n";
    else
        cout << "UNHAPPY " << sum1 << " " << sum2 << "\n";
    return 0;
}

bool ticket(int num, int &sum1, int &sum2)
{
    int digits[6];
    for (int i = 5; i >= 0; --i)
    {
        digits[i] = num % 10;
        num /= 10;
    }
    sum1 = digits[0] + digits[1] + digits[2];
    sum2 = digits[3] + digits[4] + digits[5];
    return sum1 == sum2;
}