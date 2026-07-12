#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  for(int start_i=0;start_i<n;start_i++){
    bool is_end=false;
    for(int kankaku=1;;kankaku++){
      string str_made;
      for(int i=0;i<=2;i++){
        if(start_i+i*kankaku>=n){
          is_end=true;
          break;
        }
        str_made+=s[start_i+i*kankaku];
      }
      if(str_made=="ABC"){
        ans++;
      }
      if(is_end){
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}