#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<string> R;
    vector<string> L;
    vector<string> Mid;
    vector<string> V;
    vector<bool> chk(103,false);
    for(int i=0;i<N;i++){
        string x; cin>>x;
        bool is_Pallindrome = true;
        for(int i=0;i<=(x.size()-1)/2;i++){
            if(x[i]!=x[x.size()-1-i]) {is_Pallindrome=false; break;}
        }
        if(!is_Pallindrome) V.push_back(x);
        else Mid.push_back(x);
    }
    for(int i=0;i<V.size();i++){
        if(chk[i]) continue;
        string rev = V[i];
        reverse(rev.begin(),rev.end());
        for(int j=0;j<V.size();j++){
            if(chk[j]) continue;
            if(V[j]==rev){ //해당 문자열에 대응하는 문자열이 존재할 경우
                R.push_back(V[i]);
                L.push_back(V[j]);
                chk[j] = chk[i] =true;
                break;
            }
        }
    }
    /*
    cout<<"R의 원소들\n";
    for(string val:R) cout<<val<<'\n';
    cout<<'\n';

    cout<<"L의 원소들\n";
    for(string val:L) cout<<val<<'\n';
    cout<<'\n';

    cout<<"Mid의 원소들\n";
    for(string val:Mid) cout<<val<<'\n';
    cout<<'\n';
*/
    reverse(R.begin(),R.end());
    string Ans = "";
    for(string val : L) Ans+=val;
    if(Mid.size()>=1) Ans+=Mid[0];
    for(string val : R) Ans+=val;
    cout<<Ans.size()<<'\n';
    cout<<Ans;
    return 0;
}

/*
Mid에 같은게 두개 이상 있으면 R, L에 사용할 수도 있음
홀수인 요소만 가운데에 쓰고 나머지는 R,L에 배정해도 된다.
- 그럴 필요 없음. 모든 문자열은 distinct함.
*/
