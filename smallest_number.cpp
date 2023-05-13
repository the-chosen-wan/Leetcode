#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int main(){
    int T;cin>>T;
    while(T--){
        int n,x;cin>>n>>x;

        int cnt = 0;bool flag=false;
        for(int i=31;i>=0;i--){
            if(n<=x){
                cnt++;
                break;
            }
            if((n&(1<<i))!=0){
                if(i==0)
                    {flag=true;break;}
                if(i&1)
                    cnt+=1;
                else
                    cnt+=2;
                n-=(1<<i);
            }
        }
        if(flag)
            cout<<-1<<endl;
        else
            cout<<cnt<<endl;
    }
}