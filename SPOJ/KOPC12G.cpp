#include<bits/stdc++.h>

using namespace std;

int ar[505][505];
long long fw[505][505];

void upd(int x,int y,int v){
    for(int i=x;i<=500;i+=i&-i){
        for(int j=y;j<=500;j+=j&-j){
            fw[i][j]+=v;
        }
    }
}

long long qr(int x,int y){
    long long sum=0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j){
            sum+=fw[i][j];
        }
    }
    return sum;
}

long long qr2(int a,int b,int c,int d){
    return qr(c,d)-qr(a-1,d)-qr(c,b-1)+qr(a-1,b-1);
}

void sol(){
    int n,q;
    cin >> n >> q;
    string s;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=1;j<=n;j++){
            ar[i][j]=s[j-1]-'A'+1;
            upd(i,j,ar[i][j]);
        }
    }
    int op,a,b,c,d;
    while(q--){
        cin >> op >> a >> b;
        if(!op){
            cin >> s;
            b++;
            if(!a){
                for(int i=1;i<=n;i++){
                    int tmp=ar[b][i];
                    ar[b][i]=s[i-1]-'A'+1;
                    upd(b,i,ar[b][i]-tmp);
                }
            }else{
                for(int i=1;i<=n;i++){
                    int tmp=ar[i][b];
                    ar[i][b]=s[i-1]-'A'+1;
                    upd(i,b,ar[i][b]-tmp);
                }
            }
        }else{
            cin >> c >> d;
            cout << qr2(a+1,b+1,c+1,d+1) << "\n";
        }
    }
    memset(fw,0,sizeof(fw));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        sol();
        cout << '\n';
    }
}

