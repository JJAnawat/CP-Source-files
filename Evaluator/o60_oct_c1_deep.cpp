#include<bits/stdc++.h>

using namespace std;

struct node{
    int l,r,sz=0;
};

int n,q;
node nd[200005];
vector<int> ch[200005];

int s, a, b;
int dir() {
 int res = ((s & 8) >> 3);
 s = (s * a + b) % 40507;
 return res;
}

void dfs(int u,int p){
    if(u!=p)
        ch[p].push_back(u);
    if(!nd[u].sz)
        return;
    int lc=nd[u].l,rc=nd[u].r;
    if(nd[u].sz==1){
        if(lc==-1)
            dfs(rc,p);
        else
            dfs(lc,p);
    }
    else{
        dfs(lc,lc);
        dfs(rc,rc);
    }
}

int sol(int clv,int tlv,int u){
    if(!nd[u].sz)
        return u;
    if(clv==tlv)
        return u;
    int lc=nd[u].l,rc=nd[u].r,chsz=ch[u].size();
    if(nd[u].sz==1){
        return sol(min(clv+chsz,tlv),tlv,ch[u][min(chsz-1,tlv-clv-1)]);
    }
    else{
        int di=dir();
        if(!di)
            return sol(clv+1,tlv,nd[u].l);
        else
            return sol(clv+1,tlv,nd[u].r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=0,l,r;i<n;i++){
        cin >> nd[i].l >> nd[i].r;
        if(nd[i].l>=0)
            nd[i].sz++;
        if(nd[i].r>=0)
            nd[i].sz++;
    }

    dfs(0,0);

    while(q--){
        int l;
        cin >> l >> s >> a >> b;
        cout << sol(0,l,0) << '\n';
    }
}
