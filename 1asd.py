n=int(input())
a=list()
for i in range(n):
    x,y=map(int,input().split())
    a.append((x,y))
def f(a,n):
    for i in range(n-1):
        for j in range(i,n):
            x1=a[i][0]
            x2=a[j][0]
            y1=a[i][1]
            y2=a[j][1]
            countup=0
            countdown=0
            if(x1==x2):#x=const
                for l in range(n):
                    if a[l][0]<x1:
                        countdown+=1
                    elif a[l][0]>x1:
                        countup+=1
                if countup==countdown:
                    print(i+1,j+1)
                    return
            elif(y1==y2):#y=const
                for l in range(n):
                    if a[l][1]<y1:
                        countdown+=1
                    elif a[l][1]>y1:
                        countup+=1
                if countup==countdown:
                    print(i+1,j+1)
                    return
            else:
                k=(y2-y1)/(x2-x1)
                b=y1-(x1*(y2-y1)/(x2-x1))
                for l in range(n):
                    if(a[l][1]>k*a[l][0]+b):
                        countup+=1
                    elif(a[l][1]<k*a[l][0]+b):
                        countdown+=1
                if countup==countdown:
                    print(i+1,j+1)
                    return
f(a,n)
