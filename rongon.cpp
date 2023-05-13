#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int abs(int x){
    return x>0?x:-x;
}

bool ord2(int x){
    x/=2;
    return x%2!=0;
}

bool ord22(int x){
    x/=2;
    if(x%2!=0)
        return false;
    x/=2;
    return x%2!=0;
}

int main(){
    int n;cin>>n;
    vector<int> dp(n+1,0);

    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp[i]+=dp[i-j*j];
        }
        dp[i]*=-2;
    }

    for(int& x:dp)
        x=abs(x);
    bool check1 =true;

    for(int i=1;i*i<=n;i++)
        if(!ord2(dp[i*i]))
            {check1=false;break;}
    cout<<check1<<endl;

    bool check2 = true;

    for (int i = 1; 2*i * i <= n; i++)
        if (!ord22(dp[2*i * i]))
        {
            check2 = false;
            break;
        }
    cout << check2 << endl;
}
