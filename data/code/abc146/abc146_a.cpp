#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  if(s=="SUN"){
    cout<<7<<endl;
    return 0;
  }
  vector<string> days={"SUN","MON","TUE","WED","THU","FRI","SAT","SUN","MON","TUE","WED","THU","FRI","SAT"};
  int now=0;
  while(days[now]!=s){
    now++;
  }
  int ans=0;
  while(days[now]!="SUN"){
    now++;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}