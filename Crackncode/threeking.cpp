#include<bits/stdc++.h>

using namespace std;

const int MXN=2e5+5;

int n,m,q;
int L[MXN],R[MXN],seg[MXN<<1],p[MXN];
vector<tuple<int,int,int>> v;
vector<int> ask[MXN];

void build(int l,int r,int i){
    if(l==r){
        seg[i]=0;
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=max({seg[2*i],seg[2*i+1],L[m]});
}

int qr(int l,int r,int i,int x,int y){
    if(l>y||r<x)
        return INT_MIN;
    if(l>=x&&r<=y){
        //printf("x = %d , l = %d , r = %d , y = %d , i = %d , seg[i] = %d\n",x,l,r,y,i,seg[i]);
        return seg[i];
    }
    int m=(l+r)/2;
    int al=qr(l,m,2*i,x,y),ar=qr(m+1,r,2*i+1,x,y);
    int aa=max(al,ar);
    if(al!=INT_MIN&&ar!=INT_MIN)
        aa=max(aa,L[m]);
    return aa;
}

int fd(int i){
    if(p[i]==i)
        return i;
    return p[i]=fd(p[i]);
}

void mrg(int x,int y){
    int px=fd(x),py=fd(y);
    if(px==py)
        return;
    p[px]=py;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    v.push_back({0,0,0});
    for(int i=0,x,y,z;i<m;i++){
        cin >> x >> y >> z;
        v.push_back({x,y,z});
    }

    for(int i=1;i<=n;i++){
        L[i]=1;
        R[i]=m+1;
    }

    while(1){
        bool chk=1;
        for(int i=1;i<n;i++){
            if(L[i]!=R[i]){
                chk=0;
                ask[(L[i]+R[i])/2].push_back(i);
            }
        }
        if(chk)
            break;

        for(int i=1;i<=n;i++)
            p[i]=i;

        for(int i=1;i<=m;i++){
            int x,y,z;
            tie(x,y,z)=v[i];
            mrg(x,y);
            mrg(y,z);
            for(auto it:ask[i]){
                if(fd(it)==fd(it+1))
                    R[it]=i;
                else
                    L[it]=i+1;
            }
            ask[i].clear();
        }
    }

    build(1,n,1);

    int Ql,Qr,ans;
    while(q--){
        cin >> Ql >> Qr;
        ans=qr(1,n,1,Ql,Qr);

        if(ans>m)
            cout << -1;
        else
            cout << ans;
        cout << "\n";

    }
}
/*
7 3 4
1 2 3
3 4 5
5 6 7
6 7
5 7
1 5
1 7
*/
//1 1-7
//2 1-4 3 5-7
//4 1-2 5 3-4 6 5-6 7 7-7
//8 1-1 9 2-2 10 3-3 11 4-4 12 5-5 13 6-6 14 7-7
