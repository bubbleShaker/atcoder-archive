#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin>>q;
  queue<string> que;
  while(q--){
    int type;
    cin>>type;
    if(type==1){
      string x;
      cin>>x;
      que.push(x);
    }else if(type==2){
      cout<<que.front()<<endl;
    }else if(type==3){
      que.pop();
    }
  }
  return 0;
}