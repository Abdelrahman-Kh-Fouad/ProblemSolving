fact=list()
fact.append(1)
for i in range(1 , 2002):
    fact.append(fact[i-1]*i)
cat =dict()
for i in range(1, 1001):
    res = fact[2*i] // (fact[i]*fact[i]* (i+1))
    if res >4294967295 :
        break
    cat.get(res , 0)
    cat[res]=i
while True :
    try :
        n = int (input())
    except:
        break
    print(cat[n])