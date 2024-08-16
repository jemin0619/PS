#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

struct Position{
    ll st_mul;
    ll st_add;
    ll en_mul;
    ll en_add;
    ll get_StPos(ll N){
        return st_mul*N+st_add;
    }
    ll get_EnPos(ll N){
        return en_mul*N+en_add;
    }
};

struct st_Point{
    ll mul;
    ll add;
    Position st_Y;
    Position st_X;
    ll get_Stpoint(ll N){ //구간 시작값 반환
        return mul*N+add;
    }
};

vector<st_Point> V(20000); //각 구간들의 시작 숫자를 [mul*X + add] 형태로 저장

void init(){ //전처리
    V[0].st_X.st_mul=0; V[0].st_X.st_add=1;
    V[0].st_X.en_mul=1; V[0].st_X.en_add=0;
    V[0].st_Y.st_mul=0; V[0].st_Y.st_add=1;
    V[0].st_Y.en_mul=0; V[0].st_Y.en_add=1;

    V[1].st_X.st_mul=1; V[1].st_X.st_add=0;
    V[1].st_X.en_mul=1; V[1].st_X.en_add=0;
    V[1].st_Y.st_mul=0; V[1].st_Y.st_add=2;
    V[1].st_Y.en_mul=1; V[1].st_Y.en_add=0;

    V[2].st_X.st_mul=1; V[2].st_X.st_add=-1;
    V[2].st_X.en_mul=0; V[2].st_X.en_add=1;
    V[2].st_Y.st_mul=1; V[2].st_Y.st_add=0;
    V[2].st_Y.en_mul=1; V[2].st_Y.en_add=0;

    V[3].st_X.st_mul=0; V[3].st_X.st_add=1;
    V[3].st_X.en_mul=0; V[3].st_X.en_add=1;
    V[3].st_Y.st_mul=1; V[3].st_Y.st_add=-1;
    V[3].st_Y.en_mul=0; V[3].st_Y.en_add=2;

    V[0].mul=0; V[0].add=1;
    for(int i=1;i<20000;i++){
        V[i].mul = V[i-1].mul + 1;
        V[i].add = V[i-1].add - i/2;
        if(i>=4){
            if(i%4==0){ //Y: st+1(=en+1) /X: st+1 ~ en-1
                V[i].st_X.st_mul = V[i-4].st_X.st_mul;
                V[i].st_X.en_mul = V[i-4].st_X.en_mul;
                V[i].st_Y.st_mul = V[i-4].st_Y.st_mul;
                V[i].st_Y.en_mul = V[i-4].st_Y.en_mul;


                V[i].st_Y.st_add = V[i-4].st_Y.st_add + 1;
                V[i].st_Y.en_add = V[i-4].st_Y.en_add + 1;
                V[i].st_X.st_add = V[i-4].st_X.st_add + 1;
                V[i].st_X.en_add = V[i-4].st_X.en_add - 1;
            } 
            if(i%4==1){ //Y: st+1 ~ en-1 /X: st-1(=en-1)
                V[i].st_X.st_mul = V[i-4].st_X.st_mul;
                V[i].st_X.en_mul = V[i-4].st_X.en_mul;
                V[i].st_Y.st_mul = V[i-4].st_Y.st_mul;
                V[i].st_Y.en_mul = V[i-4].st_Y.en_mul;

                V[i].st_Y.st_add = V[i-4].st_Y.st_add + 1;
                V[i].st_Y.en_add = V[i-4].st_Y.en_add - 1;
                V[i].st_X.st_add = V[i-4].st_X.st_add - 1;
                V[i].st_X.en_add = V[i-4].st_X.en_add - 1;
            }
            if(i%4==2){ //Y: st-1(=en-1) /X: en+1 ~ st-1
                V[i].st_X.st_mul = V[i-4].st_X.st_mul;
                V[i].st_X.en_mul = V[i-4].st_X.en_mul;
                V[i].st_Y.st_mul = V[i-4].st_Y.st_mul;
                V[i].st_Y.en_mul = V[i-4].st_Y.en_mul;

                V[i].st_Y.st_add = V[i-4].st_Y.st_add - 1;
                V[i].st_Y.en_add = V[i-4].st_Y.en_add - 1;
                V[i].st_X.st_add = V[i-4].st_X.st_add - 1;
                V[i].st_X.en_add = V[i-4].st_X.en_add + 1;
            }
            if(i%4==3){ //Y: en+1 ~ st-1 /X: st+1(=en+1)
                V[i].st_X.st_mul = V[i-4].st_X.st_mul;
                V[i].st_X.en_mul = V[i-4].st_X.en_mul;
                V[i].st_Y.st_mul = V[i-4].st_Y.st_mul;
                V[i].st_Y.en_mul = V[i-4].st_Y.en_mul;

                V[i].st_Y.st_add = V[i-4].st_Y.st_add - 1;
                V[i].st_Y.en_add = V[i-4].st_Y.en_add + 1;
                V[i].st_X.st_add = V[i-4].st_X.st_add + 1;
                V[i].st_X.en_add = V[i-4].st_X.en_add + 1;
            }
        }
    }    
}

