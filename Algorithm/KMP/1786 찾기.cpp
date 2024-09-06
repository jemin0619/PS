//KMP Standard 문제

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> ans;

void KMP(string&A, string&B){
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
        if(A[i] == B[j]){
            if(j == M-1){
                ans.push_back(i-M+2);
                j = Fail[j];
            }
            else j++;
        }
    }
}

int main(){
    fastio;
    string A, B;
    getline(cin, A);
    getline(cin, B);
    KMP(A, B);
    cout<<ans.size()<<'\n';
    for(int val : ans) cout<<val<<' ';
    return 0;
}
