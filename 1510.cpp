#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define pf push_front
#define mp make_pair
#define N ((1e5)+1)

bool canwin(int n){
    vector<int> squares;
    int c=1;

    while(true){
        if(c*c>N)
            break;
        squares.pb(c*c);
        c++;
    }

    vector<bool> ispos(n+1,true);
    ispos[1] = true;

    for(int i=2;i<=n;i++){
        for(int val:squares){
            if(i-val<0)
                break;
            ispos[i] = ispos[i]&ispos[i-val];
            if(!ispos[i])
                break;
        }
        ispos[i] = !ispos[i];
    }
    return ispos[n];
}

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        return canwin(n);
    }
};