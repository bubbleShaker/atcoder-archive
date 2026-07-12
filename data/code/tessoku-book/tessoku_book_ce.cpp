#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<int> rsw1(n+1),rsw2(n+1);//rsw1…あたりの累積和,rsw2…はずれの累積和
  for(int i=1;i<=n;i++){
    int atari=((a[i]==1)?1:0);
    int hazure=((a[i]==0)?1:0);
    rsw1[i]=rsw1[i-1]+atari;
    rsw2[i]=rsw2[i-1]+hazure;
  }
  int q;
  cin>>q;
  while(q--){
    int l,r;
    cin>>l>>r;
    if(rsw1[r]-rsw1[l-1]==rsw2[r]-rsw2[l-1]){
      cout<<"draw"<<'\n';
    }else{
      cout<<((rsw1[r]-rsw1[l-1]>rsw2[r]-rsw2[l-1])?"win":"lose")<<'\n';
    }
  }
  return 0;
}