#include <iostream>
#include <cstdlib> 
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() 
{
	long long int n,i,x,y,ans;
	vector <long long int> a,b;
	//structIn[] a;
	
	cin >> n;
	a.resize(n);
	b.resize(n);
	for(i=0;i<n;i++){
		std::cin >> x >> y;
		a[i]=x;
		b[i]=y;
	}

	sort(a.begin(),a.end(),[](long long int t, long long int t1){
		return t<t1;});
	sort(b.begin(),b.end(),[](long long int t, long long int t1){
		return t<t1;});
		
	ans=0;
	
	for(i=0; i<n-1 ; i++){
		ans=ans+abs(a[i+1]-a[i])*(i+1)*(n-i-1)*2;
		ans=ans+abs(b[i+1]-b[i])*(i+1)*(n-i-1)*2;
	}
	ans=ans/(n*(n-1));
	cout << ans <<endl;
	return 0;
}
