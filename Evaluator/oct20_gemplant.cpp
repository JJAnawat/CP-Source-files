#include<bits/stdc++.h>

using namespace std;

int n;
long long fw[200005];

void upd(int x,int v){
    for(int i=x;i<=200000;i+=i&-i)
        fw[i]+=v;
}

long long qr(int x){
    long long sum=0;
    for(int i=x;i>0;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q,op,a,b;
    cin >> n >> q;
    while(q--){
        cin >> op >> a >> b;
        if(op==1)
            upd(b,a);
        else
            cout << qr(b)-qr(a-1) << '\n';
    }
}
