#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int h,w,n;cin>>h>>w>>n;
    vector<vector<char>> grid(h,vector<char>(w,'.'));//.:白、#:黒
    int x=0,y=0,dir=0;
    for(int i=0;i<n;i++){
        if(grid[x][y]=='.'){
            grid[x][y]='#';
            dir=(dir+1)%4;
            x=(x+dx[dir]+h)%h;
            y=(y+dy[dir]+w)%w;
        }else{
            grid[x][y]='.';
            dir=((dir-1)+4)%4;
            x=(x+dx[dir]+h)%h;
            y=(y+dy[dir]+w)%w;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}