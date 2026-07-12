#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector a(n+1,vector<int>(n+1));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      cin>>a[i][j];
    }
  }
  int now=1;
  for(int i=1;i<=n;i++){
    if(now>=i){
      now=a[now][i];
    }else{
      now=a[i][now];
    }
  }
  cout<<now<<endl;
  return 0;
}