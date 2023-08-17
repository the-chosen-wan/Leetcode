#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
const int N  =26;

string ans(string s){
    int n = s.length();
    vector<pii> pairs(N,mp(-1,-1));

    for(int i=0;i<n;i++){
        if(pairs[s[i]-'a'].first==-1)
            pairs[s[i]-'a'].first = i;
        
        pairs[s[i]-'a'].second=i;
    }

    vector<pii> finalpos;

    for(int i=N-1;i>=0;i--){
        if(pairs[i].first==-1)
            continue;
        
        int summa=0;

        int p = finalpos.size();

        if(p==0)
            finalpos.pb(mp(pairs[i].first,i));

        else{
            int summalow = 0;
            int summahigh = 0;

            for(int j=0;j<p;j++){
                if(finalpos[j].first<pairs[i].first)
                    summalow++;
                if(finalpos[j].first<pairs[i].second)
                    summahigh++;
            }

            if(summahigh==summalow){
                finalpos.pb(mp(pairs[i].first,i));
            }

            else{
                finalpos.pb(mp(pairs[i].second,i));
            }
        }
    }

    sort(finalpos.begin(),finalpos.end());
    string ans = "";

    int f = finalpos.size();

    for(int i=0;i<f;i++){
        ans+=finalpos[i].second+'a';
    }

    return ans;
}

int main(){
    string s;cin>>s;
    cout<<ans(s)<<endl;
}