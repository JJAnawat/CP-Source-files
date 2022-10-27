#include<bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    int pre,dif;
    cin >> pre;
    for(int i=2,now;i<=m;i++){
        cin >> now;
        dif=now-pre;
        if(dif!=0)
            dif--;
        v.push_back(dif);
        pre=now;
    }
    sort(v.rbegin(),v.rend());
    long long ans=0;
    for(int i=k-1;i<v.size();i++)
        ans+=v[i];
    cout << ans;
}
