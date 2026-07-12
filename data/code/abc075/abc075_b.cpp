#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;cin>>h>>w;
    vector<string> s(h);
    vector<int> dx={-1,-1,0,1,1,1,0,-1};
    vector<int> dy={0,1,1,1,0,-1,-1,-1};
    vector<vector<int>> ans(h,vector<int>(w));
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#')continue;
            for(int k=0;k<8;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0||nx>=h||ny<0||ny>=w)continue;
                if(s[nx][ny]=='#'){
                    ans[i][j]++;
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                cout<<ans[i][j];
            }else{
                cout<<"#";
            }
        }
        cout<<endl;
    }
    return 0;
}