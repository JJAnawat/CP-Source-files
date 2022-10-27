#include<bits/stdc++.h>

using namespace std;

int n;
double a[20],b[20];
double ans=DBL_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    //if 1 == choose a
    //else == choose b
    double suma,sumb,cnta,cntb;
    for(int st=0;st<=(1<<n)-1;st++){
        suma=sumb=cnta=cntb=0;
        for(int i=0;i<n;i++){
            if(st&(1<<i)){
                cnta++;
                suma+=a[i];
            }else{
                cntb++;
                sumb+=b[i];
            }
        }
        double aa=suma*(100.0-cnta)/100.0;
        double bb=sumb*(100.0-cntb)/100.0;
        ans=min(ans,aa+bb);
    }
    cout << ans;
}
