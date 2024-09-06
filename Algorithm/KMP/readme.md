## KMP 설명 자료
### [[바킹독의 실전 알고리즘] 0x1E강 - KMP](https://www.youtube.com/watch?v=9bkbV-VANQ0)
### [KKS227 KMP 알고리즘(Knuth–Morris–Pratt Algorithm)](https://m.blog.naver.com/PostView.naver?blogId=kks227&logNo=220917078260&navType=by)

## KMP란
- 문자열 매칭 알고리즘
- O(N+M)에 동작한다.
- 어려운 편에 속하는 알고리즘이다...
- 응용이 없는 KMP 문제는 C++에선 strstr, 파이썬에선 in으로 처리할 수 있다.

```cpp
//BOJ 9253 스페셜 저지

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    string A,B,C; cin>>A>>B>>C;
    cout<<(strstr(A.c_str(), C.c_str()) && strstr(B.c_str(), C.c_str())?"YES":"NO");
    return 0;
}
```
