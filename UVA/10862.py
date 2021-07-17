n=0
fib=list()
fib.append(0)
fib.append(1)
fib.append(1)
for i in range(3,2*(2000+1)):
    fib.append(fib[i-1]+fib[i-2])
while True:
    n=int(input())
    if n==0:
        break
    print(fib[2*n])
