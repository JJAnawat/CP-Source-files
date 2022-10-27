#include<bits/stdc++.h>

using namespace std;

long long n,m;
long long fw[3][100005];
/*
fw[0]=height
fw[1]=go up
fw[2]=go down
*/

void upd(int k,int x,int v){
    for(int i=x;i<=100000;i+=i&-i)
        fw[k][i]+=v;
}

long long qr(int k,int x){
    long long sum=0;
    for(int i=x;i>=1;i-=i&-i)
        sum+=fw[k][i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int t,a,b;
    while(m--){
        cin >> t >> a >> b;
        if(t==1){
            if(qr(0,a-1)==qr(0,a))
                upd(1,a,1);
            if(qr(0,b)==qr(0,b+1))
                upd(2,b+1,1);
            upd(0,a,1);
            upd(0,b+1,-1);
            if(qr(0,a-1)==qr(0,a))
                upd(2,a,-1);
            if(qr(0,b)==qr(0,b+1))
                upd(1,b+1,-1);
        }else if(t==2){
            cout << qr(0,a) << ' ' << qr(0,b) << '\n';
        }else{
            cout << qr(0,a) << ' ' << qr(0,b) << " " << qr(1,b)-qr(1,a) << ' ' << qr(2,b)-qr(2,a) << "\n";
        }
    }
}
