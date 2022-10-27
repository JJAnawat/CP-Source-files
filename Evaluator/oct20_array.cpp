#include<bits/stdc++.h>

using namespace std;

long long n,q;
vector<long long> v;
unordered_map<long long,long long> vtoi;
vector<tuple<int,long long,long long,long long>> oper;
long long seg[1<<19],lz[1<<19];

void pushlz(int l,int r,int i){
    if(!lz[i])
        return;
    //long long rr=itov[r],ll=itov[l];
    seg[i]=(v[r+1]-v[l])*lz[i];
    if(l!=r){
        lz[2*i]=lz[i];
        lz[2*i+1]=lz[i];
    }
    lz[i]=0;
}

void upd(int l,int r,int i,int x,int y,int val){
    pushlz(l,r,i);
    if(l>y||r<x)
        return;
    if(l>=x&&r<=y){
        lz[i]=val;
        pushlz(l,r,i);
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,y,val);
    upd(m+1,r,2*i+1,x,y,val);
    seg[i]=seg[2*i]+seg[2*i+1];
}

long long qr(int l,int r,int i,int x,int y){
    pushlz(l,r,i);
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    return qr(l,m,2*i,x,y)+qr(m+1,r,2*i+1,x,y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i=0,op,a,b,c;i<q;i++){
        cin >> op >> a >> b;
        if(!op)
            cin >> c;
        else
            c=0;
        oper.push_back({op,a,b,c});
        v.push_back(a);
        v.push_back(b);
    }
    v.push_back(0);
    v.push_back(n);

    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    int k=v.size();
    for(int i=0;i<k;i++){
        //cout << i << ' ' << v[i] << '\n';
        vtoi[v[i]]=i;
    }

    //cout << k << '\n';
    //upd(1,k,1,1,5,1);
    for(auto [op,a,b,c]:oper){
        a=vtoi[a];
        b=vtoi[b]-1;
        //cout << a << ' ' << b << '\n';
        if(!op){
            upd(0,k-1,1,a,b,c);
            //cout << qr(1,k,1,a,b) << "\n";
        }else{
            cout << qr(0,k-1,1,a,b) << '\n';
        }
    }
}
