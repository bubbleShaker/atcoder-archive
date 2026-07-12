#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> A(N+1);
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }
  int ok=0,ng=(N/2)+1;
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    vector<int> F,B;
    for(int i=1;i<=mid;i++){
      F.push_back(A[i]);
      B.push_back(A[N-i+1]);
    }
    reverse(B.begin(),B.end());
    bool is_ok=true;
    for(int i=0;i<mid;i++){
      if(2*F[i]>B[i]){
        is_ok=false;
        break;
      }
    }
    if(is_ok){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  cout<<ok<<endl;
  return 0;
}