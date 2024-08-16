//입력은 형식을 엄격하게 준수한다고 나와있으므로 예외처리를 할 필요가 없다.
//error는 행렬 곱셈을 하지 못하는 경우에만 띄우면 된다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct matrix{
    ll row;
    ll col;
    matrix(ll r=0, ll c=0) : row(r), col(c) {}
};

int main(){
    int N; cin>>N;
    map<char, matrix> Mp;
    for(int i=0;i<N;i++){
        char X; ll R, C;
        cin>>X>>R>>C;
        Mp[X] = matrix(R,C);
    } 
    string S;
    while(cin>>S){
        stack<matrix> St;
        ll Ans = 0;
        bool isError = false;
        for(char c : S){
            if(c=='(') continue;
            if(c>='A' && c<='Z') St.push(Mp[c]);
            if(c==')'){
                matrix m2 = St.top(); St.pop();
                matrix m1 = St.top(); St.pop();
                if(m1.col != m2.row) {cout<<"error\n"; isError=true; break;}
                else{
                    Ans += m1.row * m1.col * m2.col;
                    matrix m3 = matrix(m1.row, m2.col);
                    St.push(m3);
                }
            }
        }
        if(isError) continue;
        cout<<Ans<<'\n';
    }
    return 0;
}
