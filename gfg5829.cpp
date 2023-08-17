//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

string ans(int s,int d){
    
    if(9*d<s)
        return "-1";
        
    string ans="";

    for(int i=0;i<d;i++){
        if(i==d-1){
            ans+=(s+'0');
            break;
        }
        
        int lowerlimit = i==0?1:0;

        for(int j=lowerlimit;j<=9;j++){
            if(j+9*(d-i-1)>=s){
                s-=j;
                ans+=(j+'0');
                break;
            }
        }
    }
    return ans;
}

class Solution{   
public:
    string smallestNumber(int S, int D){
        return ans(S,D);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends