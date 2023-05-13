#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[10][2][100];

ll digit(int pos,int tight, int sum, int digits[]){
    if(pos==10){
        return sum;
    }

    if(dp[pos][tight][sum]!=-1)
        return dp[pos][tight][sum];
    
    int k = tight?9:digits[pos];
    ll ret = 0;

    for(int i=0;i<=k;i++){
        int newtight;
        if (tight == 1)
            newtight = 1;
        else
            newtight = (i < digits[pos]) ? 1 : 0;
        ret+=digit(pos+1,newtight,sum+(i==1),digits);
    }

    dp[pos][tight][sum]=ret;
    return ret;
}

class Solution
{
public:
    int countDigitOne(int n)
    {
        int digits[10];
        for (int i = 9; i >= 0; i--)
        {
            digits[i] = n % 10;
            n /= 10;
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 100; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }

        return digit(0,0,0,digits);
    }
};

int main(){
    int n;cin>>n;
    int digits[10];
    for(int i=9;i>=0;i--){
        digits[i] = n%10;
        n/=10;
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<100;k++){
                dp[i][j][k]=-1;
            }
        }
    }

    cout<<digit(0,0,0,digits)<<endl;
}