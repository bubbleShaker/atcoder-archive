#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int n;cin>>n;
    int val=1;
    int x=0,y=0;
    const vector<int> dx={0,1,0,-1};
    const vector<int> dy={1,0,-1,0};
    vector<vector<int>> ans(n,vector<int>(n));
    set<pair<int,int>> visitedSet;
    int i=0;
    int endX=(n+1)/2-1;
    int endY=(n+1)/2-1;
    while(!(x==endX&&y==endY)){
        visitedSet.insert({x,y});
        ans[x][y]=val;
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n||visitedSet.count({nx,ny})){
            nx-=dx[i];
            ny-=dy[i];
            i++;
            i%=4;
            nx=x+dx[i];
            ny=y+dy[i];
        }
        x=nx;
        y=ny;
        val++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==endX&&j==endY){
                cout<<'T';
            }else{
                cout<<ans[i][j];
            }
            cout<<" \n"[j+1==n];
        }
    }
    return 0;
}