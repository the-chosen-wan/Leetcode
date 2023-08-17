#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>>& statements){
    int n = statements.size();
    int mask = (1<<n);
    int maxa = -inf;

    for(int i=0;i<mask;i++){
        int flag = true;

        for(int j=0;j<n;j++){
            int good1 = (i&(1<<j))!=0;
            for(int k=0;k<n;k++){
                int good2 = (i&(1<<k))!=0;

                if(j==k)
                    continue;
                
                if(good1==1&&statements[j][k]==0&&good2==1){
                    flag=false;
                    break;
                }

                if(good1==1&&statements[j][k]==1&&good2==0){
                    flag=false;
                    break;
                }
            }

            if(!flag)
                break;
        }

        if(flag){
            maxa = max(maxa,__builtin_popcount(i));
        }
    }

    return maxa;
}

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        return ans(statements);
    }
};