#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int x, y;
        cin >> x >> y;

        string s;
        cin >> s;

        int U = 0, R = 0, D = 0, L = 0;

        (x > 0) ? R = x : L = -x;

        (y > 0) ? U = y : D = -y;

        int c1, c2;

        if (R)
        {
            c1 = count(s.begin(), s.end(), 'R');
            if (U)
            {
                c2 = count(s.begin(), s.end(), 'U');
            }
            else
            {
                c2 = count(s.begin(), s.end(), 'D');
            }
        }

        else
        {
            c1 = count(s.begin(), s.end(), 'L');
            if (U)
            {
                c2 = count(s.begin(), s.end(), 'U');
            }
            else
            {
                c2 = count(s.begin(), s.end(), 'D');
            }
        }

        if (c1 >= L && c1 >= R && c2 >= U && c2 >= D)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
