#include <iostream>
#include <cstdlib> 
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {
double x;
double y;
int i;
double m;
} struct_in; 
//put here structure (x,y,i)

int main() 
{
	int n,n1,n2;
	double x,y,x1,y1,x2,y2,dx,dy,m;
	
	vector <struct_in> a;
	//structIn[] a;
	
	cin >> n;
	a.resize(n);

	for(int i=0;i<n;i++){
		std::cin >> x >> y;
		a[i].x=x;
		a[i].y=y;
		a[i].i=i;
	}
	swap(a[0],a[distance(a.begin(),min_element(a.begin(),a.end(),[](struct_in a,struct_in b){
		return a.x<b.x;}))]);
	x1=a[0].x;
	y1=a[0].y;
	n1=a[0].i;
	
	for(int i=1;i<n;i++){
		x2=a[i].x;
		y2=a[i].y;
		n2=a[i].i;
		
		dx=x2-x1;
		dy=y2-y1;
		
		m=atan2(dy,dx);
		a[i].m=m;

	}
	sort(a.begin()+1,a.end(),[](struct_in a, struct_in b){
		return a.m<b.m;});
	//print(l[(len(l)-1)//2][1][0],l[(len(l)-1)//2][1][1])
	cout << n1+1<< " " << a[n/2].i+1 <<endl;
    return 0; 
}