//https://velog.io/@sungpaks/BOJ-C-25294-%EB%8B%AC%ED%8C%BD%EC%9D%B4%EC%99%80-%EC%BF%BC%EB%A6%AC
int query1(int n, int x, int y) {
	//n X n 달팽이배열에서 x, y좌표에 있는 수를 찾는다
	if (y == 1) return x;
	if (x == n/2+1 && y == n/2+1) return n*n;
	int cur = n;
	int curX = n, curY = 1;
	int flag = 0;
	int i = 1;
	while (1) {
		if (curX == x) {
			cur += y - curY;
			return cur;
		}
		curY += n-i;
		cur += n-i;
		if (curY == y) {
			cur += curX - x;
			return cur;
		}
		curX -= n-i;
		cur += n-i;
		i++;
		if (curX == x) {
			cur += curY - y;
			return cur;
		}
		curY -= n-i;
		cur += n-i;
		if (curY == y) {
			cur += x - curX;
			return cur;
		}
		curX += n-i;
		cur += n-i;
		i++;
	}
}

pair<ll,ll> query2(int N, int Z){ //OK
    //V[0] ~ V[N*2 -2]
    //인덱스는 0 ~ N*2-2 사이를 돌아야 하므로 

    //check(mid) : mid 구간의 시작값이 Z보다 작거나 같은가?
    //1 1 0 0으로 존재 -> st가 알맞은 구간의 시작값의 인덱스가 됨
    ll st = -1; ll en = N*2-1;
    while(st+1<en){
        ll mid = (st+en)/2;
        if(V[mid].get_Stpoint(N)<=Z) st=mid;
        else en=mid;
    }

    ll diff = Z - V[st].get_Stpoint(N);
    if(st%4==0){ //→
        return {V[st].st_Y.get_StPos(N), V[st].st_X.get_StPos(N)+diff};
    }
    if(st%4==1){ //↓
        return {V[st].st_Y.get_StPos(N)+diff, V[st].st_X.get_StPos(N)};
    }
    if(st%4==2){ //←
        return {V[st].st_Y.get_StPos(N), V[st].st_X.get_StPos(N)-diff};
    }
    if(st%4==3){ //↑
        return {V[st].st_Y.get_StPos(N)-diff, V[st].st_X.get_StPos(N)};
    }
}

int main(){
    fastio;
    init();
    int T; cin>>T;
    while(T--){
        int Q; cin>>Q;
        if(Q==1){
            int N, Y, X; cin>>N>>Y>>X;
            cout<<query1(N, X, Y)<<'\n';
        }
        if(Q==2){
            int N, Z; cin>>N>>Z;
            pair<ll,ll> Ans = query2(N,Z);
            cout<<Ans.first<<' '<<Ans.second<<'\n';
        }
    }
    return 0;
}    
