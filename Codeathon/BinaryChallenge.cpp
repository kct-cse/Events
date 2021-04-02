#include <iostream>
using namespace std;
int64_t solve(string &s, const int64_t &flip_cost, const int64_t &rev_cost)
{

    bool isZeroPresent = false;
    int64_t min_cost = 0;
    int zeroGrpCount = 0;
    int64_t min_operation_cost = min(flip_cost, rev_cost);

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '0')
        {
            isZeroPresent = true;
        }

        if (isZeroPresent && (s[i] == '1' || i == s.length() - 1))
        {
            zeroGrpCount++;
            isZeroPresent = false;
        }
    }

    if (zeroGrpCount > 1)
    {
        min_cost = min_operation_cost * (zeroGrpCount - 1);
    }

    if (zeroGrpCount >= 1)
        min_cost += flip_cost;

    return min_cost;
}
int main()
{

    int n, flip_cost, rev_cost;
    string s;

    cin >> n >> rev_cost >> flip_cost;

    cin >> s;

    cout << solve(s, flip_cost, rev_cost) << endl;

    return 0;
}
