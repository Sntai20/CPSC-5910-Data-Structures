/*
 * Created by Antonio Santana on 5/17/21.
 *
 * Problem 4: Coins
 * Prints total weight in pounds of all the coins used by all the possible combinations
 * of 1, 5, 10, 25, 50 cent coins to make $1
 */
#include <iostream>
#include <vector>

using namespace std;

int coinValues[] = {50, 25, 10, 5, 1};
double weights[] = {11.340, 5.670, 2.268, 5.000, 2.500};

int main() {

    const int target = 100;

    vector<vector<int>> solutions;

    int maxHalves = target / coinValues[0];
    cout << "Max Halves: " << maxHalves << endl;

    for (int h = 0; h <= maxHalves; h++)
    {
        int q_remaining = target - (h * coinValues[0]);
        cout << "q_remain: " << q_remaining << endl;

        if (q_remaining < 0)
        {
            vector<int> s = {h, 0, 0, 0, 0};
            solutions.push_back(s);
            continue;
        }
        int max_quarters = q_remaining / coinValues[1];

        for (int q = 0; q <= max_quarters; q++)
        {
            int d_remaining = q_remaining - (q * coinValues[1]);

            if (d_remaining < 0) {
                vector<int> s = {h, q, 0, 0, 0};
                solutions.push_back(s);
                continue;
            }

            int max_dimes = int(d_remaining / coinValues[2]);
            for (int d = 0; d <= max_dimes; d++)
            {
                int n_remaining = d_remaining - (d * coinValues[2]);

                if (n_remaining < 0)
                {
                    vector<int> s = {h, q, d, 0, 0};
                    solutions.push_back(s);
                    continue;
                }

                int max_nickels = int(n_remaining / coinValues[3]);
                for (int n = 0; n <= max_nickels; n++)
                {
                    int p = n_remaining - (n * coinValues[3]);

                    if (p < 0)
                        p = 0;

                    vector<int> s = {h, q, d, n, p};

                    solutions.push_back(s);
                }
            }
        }
    }

    cout << "Solution Count: " << solutions.size() << endl;

    double grams = 0;

    for (auto s : solutions)
    {
        for (unsigned int i = 0; i < s.size(); i++) {
            grams += s[i] * weights[i];
        }
    }

    double pounds = grams / 453.592;

    cout << "Grams: " << grams << endl;
    cout << "Pounds: " << pounds << endl;

    return 0;
}