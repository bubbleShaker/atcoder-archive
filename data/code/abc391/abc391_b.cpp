#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<string> s(n),t(m);
  for(int i=0;i<n;i++)cin>>s[i];
  for(int i=0;i<m;i++)cin>>t[i];
  for(int a=0;a<n-m+1;a++){
    for(int b=0;b<n-m+1;b++){
      bool is_ok=true;
      for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          if(s[a+i][b+j]!=t[i][j])is_ok=false;
        }
      }
      if(is_ok){
        cout<<a+1<<" "<<b+1<<endl;
        return 0;
      }
    }
  }
  return 0;
}