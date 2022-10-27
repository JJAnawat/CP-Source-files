#include<bits/stdc++.h>

using namespace std;

const int MXN=1e5+5;
long long pf[MXN],fw[MXN];
vector<long long> v;
long long n,k,pos[MXN];

void upd(long long x,long long val){
    for(long long i=x;i<MXN;i+=i&-i)
        fw[i]+=val;
}

long long qr(long long x){
    long long sum=0;
    for(long long i=x;i>0;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(long long i=1;i<=n;i++){
        cin >> pf[i];
        pf[i]+=pf[i-1];
        v.push_back(pf[i]);
    }

    v.push_back(0);
    v.push_back(-1e18);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(long long i=0;i<=n;i++){
        pos[i]=lower_bound(v.begin(),v.end(),pf[i])-v.begin()+1;
    }

    /*
    for(int i=1;i<=n;i++)
    cout << pf[i] << ' ' << pos[i] << '\n';
    */

    long long l=-1e11,r=1e11;
    while(l<r){
        memset(fw,0,sizeof(fw));
        long long mid=(l+r+1)/2;
        long long cnt=0;

        upd(pos[0],1);
        for(long long i=1;i<=n;i++){
            auto it=upper_bound(v.begin(),v.end(),pf[i]-mid)-v.begin();
            //--it;
            cnt+=qr(it);
            upd(pos[i],1);
        }

        if(cnt>=k)
            l=mid;
        else
            r=mid-1;
    }
    cout << l;
    /*
    memset(fw,0,sizeof(fw));
    long long cnt=0;
    //v={1,3,6,10}
    //pf[i]={1,3,6,10};
    for(int i=1;i<=n;i++){

            auto it=upper_bound(v.begin(),v.end(),pf[i]-9)-v.begin();
            //--it;
            cout << it << ' ';
            upd(pos[i],1);
            cnt+=qr(it);
        }
        cout << '\n';
        for(int i=1;i<=4;i++){
            cout << qr(i) << ' ';
        }
    cout << "\n";
    cout << cnt;*/
}
