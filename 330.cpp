#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int get_highest(int n){
    int c = 0;
    for(int i=0;i<15;i++)
        if(n&(1<<i))
            c = i;
    return ++c;
}

int get_minimum(vector<int>& nums){

}

// int main(){
//     int num;cin>>num;vector<int> a(num);
//     for(int i=0;i<num;i++)
//         cin>>a[i];
//     int n;cin>>n;
//     cout<<maximum(a,n);
// }