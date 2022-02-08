import math 
from sys import stdin
t=int(stdin.readline())
while(t!=0):
    A=int(stdin.readline(),2)
    B=int(stdin.readline(),2)
    if B==0:
        print(2)
    elif A==0:
        print(1)
    else:
        n=A+B
        lg=int(math.log(n,2))
        pg=int(math.log(B,2))        
        print(lg-pg+1)
    t-=1
