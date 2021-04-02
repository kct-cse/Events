#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int a[100005];

long long solve(int n, int len, int k)
{
    set<pair<int, int>> A, B;
    long long sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        A.insert(make_pair(a[i], i));
        sum += a[i];
    }
    int r = k;
    long long ans = 0;
    for (int i = len - 1; i < n; i++)
    {
        A.insert(make_pair(a[i], i));
        sum += a[i];
        while (r > 0 && !A.empty() && A.begin()->first < 0)
        {
            sum = sum - 2 * (A.begin()->first);
            B.insert(*A.begin());
            A.erase(A.begin());
            r--;
        }
        while (!B.empty() && !A.empty() && B.rbegin()->first > A.begin()->first)
        {
            sum -= 2 * (A.begin()->first - B.rbegin()->first);
            pair<int, int> P = *A.begin();
            A.erase(A.begin());
            pair<int, int> Q = *B.rbegin();
            B.erase(Q);
            A.insert(Q);
            B.insert(P);
        }
        int x = i - len + 1;
        ans = max(ans, sum);
        if (A.find(make_pair(a[x], x)) == A.end())
        {
            B.erase(make_pair(a[x], x));
            sum += a[x];
            r++;
        }
        else
        {
            sum -= a[x];
            A.erase(make_pair(a[x], x));
        }
    }
    return ans;
}

int main(void)
{
    int n, len, k;
    scanf("%d%d", &n, &len);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    long long ans = solve(n, len, k);
    for (int i = 0; i < n; i++)
        a[i] = -a[i];
    ans = max(ans, solve(n, len, k));

    printf("%lld\n", ans);
    return 0;
}
