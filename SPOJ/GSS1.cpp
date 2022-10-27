#include<bits/stdc++.h>

using namespace std;

struct Node{
    long long pre=0,suf=0,mid=0,sum=0;
};

int n;
long long ar[50005];
Node seg[1<<17];
Node minnode;

Node merge(Node l,Node r){
    Node tmp;
    if(l.sum==-1e18)
        tmp.sum=r.sum;
    else if(r.sum==-1e18)
        tmp.sum=l.sum;
    else
        tmp.sum=l.sum+r.sum;
    tmp.pre=max(l.pre,l.sum+r.pre);
    tmp.suf=max(r.suf,r.sum+l.suf);
    tmp.mid=max({l.suf+r.pre,l.mid,r.mid});
    return tmp;
}

void build(int l,int r,int i){
    if(l==r){
        seg[i].pre=seg[i].suf=seg[i].mid=seg[i].sum=ar[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=merge(seg[2*i],seg[2*i+1]);
}

Node query(int l,int r,int i,int x,int y){
    if(l>y||r<x)
        return minnode;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    return merge(query(l,m,2*i,x,y),query(m+1,r,2*i+1,x,y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    minnode.pre=minnode.suf=minnode.mid=minnode.sum=-1e18;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> ar[i];
    build(1,n,1);

    int qr,x,y;
    cin >> qr;
    while(qr--){
        cin >> x >> y;
        if(x>y){
            cout << -1000000 << '\n';
            continue;
        }
        Node ans=query(1,n,1,x,y);
        cout << max({ans.sum,ans.mid,ans.pre,ans.suf}) << '\n';
        //cout << ans.sum << " " << ans.mid << " " <<  ans.pre << ' ' << ans.suf << '\n';
    }
}
