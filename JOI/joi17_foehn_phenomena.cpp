#include<bits/stdc++.h>

using namespace std;

long long n,q,s,t;
long long ar[200005],dif[200005],fw[200005];

void upd(long long x,long long val){
    for(;x<=200000;x+=x&-x)
        fw[x]+=val;
}

long long qr(long long x){
    long long sum=0;
    for(;x>=1;x-=x&-x)
        sum+=fw[x];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q >> s >> t >> ar[0];
    for(long long i=1;i<=n;i++){
        cin >> ar[i];
        dif[i]=ar[i]-ar[i-1];
        if(dif[i]>0){
            upd(i,-dif[i]*s);
        }
        else{
            upd(i,-dif[i]*t);
        }
    }
    long long l,r,x;
    while(q--){
        cin >> l >> r >> x;
        if(dif[l]>0){
            if(dif[l]+x>0){
                dif[l]+=x;
                upd(l,-x*s);
            }
            else{//+ -> -
                upd(l,dif[l]*s-(dif[l]+x)*t);
                dif[l]+=x;

            }
        }
        else{//dif[l]<0
            if(dif[l]+x>0){
                upd(l,dif[l]*t-(x+dif[l])*s);
                dif[l]+=x;
                //cout << x << ' ' << dif[l] << ' ' << "hello\n";
            }
            else{
                dif[l]+=x;
                upd(l,-x*t);
            }
        }
        if(r!=n){
           r++;
        if(dif[r]>0){
            if(dif[r]-x>0){
                dif[r]-=x;
                upd(r,x*s);
            }
            else{//+ -> -
                upd(r,dif[r]*s-(dif[r]-x)*t);
                dif[r]-=x;
            }
        }
        else{//- -> +
            if(dif[r]-x>0){
                upd(r,dif[r]*t-(dif[r]-x)*s);
                dif[r]-=x;
            }
            else{//- -> -
                dif[r]-=x;
                upd(r,x*t);
            }
        }
        }

        long long ans=qr(n);
        cout << ans << '\n';
    }
}
