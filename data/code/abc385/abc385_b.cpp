#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;

vector<int> dx={-1,0,1,0};
vector<int> dy={0,1,0,-1};

int main(){
  int h,w,x,y;
  cin>>h>>w>>x>>y;
  x--;y--;
  vector<string> s(h);
  for(int i=0;i<h;i++)cin>>s[i];
  string t;
  cin>>t;
  map<char,int> mp;
  mp['U']=0;
  mp['R']=1;
  mp['D']=2;
  mp['L']=3;
  set<P> st;
  for(int i=0;i<t.size();i++){
    int nx=x+dx[mp[t[i]]];
    int ny=y+dy[mp[t[i]]];
    if(s[nx][ny]=='#')continue;
    if(s[nx][ny]=='@'){
      st.insert(make_pair(nx,ny));
    }
    x=nx;
    y=ny;
  }
  cout<<x+1<<" "<<y+1<<" "<<st.size()<<endl;
  return 0;
}