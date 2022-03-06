import time
a=3
prime=[2]
stime=time.time()
while 1==1:
	print(prime[-1],'\t',time.time()-stime)
	b=a-1
	r=0
	while b>=2:
		if a%b ==0:
			r=0
			break
		b-=1
		r=1
	if r==1:
		prime.append(a)
	a+=1	

