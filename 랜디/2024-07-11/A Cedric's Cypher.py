while True:
    S = input()
    if S == "#": 
        break
    Ans = ""
    shift = ord(S[len(S)-1]) - ord('A')
    S = S[:-1]
    for c in S:
        if 'a' <= c <= 'z':
            tmp = ord(c) - shift
            if tmp < ord('a'):
                tmp = ord('z') - (ord('a') - tmp - 1)
            Ans += chr(tmp)
            
        elif 'A' <= c <= 'Z':
            tmp = ord(c) - shift
            if tmp < ord('A'):
                tmp = ord('Z') - (ord('A') - tmp - 1)
            Ans += chr(tmp)
        
        else:
            Ans += c
    print(Ans)
