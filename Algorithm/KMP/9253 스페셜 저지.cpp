//사용자가 출력한 문자열의 길이가 답과 동일하므로 입력된 문자열이 A, B에 모두 매칭되는지 확인하면 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> Fail;

vector<int> failure(string &A){
    int N = A.size();
    vector<int> Fail(N+3);
    for(int i=1, j=0; i<N; i++){
        while(j>0 && A[i]!=A[j]) j=Fail[j-1];
        if(A[i]==A[j]) j++;
        Fail[i] = j;
    }
    return Fail;
}

bool KMP(string&A, string&B){
    int N = A.size();
    int M = B.size();
    for(int i=0,j=0; i<N; i++){
        while(j>0 && A[i]!=B[j]) j=Fail[j-1];
        if(A[i]==B[j]){
            if(j==M-1) return true;
            j++;
        }
    }
    return false;
}

int main(){
    fastio;
    string A,B,C; cin>>A>>B>>C;
    Fail = failure(C);
    cout<<((KMP(A,C)&&KMP(B,C))?"YES":"NO");
    return 0;
}
