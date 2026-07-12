#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w,n;cin>>h>>w>>n;
    string t;
    vector<string> s(h);
    cin>>t;
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    map<char,int> dx,dy;
    dx['U']=-1;dy['U']=0;
    dx['R']=0;dy['R']=1;
    dx['D']=1;dy['D']=0;
    dx['L']=0;dy['L']=-1;
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int x=i,y=j;
            if(s[i][j]=='#')continue;
            for(int k=0;k<n;k++){
                int nx=x+dx[t[k]];
                int ny=y+dy[t[k]];
                if(s[nx][ny]=='#')break;
                x=nx;
                y=ny;
                if(k==n-1){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}