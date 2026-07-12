#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<double> R(N);
  for(int i=0;i<N;i++) cin>>R[i];
  sort(R.begin(),R.end());
  double ans=0;
  for(int i=N-K;i<N;i++) ans=(ans+R[i])/2;
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
  return 0;
}