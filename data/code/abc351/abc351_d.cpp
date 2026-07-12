#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    set<pair<int,int>> gst,st;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
                st.insert({i,j});
            }
        }
    }
    for(auto [x,y]:st){
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=h||nx<0||ny>=w||ny<0){
                continue;
            }
            gst.insert({nx,ny});
        }
    }
    dsu uf(h*w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int num=i*w+j;
            if(st.count({i,j})){
                continue;
            }
            if(gst.count({i,j})){
                continue;
            }
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=h||nx<0||ny>=w||ny<0){
                    continue;
                }
                if(st.count({nx,ny})){
                    continue;
                }
                if(gst.count({nx,ny})){
                    continue;
                }
                int nnum=nx*w+ny;
                uf.merge(num,nnum);
            }
        }
    }
    map<int,set<pair<int,int>>> mp;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int num=i*w+j;
            if(st.count({i,j})){
                continue;
            }
            if(gst.count({i,j})){
                continue;
            }
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=h||nx<0||ny>=w||ny<0){
                    continue;
                }
                if(st.count({nx,ny})){
                    continue;
                }
                if(gst.count({nx,ny})){
                    mp[uf.leader(num)].insert({nx,ny});
                }
            }
        }
    }
    set<int> lst;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int num=i*w+j;
            if(st.count({i,j})){
                continue;
            }
            if(gst.count({i,j})){
                continue;
            }
            lst.insert(uf.leader(num));
        }
    }
    int ans=1;
    for(auto l:lst){
        int sum=uf.size(l)+mp[l].size();
        // cout<<uf.size(l)<<" "<<st.size()<<endl;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}