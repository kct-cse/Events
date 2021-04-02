#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    int n, m;

    cin >> n >> m;

    int *arr = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + m);

    int ans = INT32_MAX;

    for (int i = 0; i < m - n + 1; ++i)
    {
        ans = min(ans, arr[i + n - 1] - arr[i]);
    }

    cout << ans << endl;

    return 0;
}
