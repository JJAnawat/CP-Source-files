#include<bits/stdc++.h>

using namespace std;

long long c[25],ans;
bool pos=1;

void sol(long long n,long long w){
    if(w<=0){
        pos=0;
        return;
    }
    if(n==1){
        ans+=w;
        return;
    }
    if(!pos)
        return;
    w=w*2+1-c[n-1];
    long long a=w/2;
    long long b=w-a;
    sol(n-1,a);
    sol(n-1,b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,w;
    cin >> n >> w;
    for(int i=1;i<n;i++)
        cin >> c[i];
    sol(n,w);
    if(!pos)
        ans=-1;
    cout << ans;
}
