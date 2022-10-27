#include<bits/stdc++.h>

using namespace std;

long long q,k;
long long ans=0;
bool btk[35],chk=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q >> k;

    for(int i=0;i<=30;i++){
        if(k&(1<<i))
            btk[i]=1;
    }

    for(int i=1,c;i<=q;i++){
        cin >> c;
        ans=0;
        chk=1;
        for(int b=0;b<=30;b++){
            if(c&(1<<b)){
                if(!btk[b]){
                    ans+=(1<<b);
                }
            }else{
                if(btk[b]){
                    cout << -1;
                    chk=0;
                    break;
                }
            }
        }
        if(chk)
            cout << ans;
        cout << '\n';
    }
}
