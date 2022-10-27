#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int n,m;
stack<pair<int,int>> st;
int pw[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    st.push({0,0});
    for(int i=0,x;i<n;i++){
        cin >> x;
        while(st.top().fi>x)
            st.pop();
        int tmp;
        if(st.top()==make_pair(0,0))
            tmp=0;
        else
            tmp=max(st.top().se,x-st.top().fi);
        pw[i]=tmp;
        st.push({x,tmp});
    }

    sort(pw,pw+n);
    for(int i=0,q;i<m;i++){
        cin >> q;
        auto it=upper_bound(pw,pw+n,q)-pw;
        cout << n-it << "\n";
    }
}
