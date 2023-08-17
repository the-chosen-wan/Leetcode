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
const int N = (1e6)+1;

int solve(int N,int K,vector<int>& nums){
    int n = N;
    int k = K;

    int zero=0;
    map<int,int> setta;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
                continue;
            }

            int square_root = sqrt(nums[i]) + 1;
            for (int j = 1; j < square_root; j++) { 
                if (nums[i] % j==0 && j*j!=nums[i]){
                    setta[j]++;
                    setta[nums[i]/j]++;
                }
                else if(nums[i]%j==0 && j*j==nums[i]){
                    setta[j]++;
                }
            }
        }


        vector<int> s;

        for(pii v:setta){
            if(v.second+zero>=k)
                s.pb(v.first);
        }

        return *max_element(s.begin(),s.end());
}

int main(){
    int T;cin>>T;
    while(T--){
        map<int,int> setta;
        int n;cin>>n;
        int k;cin>>k;

        vector<int> nums(n,0);
        int zero=0;

        for(int i=0;i<n;i++)
            cin>>nums[i];
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
                continue;
            }

            int square_root = sqrt(nums[i]) + 1;
            for (int j = 1; j < square_root; j++) { 
                if (nums[i] % j){
                    setta[j]++;
                    setta[nums[i]/j]++;
                }
            }
        }


        vector<int> s;

        for(pii v:setta){
            if(v.second+zero>=k)
                s.pb(v.first);
        }

        return *max_element(s.begin(),s.end());
    }
}