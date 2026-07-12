#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector a(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  vector<int> t(n+1);
  for(int i=1;i<=n;i++){
    t[i]=i;
  }
  int q;
  cin>>q;
  while(q--){
    int type,x,y;
    cin>>type>>x>>y;
    if(type==1){
      int tmp=t[x];
      t[x]=t[y];
      t[y]=tmp;
    }else if(type==2){
      cout<<a[t[x]-1][y-1]<<endl;
    }
  }
  return 0;
}