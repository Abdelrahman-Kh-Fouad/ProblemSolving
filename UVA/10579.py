import math
f =list()
f.append(1)
f.append(1)
i =2
while 1 :
    f.append(f[i-1]+f[i-2])
    if math.log10(f[i]) > 1000:
        break
    i+=1
while True:
    try :
        n=int(input())
        print(f[n-1])
    except:
        break
