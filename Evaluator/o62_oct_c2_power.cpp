#include<bits/stdc++.h>

using namespace std;

int n,m;
set<pair<int,long long>> s;
long long ans=0;

long long qr(int i){
    if(s.empty())
        return 0;
    auto it=s.lower_bound({i,0});
    long long mx=0;
    if(it==s.begin())
        mx=max(mx,it->second-abs(it->first-i));
    else if(it==s.end()){
        it--;
        mx=max(mx,it->second-abs(it->first-i));
    }
    else{
        mx=max(mx,it->second-abs(it->first-i));
        it--;
        mx=max(mx,it->second-abs(it->first-i));
    }
    return mx;
}

void del(long long cmx,int ci){
    auto it=s.lower_bound({ci,0});
    while(it!=s.end()&&cmx-abs(it->first-ci)>=it->second){
        it=s.erase(it);
    }
    it=s.lower_bound({ci,0});
    if(it!=s.begin()){
        it--;
        while(cmx-abs(it->first-ci)>=it->second){
            it=s.erase(it);
            if(it==s.begin())
              break;
            it--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0,a,b,c;i<m;i++){
        cin >> a >> b >> c;
        if(s.empty()){
            s.insert({b,c});
            s.insert({a,c});
            ans=c;
        }
        else{
            long long mxa=qr(a);
            long long mxb=qr(b);

            del(mxa+c,b);
            if(!s.empty())
                del(mxb+c,a);

            if(mxa+c>mxb){
                ans=max(ans,mxa+c);
                s.insert({b,mxa+c});
            }
            if(mxb+c>mxa){
                ans=max(ans,mxb+c);
                s.insert({a,mxb+c});
            }
        }
        cout << ans << "\n";
    }
}
