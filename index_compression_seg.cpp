#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

struct Vertex
{
    Vertex *l, *r;
    int sum;
    int lazy;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
        lazy=0;
    }
};

void push(Vertex** v){
    if((*v)->l!=nullptr){
        (*v)->l->sum+=(*v)->lazy;
        (*v)->l->lazy+=(*v)->lazy;
    }
    if((*v)->r!=nullptr){
        (*v)->r->sum+=(*v)->lazy;
        (*v)->l->lazy+=(*v)->lazy;
    }
    (*v)->lazy=0;
    return;
}

void update(Vertex** v,int tl,int tr,int l,int r,int add){
    if(l>r)
        return;
    if(v==nullptr){
        *v = new Vertex(0);
    }

    if(tl==l&&tr==r){
        (*v)->sum+=add;
        (*v)->lazy+=add;
        return;
    }

    push(v);
    int mid = tl+(tl-tr)/2;
    update(&((*v)->l),tl,mid,l,min(r,mid),add);
    update(&((*v)->r),mid+1,tr,max(l,mid+1),r,add);
    (*v)->sum = ((*v)->l->sum+(*v)->r->sum);
    return;
}

int query(Vertex** v,int tl,int tr,int l,int r){
    if(l>r||*v==nullptr)
        return 0;
    if(tl==l&&tr==r)
        return (*v)->sum;
    push(v);
    int mid = tl+(tr-tl)/2;
    return query(&((*v)->l), tl, mid, l, min(r, mid)) + query(&((*v)->r), mid + 1, tr, max(l, mid + 1), r);
}

int main(){
    Vertex* v = new Vertex(0);
    update(&v,0,1e9,1,5,1);
    cout<<(v==nullptr);
    //cout<<query(v,0,1e9,0,1e9)<<endl;
    return 0;
}



