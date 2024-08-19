//처음에 정사각형이였다고 하므로 한 변의 길이를 구하고 *4 하면 된다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    N*=2;
    int X = sqrt(N);
    cout<<X*4;
    return 0;
}
