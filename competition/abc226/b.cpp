#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int n;  cin >> n;
    cin.ignore();
    vector<string> s(n);
    map<string, int> mp;
    int ans = 0;
    rep(i, n)
    {
        getline(cin, s[i]);
        if(mp[s[i]] == 0){
            ans++;
            mp[s[i]] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}