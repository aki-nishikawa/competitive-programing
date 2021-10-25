#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 998244353;
int main(){
    int n,m,a,b;    cin >> n >> m >> a >> b;
    vector<vector<ll>> dp(m+1, vector<ll>(n+1, 0));
    dp[0][0] = 1;
    rep(i, n+1){
        if(i == a && b == 0){
            //cout << 'a' << endl;
            break;
        }
        dp[0][i] = 1;
    }
    rep(j, m+1){
        if(a == 0 && j == b){
            //cout << 'b' << endl;
            break;
        }
        dp[j][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == a && j == b)    dp[j][i] = 0;
            else    dp[j][i] = dp[j-1][i] + dp[j][i-1];
            dp[j][i] %= MOD;
        }
    }
    //rep(j, m+1){
    //    rep(i, n+1) cout << dp[j][i] << ' ';
    //    cout << endl;
    //}
    cout << dp[m][n] << endl;
    return 0;
}