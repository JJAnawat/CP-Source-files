#include<bits/stdc++.h>

using namespace std;

int n;
long long fw[1050][1050];

void upd(int x,int y,int v){
    for(int i=x;i<=1024;i+=i&-i)
        for(int j=y;j<=1024;j+=j&-j)
            fw[i][j]+=v;
}

long long qr(int x,int y){
    long long sum=0;
    for(int i=x;i>=1;i-=i&-i)
        for(int j=y;j>=1;j-=j&-j)
            sum+=fw[i][j];
    return sum;
}

long long ans(int a,int b,int c,int d){
    return qr(c,d)-qr(c,b-1)-qr(a-1,d)+qr(a-1,b-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int op,a,b,c,d;
    cin >> op >> n;
    while(1){
        cin >> op;
        if(op==3)
            break;
        cin >> a >> b >> c;
        if(op==1){
            upd(a+1,b+1,c);
        }else{
            cin >> d;
            cout << ans(a+1,b+1,c+1,d+1) << '\n';
        }
    }
}
