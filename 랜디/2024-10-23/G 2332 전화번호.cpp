//ans[i] : S[i-1]까지 문자열을 대응시키는데 필요한 문자열의 최소 개수
//문자열이 매칭만 되면 되므로 역추적에 이전 인덱스만 전해주면 됐다.
//그래서 인덱스만 쪼개놓고, 그에 맞는 단어만 넣어주면 된다.
//
//최적화는 다음의 아이디어로 이루어진다.
//인덱스 i~j-1를 어떤 문자로 대응시킬 때, ans[j]의 값이 ans[i]+1보다 크다면 ans[j] = ans[i]+1로 갱신해준다.
//처음에 탑다운으로 시도했는데 계속 TLE를 받았다. 구현상 실수가 있던 것 같다.
//쉽지 않음.
//https://github.com/PhiCis/Baekjoon/blob/5d00aa1be18a000cb85420f70ff77c7b99da4527/%EB%B0%B1%EC%A4%80/Gold/2332.%E2%80%85%EC%A0%84%ED%99%94%EB%B2%88%ED%98%B8/%EC%A0%84%ED%99%94%EB%B2%88%ED%98%B8.cc#L4

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define xx first
#define yy second

char arr[] = {'2','2','2','3','3','3','4','4','1','1','5','5','6','6','0','7','0','7','7','8','8','8','9','9','9','0'};
string encode(string X){
    for(char&val : X){
        val = arr[val-'a'];
    }
    return X;
}

int N;
string S;
vector<pair<string, string>> V;
vector<int> pre;
vector<int> ans;
vector<vector<string>> word; //word[i][j] : S[i~j-1]에 대응시킬 수 있는 단어

int main(){
    fastio;
    cin>>S>>N;
    V.resize(N);
    word.resize(S.size()+1, vector<string>(S.size()+1, ""));
    pre.resize(S.size()+1, -1);
    ans.resize(S.size()+1, 0x7f7f7f7f);
    for(int i=0; i<N; i++){
        string x; cin>>x;
        V[i] = {x, encode(x)};
        for(int j=0; j+V[i].yy.size()<=S.size(); j++){
            bool flag = false;
            for(int k=0; k<V[i].yy.size(); k++){
                if(V[i].yy[k] != S[j+k]) {flag=true; break;}
            }
            if(flag) continue;
            word[j][j+V[i].yy.size()] = V[i].xx;
        }
    }

    ans[0] = 0;
    for(int i=1; i<=S.size(); i++){
        for(int j=0; j<i; j++){
            if(word[j][i]!="" && ans[j]+1<ans[i]){
                ans[i] = ans[j]+1;
                pre[i] = j;
            } 
        }
    }

    if(ans[S.size()]==0x7f7f7f7f) cout<<"0\nNo solution.";
    else{
        vector<int> path;
        int idx = S.size();
        while(pre[idx]!=-1){
            path.push_back(pre[idx]);
            idx = pre[idx];
        }
        reverse(path.begin(), path.end());
        path.push_back(S.size());
        cout<<ans[S.size()]<<'\n';
        for(int i=1; i<path.size(); i++) cout<<word[path[i-1]][path[i]]<<'\n';
    }
    return 0;
}
