#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    string s;   cin >> s;
    int ans;
    if(s[0] == s[1] && s[1] == s[2]){
        ans = 1;
    }else if(s[0] != s[1] && s[1] != s[2] && s[2] != s[0]){
        ans = 6;
    }else{
        ans = 3;
    }
    cout << ans << endl;
    return 0;
}