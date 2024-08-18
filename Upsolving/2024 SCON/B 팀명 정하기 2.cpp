#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back

int main(){
    fastio;
    int N; cin>>N;
    for(int i=0; i<N; i++){
        string S; cin>>S;
        //대문자가 소문자보다 많으면 안됨
        //팀명은 10글자 이내
        //숫자로만 구성되면 안됨
        if(S.size()>10) continue;
        int lc=0, uc=0, num=0;
        for(char c : S){
            if(c>='a' && c<='z') lc++;
            if(c>='A' && c<='Z') uc++;
            if(c>='0' && c<='9') num++;
        }
        if(uc>lc) continue;
        if(num==S.size()) continue;
        cout<<S<<'\n';
    }
    return 0;
}

//00:09 AC
