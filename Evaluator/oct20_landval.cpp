#include<bits/stdc++.h>

using namespace std;

int n,m;
long long fw[200005];

void upd(int x,int v){
    for(int i=x;i<=200000;i+=i&-i)
        fw[i]+=v;
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

    cin >> n >> m;
    int op,a,b,c;
    while(m--){
        cin >> op >> a;
        if(op==1){
            cin >> b >> c;
            upd(a,c);
            upd(b+1,-c);
        }else{
            cout << qr(a) << '\n';
        }
    }
}
