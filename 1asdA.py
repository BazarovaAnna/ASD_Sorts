import math
n=int(input())

a=list()
for i in range(n):
    x,y=map(float,input().split())
    a.append((x,y,i))
a.sort()

x1=a[0][0]
y1=a[0][1]
n1=a[0][2]+1

l=list()
for i in range(1,n):    
    x2=a[i][0]
    y2=a[i][1]
    n2=a[i][2]+1

    dx=x2-x1
    dy=y2-y1
    
    m=math.atan2(dy,dx)
    l.append((m,(n1,n2)))
    
l.sort()
#print(*l)
print(l[(len(l)-1)//2][1][0],l[(len(l)-1)//2][1][1])
