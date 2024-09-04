//처음엔 문자열이 숫자와 문자로 이분적으로 나뉘는 것으로 이해했는데 그게 아닌 경우가 있어서 WA를 받았다. 
//빼기와 나누기는 교환법칙이 성립하지 않으므로 순서를 고려해줘야 하는데 그걸 안해서 WA를 받았다.
//ex) 스택에 2 3(top)이 있을 때 -가 오면 3-2를 해야하는데 2-3을 함.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    string S; cin>>S;
    stack<int> num;
    queue<char> oper;
    ll ans = 0;
    for(char c : S){
        if('0'<=c && c<='9'){
            if(oper.empty()) num.push(c-'0');
            else{
                while(num.size()>1){
                    ll A = num.top(); num.pop();
                    ll B = num.top(); num.pop();
                    char op = oper.front(); oper.pop();
                    ll res = 0;
                    if(op=='+'){
                        res = A+B;
                    }
                    if(op=='-'){
                        res = B-A;
                    }
                    if(op=='*'){
                        res = A*B;
                    }
                    if(op=='/'){
                        res = B/A;
                    }
                    num.push(res);
                }
                num.push(c-'0');
            }
        }
        else oper.push(c);
    }
    while(num.size()>1){
        ll A = num.top(); num.pop();
        ll B = num.top(); num.pop();
        char op = oper.front(); oper.pop();
        ll res = 0;
        if(op=='+'){
            res = A+B;
        }
        if(op=='-'){
            res = B-A;
        }
        if(op=='*'){
            res = A*B;
        }
        if(op=='/'){
            res = B/A;
        }
        num.push(res);
    }
    cout<<num.top();
    return 0;
}
