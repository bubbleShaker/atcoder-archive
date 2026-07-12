#include <iostream>
#include <string>
int main(){
  int n,q;
  std::string s;
  std::cin>>n>>q>>s;
  int cnt=0;
  for(int i=1;i<n-1;i++){
    if(s[i-1]=='A'&&s[i]=='B'&&s[i+1]=='C'){
      cnt++;
    }
  }
  while(q--){
    int x;
    char c;
    std::cin>>x>>c;
    x--;
    if(s[x]=='A'&&x+1<n&&s[x+1]=='B'&&x+2<n&&s[x+2]=='C'){
      cnt--;
    }else if(s[x]=='B'&&x-1>=0&&s[x-1]=='A'&&x+1<n&&s[x+1]=='C'){
      cnt--;
    }else if(s[x]=='C'&&x-1>=0&&s[x-1]=='B'&&x-2>=0&&s[x-2]=='A'){
      cnt--;
    }
    s[x]=c;
    if(s[x]=='A'&&x+1<n&&s[x+1]=='B'&&x+2<n&&s[x+2]=='C'){
      cnt++;
    }else if(s[x]=='B'&&x-1>=0&&s[x-1]=='A'&&x+1<n&&s[x+1]=='C'){
      cnt++;
    }else if(s[x]=='C'&&x-1>=0&&s[x-1]=='B'&&x-2>=0&&s[x-2]=='A'){
      cnt++;
    }
    std::cout<<cnt<<'\n';
  }
  return 0;
}