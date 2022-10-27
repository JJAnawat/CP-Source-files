#include<bits/stdc++.h>

using namespace std;

int n,q;
int pa[100005];

int fi(int i){
    if(pa[i]==i)
        return i;
    return pa[i]=fi(pa[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    char op;
    int a,b;
    while(q--){
        cin >> op >> a >> b;
        if(op=='q'){
            a=fi(a);
            b=fi(b);
            if(a==b)
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else{
            a=fi(a);
            b=fi(b);
            if(a==b)
                continue;
            pa[a]=b;
        }
    }
}
