#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &fruits, int start, int k)
{
    int n = fruits.size();

    vector<pii> lesser;
    vector<pii> greater;

    for(int i=0;i<n;i++){
        if(fruits[i][0]<=start){
            lesser.pb(mp(fruits[i][0],fruits[i][1]));
        }

        else
            greater.pb(mp(fruits[i][0],fruits[i][1]));
    }

    sort(lesser.begin(),lesser.end());
    sort(greater.begin(),greater.end());

    int l = lesser.size();
    int g = greater.size();

    vector<int> lesuf(l,0);
    vector<int> grepref(g,0);

    if(l>0)
        lesuf[l-1] = lesser[l-1].second;

    if(g>0)
        grepref[0] = greater[0].second;

    for(int i=l-2;i>=0;i--){
        lesuf[i] = lesuf[i+1] + lesser[i].second;
    }

    for(int i=1;i<g;i++){
        grepref[i] = grepref[i-1] + greater[i].second;
    }

    int amt = 0;

    for(int i=l-1;i>=0;i--){
        int temp = k;
        temp -= (start - lesser[l-1].first);

        int val = 0;

        if(temp >= 2*(lesser[l-1].first - lesser[i].first)){
            val+=lesuf[i];
            temp -= 2*(lesser[l-1].first - lesser[i].first);
        }

        temp-= (start - lesser[l-1].first);
        if(greater.size()>0){
            temp -= (greater[0].first - start);

            if(temp>=0){
                temp += greater[0].first;
                auto ptr = upper_bound(greater.begin(),greater.end(),mp(temp,inf));

                if(ptr!=greater.begin()){
                    val+= grepref[ptr-greater.begin()-1];
                }
                
            }
        }

        amt = max(amt,val);
    }

   for(int i=0;i<g;i++){
        int temp = k;
        temp -= (greater[0].first - start);

        int val = 0;

        if(temp >= 2*(greater[i].first - greater[0].first)){
            val+=grepref[i];
            temp -= 2*(greater[i].first - greater[0].first);
        }

        temp-= (greater[0].first - start);
        if(lesser.size()>0){
            temp -= (start-lesser[l-1].first);

            if(temp>=0){
                temp  = lesser[l-1].first-temp;
                auto ptr = lower_bound(lesser.begin(),lesser.end(),mp(temp,-inf));

                if(ptr!=lesser.end()){
                    val+= lesuf[ptr-lesser.begin()];
                }
                
            }
        }

        amt = max(amt,val);
    }
    int temp = k;
    if(greater.size()>0){
        k-=(greater[0].first - start);
        k+=greater[0].first;

        auto ptr = upper_bound(greater.begin(),greater.end(),mp(k,inf));

        if(ptr!=greater.begin()){
            amt=max(amt,grepref[ptr-greater.begin()-1]);
        }
    }

    k = temp;
    if(lesser.size()>0){
        k-=(start - lesser[l-1].first);
        k = (lesser[l-1].first-k);

        auto ptr = lower_bound(lesser.begin(),lesser.end(),mp(k,-inf));

        if(ptr!=lesser.end()){
            amt=max(amt,lesuf[ptr-lesser.begin()]);
        }
    }
    return amt;
}

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        return ans(fruits,startPos,k);
    }
};

// int main(){
//     vector<vector<int>> v = {{20000,10000}};
//     cout<<ans(v,20000,20000)<<endl;
//     return 0;
// }
