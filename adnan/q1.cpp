#include<iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

string ans(string s){
    int n = s.length();

    if(n==1)
        return "IMPOSSIBLE";

    int limit = n/2;

    int numa = 0;

    for(int i=0;i<limit;i++){
        if(s[i]=='a')
            numa++;
    }

    if(numa==limit){
        s[n-1]='b';
    }       

    else{
        for(int i=0;i<limit;i++){
            if(s[i]!='a'){
                s[i]='a';
                return s;
            }
        }
    }

    return s;
}

int main(){
    string s;cin>>s;
    cout<<ans(s)<<endl;
}