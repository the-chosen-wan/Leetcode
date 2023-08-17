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

vector<int> solve(int N,int M ,vector<int>& A,vector<int>& B, vector<int>& C){

    vector<int> hero(N);
    vector<pii> coin(N);

    for(int i=0;i<N;i++){
        hero[i] = A[i];
    }

    for(int i=0;i<M;i++){
        coin[i].first = B[i];
    }

    for(int i=0;i<M;i++){
        coin[i].second=C[i];
    }


    sort(coin.begin(),coin.end());

    vector<int> pref(M);
    pref[0] = coin[0].second;

    for(int i=1;i<M;i++){
        pref[i] = pref[i-1]+coin[i].second;
    }

    vector<int> ans(N,0);

    for(int i=0;i<N;i++){
        auto iter = upper_bound(coin.begin(),coin.end(),mp(hero[i],inf));

        if(iter==coin.end()){
            ans[i] = pref[M-1];
        }

        else{
            int ind = iter - coin.begin() - 1;
            ans[i] = pref[ind];
        }
    }

    return ans;
}

int main(){
    int N;
    cin>>N;
    int M;
    cin>>M;

    vector<int> hero(N);
    vector<pii> coin(N);

    for(int i=0;i<N;i++){
        cin>>hero[i];
    }

    for(int i=0;i<M;i++){
        cin>>coin[i].first;
    }

    for(int i=0;i<M;i++){
        cin>>coin[i].second;
    }


    sort(coin.begin(),coin.end());

    vector<int> pref(M);
    pref[0] = coin[0].second;

    for(int i=1;i<M;i++){
        pref[i] = pref[i-1]+coin[i].second;
    }

    vector<int> ans(N,0);

    for(int i=0;i<N;i++){
        auto iter = upper_bound(coin.begin(),coin.end(),mp(hero[i],inf));

        if(iter==coin.end()){
            ans[i] = pref[M-1];
        }

        else{
            int ind = iter - coin.begin() - 1;
            ans[i] = pref[ind];
        }
    }

    for(int i=0;i<N;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}