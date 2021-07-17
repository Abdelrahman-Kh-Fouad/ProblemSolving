fact=list()
def c(n,k):
    return  fact[n]//(fact[k]*fact[n-k])
fact.append(1)
for i in range(1,2002):
    fact.append(fact[i-1]*i)

while True:
    try :
        n=int(input())
    except :
        break
    print(fact[2*n] // ((n+1)*fact[n]*fact[n] ) )