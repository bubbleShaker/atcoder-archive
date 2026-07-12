#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    cin >> S;
    
    stack<string> ss;
    set<char> cs;
    
    ss.push("");
    
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '('){
            ss.push("");
        }
        else if(S[i] == ')'){
            for(char t : ss.top()){
                cs.erase(t);
            }
            ss.pop();
        }
        else{
            if(cs.count(S[i])){
                cout << "No" << endl;
                return 0;
            }
            ss.top().push_back(S[i]);
            cs.insert(S[i]);
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}
