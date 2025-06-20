#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Converts a 100-point score to a 5-point grade.
 * 
 * @param score The input score (0-100).
 * @return int The corresponding grade (2-5).
 */
int convert_score(int score) {
    if (score >= 90) return 5;
    else if (score >= 70) return 4;
    else if (score >= 50) return 3;
    else return 2;
}

/**
 * @brief Main function: generates random scores and converts them to grades.
 */
int main() {
    int seed;
    cin >> seed;
    srand(seed);

    for (int i = 0; i < 8; ++i) {
        int score_100 = rand() % 101; // Random score (0-100)
        int score_5 = convert_score(score_100);

        // Output directly without stringstream
        cout << score_100 << "(" << score_5 << ")";

        // Add space unless it's the last element
        if (i < 7) cout << " ";
    }

    cout << "\n";
    return 0;
}