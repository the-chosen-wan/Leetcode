#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 32

int ans(int num1,int num2){
    int set2 = __builtin_popcount(num2);
    int set1 = __builtin_popcount(num1);
    int x=0;

    int cnt=0;
    for(int i=N-1;i>=0;i--){
        if((num1&(1<<i))!=0&&cnt<set2)
            {x^=(1<<i);cnt++;}
    }

    if(cnt<set2){
        for(int i=0;i<N;i++){
            if((num1&(1<<i))==0&&cnt<set2)
            {x^=(1<<i);cnt++;}
        }
    }
    return x;
}

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        return ans(num1,num2);
    }
};