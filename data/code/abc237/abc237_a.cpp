#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  long long num=1;
  for(int i=0;i<31;i++){
    num<<=1;
  }
  if(-num<=n&&n<num){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}