#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  string s;
  cin>>s;
  x--;
  queue<int> que;
  que.push(x);
  s[x]='@';
  while(!que.empty()){
    int pos=que.front();
    que.pop();
    if(pos-1>=0&&s[pos-1]=='.'){
      s[pos-1]='@';
      que.push(pos-1);
    }
    if(pos+1<n&&s[pos+1]=='.'){
      s[pos+1]='@';
      que.push(pos+1);
    }
  }
  cout<<s<<endl;
  return 0;
}