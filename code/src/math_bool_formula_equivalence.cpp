/**
 * @file formula_equivalence.cpp
 * @brief Program to verify equivalence of two boolean formulas
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

/**
 * @brief Computes the old formula: (¬A ∧ B ∧ C) ∨ (A ∧ ¬B ∧ C) ∨ (A ∧ B ∧ C)
 * @param a Boolean value of variable A
 * @param b Boolean value of variable B
 * @param c Boolean value of variable C
 * @return Result of the old formula computation
 */
bool compute_old_formula(bool a, bool b, bool c)
{
    return (!a && b && c) || (a && !b && c) || (a && b && c);
}

/**
 * @brief Computes the new formula: C ∧ (A ∨ B)
 * @param a Boolean value of variable A
 * @param b Boolean value of variable B
 * @param c Boolean value of variable C
 * @return Result of the new formula computation
 */
bool compute_new_formula(bool a, bool b, bool c)
{
    return c && (a || b);
}

/**
 * @brief Generates all possible combinations of three boolean values
 * @return Vector of tuples containing all (A,B,C) combinations
 */
vector<tuple<bool, bool, bool>> generate_combinations()
{
    vector<tuple<bool, bool, bool>> combinations;
    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            for (int c = 0; c <= 1; c++)
            {
                combinations.emplace_back(a, b, c);
            }
        }
    }
    return combinations;
}

/**
 * @brief Tests equivalence of two formulas across all input combinations
 * @return Pair containing equivalence result and mismatch information
 */
pair<bool, vector<tuple<bool, bool, bool>>> test_equivalence()
{
    auto combinations = generate_combinations();
    vector<tuple<bool, bool, bool>> mismatches;
    bool equivalent = true;

    cout << "A\tB\tC\tOld\tNew\tMatch\n";
    cout << "--------------------------------\n";

    for (const auto &[a, b, c] : combinations)
    {
        bool old_result = compute_old_formula(a, b, c);
        bool new_result = compute_new_formula(a, b, c);
        bool match = (old_result == new_result);

        cout << a << "\t" << b << "\t" << c << "\t"
             << old_result << "\t" << new_result << "\t"
             << (match ? "✓" : "✗") << "\n";

        if (!match)
        {
            equivalent = false;
            mismatches.emplace_back(a, b, c);
        }
    }

    return {equivalent, mismatches};
}

/**
 * @brief Main program entry point
 * @return Exit status (0 for success)
 */
int main()
{
    auto [equivalent, mismatches] = test_equivalence();

    cout << "\nFormulas are " << (equivalent ? "" : "not ") << "equivalent\n";

    if (!equivalent)
    {
        cout << "Mismatches found for these inputs:\n";
        for (const auto &[a, b, c] : mismatches)
        {
            cout << "A=" << a << ", B=" << b << ", C=" << c << "\n";
        }
    }

    return 0;
}