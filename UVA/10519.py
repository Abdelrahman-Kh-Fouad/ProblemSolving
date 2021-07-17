while True:
	try:
		n=input()
		n=int(n)
		if n ==0 :
			print(1)
		else :
			print(int(n*n -(n-2)))
	except:
		break

