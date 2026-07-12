#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,l;
  cin>>n>>l;
  int ans=0;
  for(int i=0;i<n;i++){
    int a;
    char b;
    cin>>a>>b;
    if(b=='E'){
      ans=max(ans,l-a);
    }else{
      ans=max(ans,a);
    }
  }
  cout<<ans<<endl;
  return 0;
}