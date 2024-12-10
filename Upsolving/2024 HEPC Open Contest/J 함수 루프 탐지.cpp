//https://github.com/dlalsrn/Baekjoon/blob/main/백준/Gold/31875. 함수 루프 탐지/함수 루프 탐지.cc

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

void solve(){
    int mxCnt=1, cnt=1;
    int N; cin>>N;
    map<string, int> Mp;
    vector<string> A(N+1), pre, ans;
    for(int i=1; i<=N; i++) cin>>A[i];
    for(int i=1; i<=N; i++){
        if(Mp.find(A[i])==Mp.end()) {Mp[A[i]]=i; continue;}
        int diff = i - Mp[A[i]];
        int jump = 0;
        bool loop = true;
        for(int j=0; j<diff; j++){
            if(i+j>N || Mp.find(A[i+j])==Mp.end() || (i+j)-Mp[A[i+j]]!=diff) {loop=false; break;}
            Mp[A[i+j]] = i+j;
            jump++;
        }
        if(loop){
            vector<string> tmp(diff);
            for(int j=0; j<diff; j++) tmp[j] = A[i+j];
            if(pre.size()>0 && tmp==pre) cnt++;
            else cnt = 2;
            if(mxCnt<cnt){
                mxCnt = cnt;
                ans = tmp;
            }
            pre = tmp;
        }
        else pre.clear();
        i += jump-1;
    }
    if(mxCnt==1) {cout<<"-1"; return;}
    cout<<ans.size()<<' '<<mxCnt<<'\n';
    for(string val : ans) cout<<val<<' ';
}

int main(){
    fastio;
    solve();
    return 0;
}
