fib=[]
com=[]
fib.append(1)
fib.append(1)
com.append(1)
com.append(2)
for i in range(2,1500+1):
    fib.append(fib[i-1]+fib[i-2])
    com.append(com[i-1]+fib[i])
cnt =1
while True :
    n= int(input())
    if n ==0 :
        break
    print("Set %d:"%cnt)
    if fib[n-1] % 2 == 0:
        print(com[n - 1]  - (fib[n-1] // 2 )-1 )
    else:
        print(com[n - 1] - 1 - fib[n-1] // 2)
    cnt+=1



