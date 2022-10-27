#include<bits/stdc++.h>

using namespace std;

int a[105],b[105],t[105];
long long dp[105][105][105],help[105][105][105];
int m,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> k;
    for(int i=1;i<=k;i++)
        cin >> a[i] >> b[i] >> t[i];

    for(int w=0;w<=m;w++){
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                dp[w][x][y]=INT_MIN;
            }
        }
    }
    dp[0][0][0]=0;

    long long ans=INT_MIN;
    for(int i=1;i<=k;i++){
        int xx=t[i];
        int yy=1-xx;
        int ww=a[i];
        for(int w=0;w<=m;w++){
            for(int x=0;x<k;x++){
                for(int y=0;y<k;y++){
                    help[w][x][y]=INT_MIN;
                    if(w-ww<0||x-xx<0||y-yy<0)
                        continue;
                    if(x>=2*y+3)
                        continue;
                    if(y>=2*x+3)
                        continue;
                    if(dp[w-ww][x-xx][y-yy]<0)
                        continue;
                    help[w][x][y]=dp[w-ww][x-xx][y-yy]+b[i];
                    ans=max(ans,help[w][x][y]);
                }
            }
        }
        for(int w=0;w<=m;w++){
            for(int x=0;x<k;x++){
                for(int y=0;y<k;y++){
                    dp[w][x][y]=max(dp[w][x][y],help[w][x][y]);
                }
            }
        }
    }

    cout << ans;
}
/*
if(x>=2y+3)
    cannot place
*/
