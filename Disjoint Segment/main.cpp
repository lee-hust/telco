#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int, int> ii;
#define fi first
#define se second
const int maxn = 1e5 + 5;
ii A[maxn];
int dp[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].fi >> A[i].se;
    }
    sort(A, A+n);
    dp[n-1] = 1;
    for (int i = n-2; i >= 0; i--)
    {
       int a = lower_bound(A, A+n, make_pair(A[i].se + 1, -1)) - A;
       dp[i] = max(dp[i+1], 1 + dp[a]);
    }
    cout << dp[0];
}