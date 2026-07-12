#include <bits/stdc++.h>
using namespace std;

int main(){
  int k;
  string s,t;
  cin>>k>>s>>t;
  if(s==t){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(s.size()==t.size()+1){
    swap(s,t);
  }
  if(s.size()==t.size()-1){//場合1,2を満たすか
    string s1=s+t[t.size()-1];
    if(s1==t){
      cout<<"Yes"<<endl;
      return 0;
    }
    string s2=s;
    reverse(s2.begin(),s2.end());
    s2+=t[0];
    reverse(s2.begin(),s2.end());
    if(s2==t){
      cout<<"Yes"<<endl;
      return 0;
    }
  
    int fi=0;
    while(s[fi]==t[fi]){
      fi++;
    }
    int li=t.size()-1;
    while(s[li-1]==t[li]){
      li--;
    }
    fi--;
    li++;
    if(fi+1==li-1){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else if(s.size()==t.size()){//場合3を満たすか
    int fi=0;
    while(s[fi]==t[fi]){
      fi++;
    }
    int li=t.size()-1;
    while(s[li]==t[li]){
      li--;
    }
    fi--;
    li++;
    if(fi+1==li-1){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}