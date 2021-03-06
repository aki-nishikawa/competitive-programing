#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> Eratosthenes(const int N)
{
    vector<bool> is_prime(N+1, true);
    vector<int> prime;
    for(int i=2;i<=N;i++)
    {
        if(is_prime[i]){
            for(int j=2*i;j<=N;j+=i)
            is_prime[j] = false;
            prime.emplace_back(i);
        }
    }
    return prime;
}