import time
a=[1]
b=[]
prime=[2]
stime=time.time()
for n1 in a:
	b=range(2,n1)
	r=0
	for n2 in b:
		if n1%n2 == 0:
			r=0
			break
		r=1
	if r==1:
		prime.append(n1)
		print(prime[-1],'\t',time.time()-stime)
	a.append(n1+1)
	
