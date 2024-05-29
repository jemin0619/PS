//https://velog.io/@publicminsu/C%EB%B0%B1%EC%A4%80-31631-rightplant
//이분의 풀이를 보고 해결했습니다

//Tag : Ad-hoc, Constructive
//풀이를 떠올리는건 할만해도 증명이 어렵다고 하는데 풀이를 떠올리는것부터 막혔습니다.
//이 문제는 절반으로 나눴을 때 각 부분의 합이 차이가 최소인 길이 N의 수열을 만드는 문제입니다.

//수열을 만드는 알고리즘은 다음과 같습니다.
//F(N)을 만들려면 F(N-1)의 각 요소에 1을 더합니다.
//그 후 적절한 위치에 1을 삽입해주면 되는데 그 점이 어렵습니다.

//일단 N-1을 ii라고 정의합니다.
//ii%4가 0 또는 2라면 수열을 반으로 나누고 사이에 1을 넣는 것이 가능합니다.
//ex1) 4 3 (1) 2 5
//ex2) 6 5 2 (1) 3 4 7

//ii%4가 1일 땐 (ii-1)/2에 1을 삽입해줍니다

//ii%4가 3일 땐 (ii-1)/2 +1 에 1을 삽입해줍니다.

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> H;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N;
    H.push_back(1); H.push_back(2);
    for(int i=3;i<=N;i++){ //길이 i의 수열을 만드는 과정
        int ii=i-1;
        for(int j=0;j<ii;j++){
            H[j]++;
        }
        int idx = ii%4; //(i-1)%4 = {0~3}
        if(idx%2==0) idx=ii/2; //0 or 2 -> 수열의 가운데 숫자를 1로 정함
        else if(idx==1) idx=(ii-1)/2; //1
        else idx=((ii-1)/2)+1; //3

        H.insert(H.begin()+idx,1);
    }
    for(int ans : H) cout<<ans<<' ';
    return 0;
}
