//원하는 두 칸간의 swap이 가능하므로 삼각형 안의 색깔로 원하는 패턴을 만들 수 있다.
//그러므로 없는 색깔만 추가해주면 된다. 
//구현을 좀 복잡하게 한 것 같은데 더 쉬운 방법이 있을 것 같다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string A,B; cin>>A>>B;
    map<char, int> chk;
    for(char c : A) chk[c]++;
    for(char c : B) chk[c]--;
    int ans = 0;
    for(auto[key,val]:chk){
        ans+=abs(val);
    }
    cout<<ans/2;
	return 0;
}
