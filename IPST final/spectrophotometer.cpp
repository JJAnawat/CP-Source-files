#include "spectrophotometer.h"
#include<bits/stdc++.h>

using namespace std;

int hd[4]={-1,-1,-1,-1};

void sort_lasers(int N) {
    if(N==1)
        return;
    else{
        hd[3]=0;
        for(int i=1;i<3*N;i++){
            int j=3,ti=i;
            while(1){
                if(hd[j]==-1){
                    hd[j]=ti;
                    break;
                }
                if(j==1&&hd[1]!=-1)
                    break;
                bool chk=call_swap(ti,hd[j]);
                if(chk)
                    break;
                else{
                    ti=hd[j];
                    hd[j]++;
                    j--;
                }
            }
        }
    }
}
