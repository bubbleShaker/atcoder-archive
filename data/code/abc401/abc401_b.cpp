#include <bits/stdc++.h>
using namespace std;

int main(){
  bool login=false;
  int n;
  cin>>n;
  string s;
  int err_cnt=0;
  for(int i=0;i<n;i++){
    cin>>s;
    if(s=="login"){
      login=true;
    }
    if(s=="logout"){
      login=false;
    }
    if(s=="private"&&!login){
      err_cnt++;
    }
  }
  cout<<err_cnt<<endl;
  return 0;
}