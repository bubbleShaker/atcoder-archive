#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]){
    cout<<"Weak"<<endl;
  }else{
    bool is_weak=true;
    for(int i=0;i<3;i++){
      int dif=s[i+1]-s[i];
      if(dif<0){
        dif+=10;
      }
      if(dif!=1){
        is_weak=false;
        break;
      }
    }
    if(is_weak){
      cout<<"Weak"<<endl;
    }else{
      cout<<"Strong"<<endl;
    }
  }
  return 0;
}