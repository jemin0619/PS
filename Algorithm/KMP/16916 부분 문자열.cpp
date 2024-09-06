//파이썬 때문에 브론즈 2가 되어버린 KMP 문제이다.
//N, M의 길이가 최대 100만이므로 KMP를 써야만 한다.
//fastio 사용시 12ms, 미사용시 72ms가 나온다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

bool KMP(string&A, string&B){
    int N = A.size();
    int M = B.size();
    vector<int> Fail(M+3);

    for(int i=1, j=0; i<M; i++){
        while(j>0 && B[i]!=B[j]) j=Fail[j-1];
        if(B[i]==B[j]) j++;
        Fail[i] = j;
    }

    for(int i=0, j=0; i<N; i++){
        while(j>0 && A[i]!=B[j]) j=Fail[j-1];
        if(A[i]==B[j]){
            if(j==M-1) return true;
            else j++;
        }
    }

    return false;
}

int main(){
    fastio;
    string A, B;
    cin>>A>>B;
    cout<<KMP(A,B);
    return 0;
}
