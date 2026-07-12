#include <iostream>
#include <string>
int main(){
  std::string w;
  std::cin>>w;
  std::string ans;
  for(int i=0;i<w.size();i++){
    if(w[i]=='a'||w[i]=='i'||w[i]=='u'||w[i]=='e'||w[i]=='o'){
      continue;
    }
    ans+=w[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}