x1=[0,0,1,1]
x2=[0,1,0,1]
y=[0,0,0,1]

th=-2.5

def check_weights(w1,w2):
	for i in range(4):
		if ((w1*x1[i]+w2*x2[i]+th) >0 and y[i]==0):
			w1=w1-x1[i]
			w2=w2-x2[i]
		if ((w1*x1[i]+w2*x2[i]+th) <=0 and y[i]==1):
			w1=w1+x1[i]
			w2=w2+x2[i]
	if th>0:
		sign='+'
	else:
		sign=''
	print(f"{w1}x1 + {w2}x2 {sign} {th} =0")

check_weights(1,1)
