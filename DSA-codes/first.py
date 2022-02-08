t=int(input())
for i in range(t):
    inp=list(map(int,input().split()))
    u=inp[0]
    h=inp[1]
    k=inp[2]
    m = (int)(1e9+7)
    g=1000
    r=((u*u)*(u*u+2*g*h))/(g*g)
    k=k/2
    ans=pow(r,k)
    ans=ans%m
    x=int(ans)
    if ans%x==0:
        print(x)
    else:
        print(ans)