#include<bits/stdc++.h>

using namespace std;

int pa[100005],n;
vector<pair<int,int>> v;

int fi(int i){
    if(pa[i]==i)
        return i;
    return pa[i]=fi(pa[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1,a;i<=n;i++){
        cin >> a;
        v.push_back({a,i});
        pa[i]=i;
    }
    sort(v.begin(),v.end());
    for(int i=1,a,b;i<=n-2;i++){
        cin >> a >> b;
        a=fi(a);
        b=fi(b);
        pa[a]=b;
    }

    int ans=INT_MAX;
    for(int i=0;i+1<n;i++){
        //cout << v[i].second << '\n';
        int l=fi(v[i].second);
        int r=fi(v[i+1].second);
        if(l!=r){
            ans=min(ans,v[i+1].first-v[i].first);
        }

    }
    cout << ans;
}
