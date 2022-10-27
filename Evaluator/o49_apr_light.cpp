#include<bits/stdc++.h>

using namespace std;

struct node{
    long long l,r,v;
};

const int mxn=1e5+5;
long long L,N,ar[mxn];
node seg[mxn<<1];
bool lz[mxn<<1];
unordered_map<long long,int> ump;

void mer(int cur,int lc,int rc){
    seg[cur].l=seg[lc].l;
    seg[cur].r=seg[rc].r;
    seg[cur].v=seg[lc].v+seg[rc].v;
}

void build(int l,int r,int i){
    if(l==r){
        seg[i].l=ar[l-1];
        seg[i].r=ar[l];
        seg[i].v=ar[l]-ar[l-1];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    mer(i,2*i,2*i+1);
}

void pushlz(int l,int r,int i){
    if(!lz[i])
        return;
    lz[i]=0;
    seg[i].v=seg[i].r-seg[i].l-seg[i].v;
    if(l!=r){
        lz[2*i]=!lz[2*i];
        lz[2*i+1]=!lz[2*i+1];
    }
}

void upd(int l,int r,int i,int x,int y){
    pushlz(l,r,i);
    if(l>y||r<x)
        return;
    if(l>=x&&r<=y){
        lz[i]=!lz[i];
        pushlz(l,r,i);
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,y);
    upd(m+1,r,2*i+1,x,y);
    mer(i,2*i,2*i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> N;
    vector<long long> v;
    for(int i=1;i<=N;i++){
        cin >> ar[i];
        v.push_back(ar[i]);
    }
    ar[0]=0;
    ar[N+1]=L;
    sort(ar,ar+N+1);

    build(1,N+1,1);

    for(int i=1;i<=N+1;i++)
        ump[ar[i]]=i;

    for(int i=0;i<N;i++){
        upd(1,N+1,1,ump[v[i]]+1,N+1);
        cout << seg[1].v << "\n";
    }
}
