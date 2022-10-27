#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

long long mndis=1e16;
vector<pair<long long,long long>> v;
set<pair<long long,long long>> s;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0,a,b;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    int j=0;
    for(int i=0;i<n;i++){
        long long sq_mndis=ceil(sqrt(mndis));
        while(v[i].fi-v[j].fi>sq_mndis){
            s.erase({v[j].se,v[j].fi});
            j++;
        }
        auto it1=s.lower_bound({v[i].se-sq_mndis,v[i].fi});
        auto it2=s.upper_bound({v[i].se+sq_mndis,v[i].fi});
        for(auto it=it1;it!=it2;it++){
            long long dx=it->se-v[i].fi;
            long long dy=it->fi-v[i].se;
            mndis=min(mndis,dx*dx+dy*dy);
        }
        s.insert({v[i].se,v[i].fi});
    }
    cout << mndis;
}
