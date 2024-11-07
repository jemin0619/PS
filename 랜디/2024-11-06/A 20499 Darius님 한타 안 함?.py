#예전엔 C++만을 고집하려는 마음이 있었는데 다 쓸모없는 고집이다.
#상황에 맞는 언어를 쓰는게 최고이다

inp = list(map(int, input().split('/')))
if(inp[0]+inp[2]<inp[1] or inp[1]==0): print("hasu")
else: print("gosu")
