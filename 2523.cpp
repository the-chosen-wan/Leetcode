#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

vector<int> ans(int left,int right){
    vector<int> primes;

    vector<bool> isprime(right+1,true);

    for(int i=2;i<=right;i++){
        if(isprime[i]){
            
            if(i>=left)
                primes.pb(i);

            for(int j=2*i;j<=right;j+=i)
                isprime[j]=false;
        }
    }

    int mindif = inf;
    vector<int> ans;

    int n = primes.size();

    for(int i=0;i<n-1;i++){
        if(primes[i+1]-primes[i]<mindif){
            mindif = primes[i+1]-primes[i];
            ans = {primes[i],primes[i+1]};
        }
    }

    if(ans.size()==0)
        ans={-1,-1};
    return ans;
}

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        return ans(left,right);
    }
};