import time
a=[1]
b=[]
prime={2:0}
stime=time.time()
for n1 in a:
	b=range(2,n1//2)
	r=0
	for n2 in b:
		if n1%n2 == 0:
			r=0
			break
		r=1
	if r==1:
		prime[n1] = time.time()-stime
		print(n1,'\t',prime[n1])
		f = open('/home/libert/Works/prime','a',encoding='UTF-8')
		data=('{}\t{}\n'.format(n1,prime[n1]))	
		f.write(data)
		f.close()
	a.append(n1+1)
