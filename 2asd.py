num=int(input())
s=list(input())
a=list()
n=len(s)
for i in range(n):
    m=[0]*n
    m[-1]=s[i]
    a.append(m)
s.sort()
for i in range(n):
    a[i][0]=s[i]

def Print(a):
    for i in range(n):
        print(*a[i])
    print()

for i in range(n-2):

    #do iteration of bwt
    for j in range(n):
        minimas=list()
        minimas.append(a[j][-1])
        
        minimas+=a[j][:i+1]
        minimas=minimas[:i+2]
        #print(*minimas)
        #minimas needs to have i+2 elems now
        #it has common i+1 elems with others
        gul=False
        for k in range(n):
            f=True
            for z in range(len(minimas)-1):
                if a[k][z]!=minimas[z]:
                    f=False
            if f and a[k][len(minimas)-1]==0:
                a[k][len(minimas)-1]=minimas[-1]
                gul=True
            if gul: break
        #Print(a)
            
print(*a[num-1], sep="")
