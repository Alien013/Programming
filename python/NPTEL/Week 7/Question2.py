def Transpose(M):
    T = list()
    for i in range(len(M[0])):
        t = list()
        for j in range(len(M)):
             t.append(M[j][i])
        T.append(t)
    return (T)
n = int(input())
M = []
for i in range(n):
    L = list(map(int, input().split()))
    M.append(L)
print(Transpose(M))
