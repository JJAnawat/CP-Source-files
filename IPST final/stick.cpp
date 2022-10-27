#include "stick.h"
#include<bits/stdc++.h>

using namespace std;

vector<long long> seg[(1<<19)];
int n;
vector<long long> nul;
vector<long long> x;
long long ans=-1;

vector<long long> mer(vector<long long> &v1,vector<long long> &v2){
    vector<long long> ret;
    ret.clear();
    if(v1.empty())
        return v2;
    if(v2.empty())
        return v1;
    int i1=0,i2=0;
    long long a,b,c;
    bool chk=0;
    int sz=0;
    while(i1<v1.size()&&i2<v2.size()){
        if(v1[i1]>v2[i2])
            ret.push_back(v1[i1++]);
        else
            ret.push_back(v2[i2++]);
        ++sz;
        if(sz>=3){
            a=ret[sz-3];
            b=ret[sz-2];
            c=ret[sz-1];
            if(b+c>a){
                chk=1;
                break;
            }
        }
    }
    if(chk)
        return ret;
    while(i1<v1.size())
        ret.push_back(v1[i1++]);
    while(i2<v2.size())
        ret.push_back(v2[i2++]);
    return ret;
}

void build(int l,int r,int i){
    if(l==r){
        seg[i].push_back(x[l]);
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=mer(seg[2*i],seg[2*i+1]);
}

vector<long long> qr(int l,int r,int i,int x,int y){
    if(l>y||r<x)
        return nul;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    vector<long long> v1=qr(l,m,2*i,x,y);
    vector<long long> v2=qr(m+1,r,2*i+1,x,y);
    return mer(v1,v2);
}

void init(int N, vector<int> X){
    n=N;
    x.resize(n);
    nul.clear();
    for(int i=0;i<n;i++)
        x[i]=X[i]*1LL;
    build(0,n-1,1);
    return;
}

//cannot do offline query
int max_length(int L,int R){
    vector<long long> v=qr(0,n-1,1,L,R);
    int sz=v.size();
    ans=-1;
    if(sz>=3){
        for(int i=0;i+2<sz;i++){
            if(v[i+1]+v[i+2]>v[i]){
                ans=v[i]+v[i+1]+v[i+2];
                break;
            }
        }
    }
    return ans;
}
