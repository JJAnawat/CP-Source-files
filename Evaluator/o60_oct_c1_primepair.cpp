#include<bits/stdc++.h>

using namespace std;

const int mx=1e6;
int lf[mx],ft[mx];
int a,b,c,d,t1,t2,a1,a2,s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=2;i<=mx;i++){
        if(!lf[i]){
            ft[i]=1;
            for(int j=i+i;j<=mx;j+=i){
                lf[j]=i;
            }
        }
    }

    for(int i=2;i<=mx;i++){
        if(lf[i]){
            ft[i]=ft[i/lf[i]]+1;
        }
    }

    cin >> a >> b >> c >> d;
    for(int i=2;i<=mx;i++){
        t1=(b/i)*i;
        t2=(d/i)*i;
        if(t1>=a&&t2>=c){
            if(ft[i]>s){
                s=ft[i];
                a1=t1;
                a2=t2;
            }
            else if(ft[i]==s){
                if((t1+t2>a1+a2)||((t1+t2==a1+a2)&&t1>t2)){
                    a1=t1;
                    a2=t2;
                }
            }
        }
    }
    cout << a1 << ' ' << a2;
}
