#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w,k;cin>>h>>w>>k;
    vector<string> s(h);
    vector<vector<int>> rswRow(h,vector<int>(w+1));
    vector<vector<int>> rswBoolRow(h,vector<int>(w+1));
    vector<vector<int>> rswCol(h+1,vector<int>(w));
    vector<vector<int>> rswBoolCol(h+1,vector<int>(w));
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int valMaru=0;
            int valBatu=0;
            if(s[i][j]=='.')valMaru=1;
            if(s[i][j]=='x')valBatu=1;
            rswRow[i][j+1]+=rswRow[i][j]+valMaru;
            rswBoolRow[i][j+1]+=rswBoolRow[i][j]+valBatu;
        }
    }
    for(int j=0;j<w;j++){
        for(int i=0;i<h;i++){
            int valMaru=0;
            int valBatu=0;
            if(s[i][j]=='.')valMaru=1;
            if(s[i][j]=='x')valBatu=1;
            rswCol[i+1][j]+=rswCol[i][j]+valMaru;
            rswBoolCol[i+1][j]+=rswBoolCol[i][j]+valBatu;
        }
    }
    int ans=(long long)1e9;
    for(int i=0;i<h;i++){
        for(int j=0;j<=w;j++){
            if(j+k<=w){
                if(rswBoolRow[i][j+k]-rswBoolRow[i][j]==0){
                    ans=min(ans,rswRow[i][j+k]-rswRow[i][j]);
                }
            }
        }
    }
    for(int j=0;j<w;j++){
        for(int i=0;i<=h;i++){
            if(i+k<=h){
                if(rswBoolCol[i+k][j]-rswBoolCol[i][j]==0){
                    ans=min(ans,rswCol[i+k][j]-rswCol[i][j]);
                }
            }
        }
    }
    
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<=w;j++){
    //         cout<<rswRow[i][j]<<" \n"[j==w];
    //     }
    // }
    
    if(ans==(long long)1e9){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}