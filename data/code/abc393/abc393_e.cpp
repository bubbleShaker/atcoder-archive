#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  int M=0;
  for(int i=0;i<N;i++)cin>>A[i],M=max(M,A[i]);
  vector<int> cnt_A(M+1);
  for(int i=0;i<N;i++)cnt_A[A[i]]++;
  vector<int> d_included_A(M+1);
  vector<int> max_d_devides_n(M+1);
  for(int d=1;d<=M;d++){
    for(int n=d;n<=M;n+=d){
      d_included_A[d]+=cnt_A[n];
    }
  }
  for(int d=1;d<=M;d++){
    if(d_included_A[d]<K)continue;
    for(int n=d;n<=M;n+=d){
      max_d_devides_n[n]=max(max_d_devides_n[n],d);
    }
  }
  for(int i=0;i<N;i++){
    cout<<max_d_devides_n[A[i]]<<endl;
  }
  return 0;
}