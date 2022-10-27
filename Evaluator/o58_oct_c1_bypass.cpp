#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,pl=13;
    for(i=14;i<=99;i+=pl,pl--){
        cout << i << '\n';
        if(i==99)
            break;
    }
    cout << pl << " " << i << '\n';
    /*
    for(int j=i-pl;j<i;j++)
        cout << j << '\n';*/
}
