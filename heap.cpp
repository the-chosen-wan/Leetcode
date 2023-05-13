#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
const int N = 1e6;

class heap{
    private:
        vector<int> values;
        int pos;

        int get_right(int n) { return 2 * n + 1; }

        int get_left(int n) { return 2 * n; }

        int get_parent(int n) { return n / 2; }

        void push_down(int n){
            int right = get_right(n);
            int left = get_left(n);
            int val = values[n];
            int ind = n;

            if(right<pos&&val>values[right]){val=values[right];ind=right;}
            if(left<pos&&val>values[left]){val=values[left];ind=left;}

            if(ind!=n){
                swap(values[n],values[ind]);
                push_down(ind);
            }
            return;
        }

        void push_up(int n){
            int par  = get_parent(n);
            if(par!=0){
                if(values[n]<values[par]){
                    swap(values[n],values[par]);
                    push_up(par);
                }
            }
            return;
        }

    public:

        heap(){
            values = vector<int>(1,0);
            pos=1;
        }

        int get_front(){
            if(pos>1){
                return values[1];
            }
            return -inf;
        }

        int pop_front(){
            if(pos>1){
                int front = get_front();
                swap(values[pos-1],values[1]);
                pos--;
                push_down(1);
                return front;
            }
            return -inf;
        }

        void insert(int val){
            values.pb(val);
            push_up(pos);
            pos++;
            return;
        }
};

int main(){
    heap h;
    for(int i=5000;i<5001;i++)
        h.insert(i);
    cout<<h.pop_front()<<endl;

}