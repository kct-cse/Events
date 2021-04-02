#include <iostream>
using namespace std;
bool check(const string &a, const string &substring)
{

    int len = substring.length();

    int i;
    for (i = 0; i < a.length() && a[i] == substring[i % len]; ++i)
        ;

    return (i == a.length()) ? true : false;
}
int main()
{
    string a = "", b = "";
    cin >> a >> b;
    int ans = 0;

    for (int i = 0; i < a.length() && i < b.length(); ++i)
    {
        if (a.length() % (i + 1) == 0 && b.length() % (i + 1) == 0)
        {
            string substring = a.substr(0, i + 1);

            ans += check(a, substring) && check(b, substring);
        }
    }

    cout << ans << endl;

    return 0;
}
