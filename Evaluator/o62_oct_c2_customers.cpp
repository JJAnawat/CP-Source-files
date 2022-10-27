#include<bits/stdc++.h>

using namespace std;

int n,m,q;
long long ans[120005];
vector<int> ch[120005],pa[120005];
long long pu[120005];
bitset<120005> hv(0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    int sq=sqrt(240000);
    for(int i=1,l;i<=m;i++){
        cin >> l;
        if(l>sq){//this shop is heavy
            hv[i]=1;
            for(int j=0,x;j<l;j++){
                cin >> x;
                pa[x].push_back(i);
            }
        }
        else{//this shop is light
            for(int j=0,x;j<l;j++){
                cin >> x;
                ch[i].push_back(x);
            }
        }
    }

    int op,x,y,z;
    long long sum=0;
    while(q--){
        cin >> op;
        if(op==1){
            cin >> x >> y;
            if(hv[x])
                pu[x]=y;
            else{
                for(auto it:ch[x])
                    ans[it]+=y-pu[x];
                pu[x]=y;
            }
        }
        else{//query
            sum=0;
            cin >> z;
            for(auto it:pa[z])
                sum+=pu[it];
            cout << sum+ans[z] << '\n';
        }
    }
}
