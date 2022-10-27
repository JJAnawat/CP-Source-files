#include "2eggs.h"
#include<bits/stdc++.h>

int height_threshold(int N, int Q) {
    //trying subtask 5
    int i,pl=13;
    bool chk=0;
    for(i=14;i<=99;i+=pl,pl--){
        if(drop_egg(1,i))
            break;
    }
    if(i>99)
        return 100;
    for(int j=i-pl;j<i;j++){
        if(drop_egg(2,j))
            return j;
    }
    return i;
}
