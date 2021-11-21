#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

const int MAX = 100;
const int MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int n, K;   cin >> n >> K;
    ll ans = 0;
    COMinit();
    for(int i = 1; i <= n; i++)
    {
        if(i == 1){
            ans = 1;
            continue;
        }
        ll score = 1;
        rep(j, K)
        {
            score *= i;
            score %= MOD;
        }
        ll cnt = 0;
        for(int j = 1; j <= n/i; j++){
            ll c = n;
            for(int k = n-1; k > n - i*j; k--){
                n *= k;
                n %= MOD;
            }
            cnt += c;
            cnt %= MOD;
        }   
        cout << score << ':' << cnt << endl;
        ans += score * cnt;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}