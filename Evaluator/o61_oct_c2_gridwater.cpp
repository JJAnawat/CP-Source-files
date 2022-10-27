#include<bits/stdc++.h>

using namespace std;

int m,n,p[160005];
int l[160005],r[160005];
vector<tuple<int,int,int>> edge,mst,nmst;
vector<int> ask[160005];

bool cmp(tuple<int,int,int> &t1,tuple<int,int,int> &t2){
    return get<2>(t1)<get<2>(t2);
}

int fi(int i){
    if(p[i]==i)
        return i;
    return fi(p[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    /*
    2 3
    id/n=row
    id%n=col
    0 1 2
    3 4 5
    */
    for(int i=0;i<m*n;i++)
        p[i]=i;
    for(int i=0;i<2*m-1;i++){
        int row=i/2;
        if(!(i%2)){
            for(int j=0,x;j<n-1;j++){
                cin >> x;
                edge.push_back({row*n+j,row*n+j+1,x});
            }
        }else{
            for(int j=0,x;j<n;j++){
                cin >> x;
                edge.push_back({row*n+j,(row+1)*n+j,x});
            }
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    for(auto it:edge){
        int u,v,w;
        tie(u,v,w)=it;
        int pu=fi(u),pv=fi(v);
        if(pu!=pv){
            p[pu]=pv;
            mst.push_back(it);
        }else{
            nmst.push_back(it);
        }
    }

    int szm=mst.size(),szn=nmst.size();
    for(int i=0;i<szn;i++){
        l[i]=0;
        r[i]=szm-1;
    }

    while(1){
        bool done=1;
        for(int i=0;i<szn;i++){
            if(l[i]<r[i]){
                done=0;
                ask[(l[i]+r[i])/2].push_back(i);
            }

        }
        if(done)
            break;

        for(int i=0;i<m*n;i++)
            p[i]=i;
        for(int i=0;i<szm;i++){
            int u,v,w;
            tie(u,v,w)=mst[i];
            int pu=fi(u),pv=fi(v);
            p[pu]=pv;
            for(auto it:ask[i]){
                int uu,vv,ww;
                tie(uu,vv,ww)=nmst[it];
                int puu=fi(uu),pvv=fi(vv);
                if(puu==pvv)
                    r[it]=i;
                else
                    l[it]=i+1;
            }
            ask[i].clear();
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<szn;i++){
        //cout << get<2>(nmst[i]) << ' ' << get<2>(mst[l[i]]) << '\n';
        ans=min(ans,get<2>(nmst[i])-get<2>(mst[l[i]]));
    }
    cout << ans;
}
