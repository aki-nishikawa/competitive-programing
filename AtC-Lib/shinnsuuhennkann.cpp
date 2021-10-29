#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//進数変換

ll binary(ll before, ll rule){
    ll ans = 0;
    for (int i = 0; before>0 ; i++)
    {
        ans = ans+(before%rule)*pow(10,i);
        before = rule/8;
    }
    return ans;
}