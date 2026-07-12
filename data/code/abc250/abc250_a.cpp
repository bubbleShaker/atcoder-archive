#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int h,w;cin>>h>>w;
    int r,c;cin>>r>>c;r--;c--;
    int ans=0;
    for(int i=0;i<4;i++){
        int nx=r+dx[i];
        int ny=c+dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w)continue;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}