#include <iostream>
#include <string>
int main(){
	std::string s;
	std::cin>>s;
	std::cout<<(s[0]-'0')*(s[2]-'0')<<'\n';
	return 0;
}