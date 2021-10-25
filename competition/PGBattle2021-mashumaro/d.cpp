#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 998244353;
int main(){
    int n;  cin >> n;
    vector<ll> a(n), s(n), sum_s(n);
    rep(i, n)   cin >> a[i];
    rep(i, n)   cin >> s[i];
    sum_s[0] = s[0];
    rep(i, n-1){
        sum_s[i+1] = sum_s[i] + s[i+1];
        sum_s[i+1] %= MOD;
    }
    ll ans = 0;
    int j = 0;
    map<ll, int> mp;
    rep(i, n){
        if(j == n){
            ans += sum_s[j-i-1];
        }else{
            while(mp[a[j]] == 0){
                mp[a[j]]++;
                j++;
                if(j == n)  break;
            }
            ans += sum_s[j-i-1];
        }
        //cout << sum_s[j-i-1] << endl;
        mp[a[i]]--;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}