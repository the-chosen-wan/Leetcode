#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair


int ans(vector<int>& buses,vector<int>& passengers,int capacity){
    int n = buses.size();
    int m = passengers.size();

    sort(buses.begin(),buses.end());
    sort(passengers.begin(),passengers.end());

    int busind = 0;

    int currbus = capacity;
    int prevfree;
    for(int i=0;i<m;i++){
        if(busind==n){
            return prevfree;
        }

        if(passengers[i]<=buses[busind]&&capacity>0){
            continue;
        }

        else{
            if(capacity==0){
                busind++;
            }

            else{
                capacity--;
            }
        }

        if(i!=0){
            prevfree = passengers[i-1]+1==passengers[i] ? prevfree : passengers[i]-1;
        }
    }

    return buses[n-1];
}

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        return ans(buses,passengers,capacity);
    }
};