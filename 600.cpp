#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 33;
ll dp[N][2][2];

template <size_t N>
void reverse(bitset<N> &b)
{
    for (size_t i = 0; i < N / 2; ++i)
    {
        bool t = b[i];
        b[i] = b[N - i - 1];
        b[N - i - 1] = t;
    }
}

ll digit(bitset<N>& b,int pos,int tight,int flag){
    if(pos==N)
        return 1;
    
    if(dp[pos][tight][flag]!=-1)
        return dp[pos][tight][flag];
    
    int k = tight?1:b[pos];
    ll ret = 0;

    for(int i=0;i<=k;i++){
        int newtight;
        if(tight==1)
            newtight = 1;
        else 
            newtight = i<b[pos]?1:0;
        
        if(flag==0)
            ret+=digit(b,pos+1,newtight,i==1);
        if(i==0&&flag==1)
            ret+=digit(b,pos+1,newtight,0);
    }
    dp[pos][tight][flag] = ret;
    //cout<<pos<<" "<<tight<<" "<<flag<<endl;
    return ret;
}

ll func(ll n){
    bitset<N> b(n);
    reverse<N>(b);

    for(int i=0;i<N;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                dp[i][j][k]=-1;
    return digit(b,0,0,0);
}

class Solution
{
public:
    int findIntegers(int n)
    {
        return func(n);
    }
};