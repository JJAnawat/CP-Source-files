#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> lis;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lis.clear();
    cin >> n;
    for(int i=0,x;i<n;i++){
        cin >> x;
        if(lis.empty()||lis.back()<x){
            lis.push_back(x);
        }else{
            auto it=lower_bound(lis.begin(),lis.end(),x);
            *it=x;
        }
    }
    cout << lis.size();
}
