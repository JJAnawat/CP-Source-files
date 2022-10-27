#include<bits/stdc++.h>

using namespace std;

long long fw[100005],ar[100005],n;
unordered_map<long long,int> ump;
vector<long long> v;

void upd(int x){
    for(int i=x;i<=100000;i+=i&-i)
        fw[i]++;
}

long long qr(int x){
    long long sum=0;
    for(int i=x;i>=1;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ar[i];
        v.push_back(ar[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
        ump[v[i]]=i+1;
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        upd(ump[ar[i]]);
        ans+=qr(ump[ar[i]]-1);
    }
    cout << ans;
}

