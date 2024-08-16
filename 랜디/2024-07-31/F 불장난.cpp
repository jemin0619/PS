//https://github.com/HaecheonLee/personal-studies/blob/06d3c8854aaa30dfd6bb3c924d0e75fcc8291ea3/PS/BOJ/20201030/%EB%B6%88%EC%9E%A5%EB%82%9C.cpp#L4

//어떻게든 규칙을 찾아내보려고 했는데 실패했다...
//파스칼의 삼각형에 얽매이던게 큰 실수였다.
//3시간동안 분석하다가 그제서야 탑다운 DP로 푸는게 맞는 것 같다는 확인이 섰다.

//y축, x축(기웅), x축(민수) 세 가지의 매개변수를 DFS에 사용했다.
//그에 따라 dx_A와 dx_B를 만들었다.

//좌표 변화 없이 내려가기 (0)
//한 쪽만 앞으로 이동 (1, 2)
//둘 다 앞으로 이동 (3)

//이렇게 해주면 기웅이가 앞에, 민수가 뒤에 있는 경우와 민수가 앞에, 기웅이가 뒤에 있는 경우를 모두 확인할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e4 + 7;

int N;
ll DP[103][103][103];
int dx_A[] = {0,1,0,1};
int dx_B[] = {0,0,1,1};

ll DFS(int y, int Ax, int Bx){
    if(y>1 && Ax==Bx) return 0; //첫 번째 칸이 아닌데 둘이 위치가 겹친 경우
    if(Ax>y || Bx>y) return 0; //문제 조건에 따라 y가 가로축 길이와 같으므로 OOB인 경우이다.
    
    if(y==N) return 1; //정상적으로 마지막 위치에 도달한 경우 1을 반환한다. (새로운 경로를 찾음)

    //메모이제이션
    ll&ret = DP[y][Ax][Bx];
    if(ret != -1) return ret;
    ret = 0;

    for(int dir=0; dir<4; dir++){
        ret += DFS(y+1, Ax+dx_A[dir], Bx+dx_B[dir]);
        ret %= MOD;
    }

    return ret;
}

int main(){
    cin>>N;
    memset(DP, -1, sizeof(DP));
    cout<<DFS(1,1,1);
    return 0;
}
