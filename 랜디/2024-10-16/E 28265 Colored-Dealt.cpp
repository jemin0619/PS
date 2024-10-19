#include <string>
#include "colored_dealt.h"

//B N개로 구성된 문자열을 S라고 할 때, design(S) = N*3 이다.
//S의 글자를 마지막 글자부터 하나씩 R로 바꾸어가면 제이가 넣은 꽃의 순서를 구할 수 있다.
//R은 1이므로 R이 골라지는 상황이라면 제이의 특정 꽃과 내가 넣은 꽃 모두 R이라는 것을 알 수 있다.

//N이 4라고 가정한다.
//초기 value를 4*3 = 12라고 설정한다. (B 4개)
//BBBR XXXX 라고 하면, 내가 설정한 R을 고르거나, 4번째 X를 골라야 하는데, 
//R 가장 작은 단위이므로 X를 고른다고 볼 수 있다.
//그러므로 design(BBBR)의 반환값을 ret이라고 할 때, 12-ret의 값에 따라 4번째 X가 무엇인지 알 수 있다.

//0이라면 그대로라는 뜻이므로 B, 
//1이라면 B에서 하나 차이난다는 의미이므로 G,
//2라면 B에서 2 차이난다는 의미이므로 R이 된다.

std::string guess(int N){
	std::string ret(N, '?');
	std::string S(N, 'B');
	int pre = N*3;
	for(int i=0; i<N; i++){
		S[i] = 'R';
		int cur = design(S);
		int diff = pre-cur;
		if(diff==0) ret[i] = 'B';
		else if(diff==1) ret[i] = 'G';
		else ret[i] = 'R';
		pre = cur;
	}
	return ret;
}
