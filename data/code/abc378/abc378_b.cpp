#include <bits/stdc++.h>
using namespace std;

int ceili(int a,int b){
  return (a+(b-1))/b;
}

int main(){
  int n;
  cin>>n;
  vector<int> q(n),r(n);
  for(int i=0;i<n;i++){
    cin>>q[i]>>r[i];
  }
  int Q;
  cin>>Q;
  while(Q--){
    int t,d;
    cin>>t>>d;
    t--;
    if(d-r[t]<0){
      cout<<r[t]<<endl;
    }else{
      int m=ceili(d-r[t],q[t]);
      cout<<q[t]*m+r[t]<<endl;
    }
  }
  return 0;
}