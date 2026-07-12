#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

map<char, int> A;
map<char, vector<int>> B;

vector<int> operator+(vector<int> a, vector<int> b){
    vector<int> c((int)a.size());
    if(!b.size()){
        for(int i = 0; i < a.size(); i++){
            b.push_back(0);
        }
    }
    int i = 0;
    
    for (i = 0; i < (int)a.size(); i++) {
        c[i] = a[i] + b[i];
    }
    
    return c;
}


int cp_int(){
    char op;
    cin >> op;
    
    if(isdigit(op)){
        int ia;
        ia = op - '0';
        return ia + cp_int();
    }else if(A.count(op)){
        return A[op] + cp_int();
    }else if(op == '-'){
        char a;
        cin >> a;
        if(isdigit(a)){
            int ia;
            ia = -1*(a - '0');
            return ia + cp_int();
        }else{
            return -1*A[a] + cp_int();
        }
    }else if(op == '+'){
        char a;
        cin >> a;
        if(isdigit(a)){
            int ia;
            ia = a - '0';
            return ia + cp_int();
        }else{
            return A[a] + cp_int();
        }
    }else if(op == ';'){
        return 0;
    }else{
        return cp_int();
    }
    
    return 0;
}

vector<int> cp_vec(){
    char op;
    vector<int> v;
    cin >> op;
    if(op == '['){
        while(op != ']'){
            cin >> op;
            if(isdigit(op)){
                int ia = op - '0';
                v.push_back(ia);
            }else if(A.count(op)){
                v.push_back(A[op]);
            }
        }
        return v + cp_vec();
    }else if(B.count(op)){
        return B[op] + cp_vec();
    }else if(op == '+'){
        char a;
        cin >> a;
        if(a == '['){
            while(a != ']'){
                cin >> a;
                if(isdigit(a)){
                    int ia = a - '0';
                    v.push_back(ia);
                }else if(A.count(a)){
                    v.push_back(A[a]);
                }
            }
            return v + cp_vec();
        }else{
            return B[a] + cp_vec();
        }
    }else if(op == '-'){
        char a;
        cin >> a;
        if(a == '['){
            while(a != ']'){
                cin >> a;
                if(isdigit(a)){
                    int ia = a - '0';
                    v.push_back(ia);
                }else if(A.count(a)){
                    v.push_back(A[a]);
                }
            }
            
            for(int i = 0; i < (int)v.size(); i++){
                v[i] = -1*v[i];
            }
            
            return v + cp_vec();
        }else{
            vector<int> c(B[a].size());
            for(int i = 0; i < (int)B[a].size(); i++){
                c[i] = -1*B[a][i];
            }
            return c + cp_vec();
        }
    }else if(op == ';'){
        return {};
    }else{
        return cp_vec();
    }
    
    return{};
}

void int_dec(char var){
    A[var] = cp_int();
}

void print_int(){
    cout << cp_int() << endl;
}

void vec_dec(char var){
    B[var] = cp_vec();
}

void print_vec(){
    vector<int> tmp = cp_vec();
    cout << "[ ";
    for (int i = 0; i < (int)tmp.size(); i++){
        cout << tmp.at(i) << " ";
    }
    cout << "]" << endl;
}



int main(){
    int i, N;
    string p;
    cin >> N;
    
    for(i = 0; i < N; i++){
        cin >> p;
        if(p == "int"){
            char v;
            cin >> v;
            int_dec(v);
        }else if(p == "print_int"){
            print_int();
        }else if(p == "vec"){
            char v;
            cin >> v;
            vec_dec(v);
        }else if(p == "print_vec"){
            print_vec();
        }
    }
}