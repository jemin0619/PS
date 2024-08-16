//수학 공식을 알아야 합니다.
//1~N의 합은 N(N+1)/2 라는 것을 한 문자를 돌때마다 O(1)에 순간에서의 ans를 구할 수 있습니다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,cnt,ans;
string S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>S;
    for(char c : S){
        if(c=='2') cnt++;
        else {cnt=0; continue;}
        ans += (cnt*(cnt+1)/2);
    }
    cout<<ans;
    return 0;
}
