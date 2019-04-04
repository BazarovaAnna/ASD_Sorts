#include <iostream>
#include <cstdlib> 
#include <algorithm>
#include <vector>
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974
using namespace std;

typedef struct {
long long int x;
long long int y;
int i;
double m;
double ro;
} struct_in; 

int main() 
{
	int n,n1,n2,max_i;
	double x,y,x1,y1,x2,y2,dx,dy,m,max,max_e;
	vector <struct_in> a;
	//structIn[] a;
	
	cin >> n;
	a.resize(n);

	for(int i=0;i<n;i++){
		std::cin >> x >> y;
		a[i].x=x;
		a[i].y=y;
		a[i].i=i+1;
	}
	
	x1=a[0].x;
	y1=a[0].y;
	n1=a[0].i;
	
	for(int i=1;i<n;i++){
		x2=a[i].x;
		y2=a[i].y;
		n2=a[i].i;
		
		dx=x2-x1;
		dy=y2-y1;
		a[i].ro=dx*dx+dy*dy;
		m=atan2(dy,dx)* 180.0 / PI;
		
		a[i].m=m;
	}
	sort(a.begin()+1,a.end(),[](struct_in a, struct_in b){
		if(a.m==b.m)
			return a.ro<b.ro;
		return a.m<b.m;});
	if(n>2){
		max=a[1].m-a[n-1].m+360;
		max_e=max;
		max_i=1;
		for(int i=2;i<n;i++){
			if(max<=(a[i].m-a[i-1].m)){
				max=a[i].m-a[i-1].m;
				max_i=i;
			}
		}
	}else{
		max_e=720;
		max=0;
		max_i=0;
	}
	//for (int i = 0; i < n; ++i) {
    //    std::cout << "x: " << a[i].x << " y: " << a[i].y << " angle: " << a[i].m << " #" << a[i].i << std::endl;
    //}
	if(max==180&&max_e==180){
		if((max_i-1)>(n-max_i)){
			cout<<max_i<<endl;
			for(int i=0;i<max_i;i++)
				cout<<a[i].i<<endl;
		}else{
			cout<<n-max_i+1<<endl;
			cout<<1<<endl;
			for(int i=max_i;i<n;i++)
				cout<<a[i].i<<endl;
		}
	}else{
		cout << n<<endl;
		cout << 1<<endl;
		if(max>180&&(!(max_i==1))){
			for(int i=max_i;i<n;i++){
				cout<< a[i].i<<endl;
			}
			for(int i=1;i<max_i;i++){
				cout<< a[i].i<<endl;
			}
		}else{
			for(int i=1;i<n;i++){
				cout<< a[i].i<<endl;
			}
		}
	}
	
    return 0; 
}