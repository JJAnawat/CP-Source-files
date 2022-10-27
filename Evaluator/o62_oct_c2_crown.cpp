/*
#include<bits/stdc++.h>

using namespace std;

int n;
int ar[200005];
int l=-1,r=-1;
vector<pair<int,int>> component;

bool chk(int ll,int rr){
    int lll=-1,rrr=-1;
    for(int i=ll;i<=rr;i++){
        if(ar[i]>=2){
            if(lll==-1)
                lll=i;
            rrr=i;
        }
    }
    //cout << lll << " " << rrr;
    if(lll==-1||lll==rrr||lll+1==rrr)
        return 0;
    return 1;
}

long long sol(int st,int ed){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        if(ar[i]==0){
            if(l!=-1)
                component.push_back({l,i-1});
        }
        else{
            if(l==-1)
                l=i;
        }
    }
    if(l!=-1)
        component.push_back({l,n});
    auto it=component.begin();
    while(it!=component.end()){
        auto [ll,rr]=*it;
        if(chk(ll,rr))
            it++;
        else
            component.erase(it);
    }
    if(component.empty()){
        cout << -1;
        return 0;
    }
    //ans=max of all components
    long long ans=INT_MIN;
    for(auto [ll,rr]:component)
        ans=max(ans,sol(ll,rr));
    cout << ans;
}
//sol for each component
//cur possible?

*/

#include<bits/stdc++.h>

using namespace std;

int n;
long long ar[200005];
vector<long long> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p=-1;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        if(ar[i]!=0)
            v.push_back(ar[i]);
    }
    if(v.size()<3){
        cout << "-1";
        return 0;
    }

    n=v.size();
    v.insert(v.begin(),0);
    bool chk=1;
    for(int i=1;i<n;i++){
        if(v[i]!=v[i+1])
            chk=0;
        if(v[i]>v[i+1]){
            p=i;
            break;
        }
    }

    if(chk&&v[1]==1){
        cout << "-1";
        return 0;
    }

    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=v[i];
    if(chk)
        sum--;
    else if(p==-1)
        sum-=v[n-1]-v[n-2]+1;
    else if(p==1)
        sum-=v[2]-v[3]+1;
    else{
        int cnt=1;
        while(v[p-1]==v[p]){
            cnt++;
            p--;
        }
        if(cnt>=3){
            sum--;
        }
        else{
            if(cnt==2){
                sum-=min(v[p]-v[p-1]+1,v[p+1]-v[p+2]+1);
            }
            else
                sum-=v[p]-min(v[p+1],v[p-1])+1;
        }
    }
    cout << sum;
}
/*
12
1 2 5 5 3 3 3 3 2 1 0 0
6
5 4 3 2 1 0
7
0 0 1 2 3 4 5
5
2 8 8 8 4
*/
