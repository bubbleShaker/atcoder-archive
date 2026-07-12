#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<char>> c(4,vector<char>(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>c[i][j];
        }
    }
    vector<vector<char>> ans(4,vector<char>(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ans[i][j]=c[4-i-1][4-j-1];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<ans[i][j]<<" \n"[j+1==4];
        }
    }
    return 0;
}