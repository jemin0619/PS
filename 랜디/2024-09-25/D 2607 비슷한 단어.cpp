//구성이 일치하는 경우, 길이 관계없이 하나 다른 경우, 길이 같고 두 개 다른 경우 ans++

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N; N--;
    string S; cin>>S;
    vector<int> V1(26, 0);
    for(char c : S) V1[c-'A']++;
    int ans = 0;
    while(N--){
        string x; cin>>x;
        vector<int> V2(26, 0);
        for(char c : x) V2[c-'A']++;
        if(V1==V2) {ans++; continue;} //같은 구성을 갖는 경우
        int diff = 0;
        for(int i=0; i<26; i++){
            diff += abs(V1[i]-V2[i]);
        }
        if(diff==1) {ans++; continue;} 
        if(x.size()==S.size() && diff==2) ans++;
    }
    cout<<ans; 
    return 0;
}
