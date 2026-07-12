#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin>>n>>t;
  int c1;
  int max_t=0,max_c1=0;
  int max_t_idx,max_c1_idx;
  vector<int> C(n),R(n);
  for(int i=0;i<n;i++){
    cin>>C[i];
  }
  for(int i=0;i<n;i++){
    cin>>R[i];
  }
  for(int i=0;i<n;i++){
    int c=C[i];
    int r=R[i];
    if(i==0){
      c1=c;
      max_c1=r;
      max_c1_idx=i;
    }
    if(c==t){
      if(max_t<r){
        max_t=r;
        max_t_idx=i;
      }
    }else if(c==c1){
      if(max_c1<r){
        max_c1=r;
        max_c1_idx=i;
      }
    }
  }
  if(max_t==0){
    cout<<max_c1_idx+1<<endl;
  }else{
    cout<<max_t_idx+1<<endl;
  }
  return 0;
}