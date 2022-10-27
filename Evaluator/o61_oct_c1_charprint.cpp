#include<bits/stdc++.h>

using namespace std;

const int MXN=3e5+5;
int mode,fw[MXN];
string s,tg;
queue<int> pos[26];

void upd(int x,int v){
    for(int i=x;i<MXN;i+=i&-i)
        fw[i]+=v;
}

int qr(int x){
    int sum=0;
    for(int i=x;i>=1;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> mode;
    cin >> s;
    for(int i=0;i<s.size();i++){
        pos[s[i]-'a'].push(i+1);
        upd(i+1,1);
    }
    cin >> tg;
    int x,sum=0,qf;
    for(auto it:tg){
        x=it-'a';
        if(pos[x].empty()){
            cout << -1;
            return 0;
        }
        qf=pos[x].front();
        pos[x].pop();
        sum+=qr(qf);
        if(mode)
            upd(qf,-1);
    }
    cout << sum;
}
