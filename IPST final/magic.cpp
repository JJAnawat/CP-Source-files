#include "magic.h"
#include <bits/stdc++.h>

using namespace std;

int n,m;
int dis[200005];
bitset<200005> iscut(0);
vector<pair<int,int>> rg[200005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void dijk(int u){
    while(!pq.empty())
        pq.pop();
    pq.push({dis[u],u});
    while(!pq.empty()){
        auto [du,u]=pq.top();
        pq.pop();

        if(dis[u]!=du)
            continue;

        int w=0;
        for(auto [v,i]:rg[u]){
            w=0;
            if(iscut[i])
                w=1;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}

vector<int> magic(int N, int M,int Q, vector<int>U, vector<int> V, vector<vector<int> >q){
  	vector<int>ans;
  	n=N;
  	m=M;
  	for(int i=0;i<n;i++)
        dis[i]=11;
    for(auto v:q){
        if(v[0]==0)
            iscut[v[1]]=1;
    }
    for(int i=0;i<m;i++)
        rg[V[i]].push_back({U[i],i});
    dis[0]=0;
    dijk(0);
    reverse(q.begin(),q.end());
    for(auto v:q){
        if(v[0]==0){
            iscut[v[1]]=0;
            dijk(V[v[1]]);
            ans.push_back(-1);
        }
        else{
            if(dis[v[1]]<=v[2])
                ans.push_back(1);
            else
                ans.push_back(0);
        }
    }
    reverse(ans.begin(),ans.end());
  	return ans;
}
