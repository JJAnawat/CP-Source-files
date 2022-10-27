#include<bits/stdc++.h>

using namespace std;

long long n,k;
long long qs[1000005],ans=LLONG_MIN;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
        if(i-k>=0){
            ans=max(ans,qs[i]-qs[i-k]);
        }
    }
    cout << ans;
}
