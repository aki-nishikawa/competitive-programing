#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

const ll MOD = 998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(n * m + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        dp[1][i] = 1;
    }
    for (int v = 1; v < n; v++)
    {
        for (int i = 1; i <= n * m; i++)
        {
            for (int x = 1; x <= m; x++)
            {
                if(i + x > n * m)    continue;
                dp[v + 1][i + x] += dp[v][i];
                dp[v + 1][i + x] %= MOD;
            }
        }
    }

    //rep(i, n * m + 1)   cout << i << ' ';
    //cout << endl;
    //for(auto &vec: dp)
    //{
    //    for(auto &x: vec)
    //        cout << x << ' ';
    //    cout << endl;
    //}

    ll ans = 0;
    for(int i = 0; i <= k; i++)
    {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}