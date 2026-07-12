#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin>>n>>q;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
  bool isReversed=false;
  while(q--){
    int type;
    cin>>type;
    if(type==1){
      int x,y;
      cin>>x>>y;
      if(isReversed){
        a[n-(x-1)]=y;
      }else{
        a[x]=y;
      }
    }else if(type==2){
      isReversed=!isReversed;
    }else if(type==3){
      int x;
      cin>>x;
      if(isReversed){
        cout<<a[n-(x-1)]<<endl;
      }else{
        cout<<a[x]<<endl;
      }
    }
  }
  return 0;
}