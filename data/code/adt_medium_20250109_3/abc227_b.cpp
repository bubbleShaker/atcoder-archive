#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    bool is_ok=false;
    for(int a=1;a<=300;a++){
      for(int b=1;b<=300;b++){
        if(4*a*b+3*a+3*b==s[i]){
          is_ok=true;
          break;
        }
      }
      if(is_ok)break;
    }
    if(!is_ok){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}