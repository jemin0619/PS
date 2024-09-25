//CPP로 문자열 처리하는게 너무 힘들었다.
//구현량이 조금 있던 문제였다.

//직접 모든 조합을 만들어보고, 입력과 같은지 비교했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<string> V;
    for(int i=0; i<M; i++){
        string x; cin>>x;
        V.push_back(x);
    }
    sort(V.begin(), V.end());

    bool chk[30]; //각 척도에 특정 알파벳이 사용되었는가?
    memset(chk, false, sizeof(chk)); 

    vector<string> ans;

    for(int i=0; i<N; i++){
        ans.push_back("");
        bool tmp[30];
        memset(tmp, false, sizeof(tmp));
        for(int j=0; j<M; j++){
            int ch = V[j][i]-'A';
            if(chk[ch]==true){cout<<"NO"; return 0;}
            if(tmp[ch]==false){
                tmp[ch] = true;
                ans[i].push_back(V[j][i]);
            }
        }
        for(int i=0; i<26; i++){
            if(tmp[i]) chk[i] = true;
        }
        sort(ans[i].begin(), ans[i].end());
    }

    vector<string> cmp;
    for(char val : ans[0]){
        string tmp = "";
        tmp += val;
        cmp.push_back(tmp);
    }

    for(int i=1; i<N; i++){
        vector<string> tmp;
        for(char val : ans[i]){
            for(string str : cmp){
                tmp.push_back(str + val);
                //cout<<tmp.back()<<' ';
            }
        }
        cmp = tmp;
    }
    sort(cmp.begin(), cmp.end());

    if(cmp != V) cout<<"NO";
    else{
        cout<<"YES\n";
        for(string val : ans) cout<<val<<'\n';
    }
    return 0;
}
