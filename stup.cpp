#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
int N;
int number;
} struct_in; 

int main(){
	int i,j,k,p,count;
	cin >> k;
	vector <struct_in> n (k)	;
	//int n[k][2];
	for(int i=0;i<k;i++){
		cin>>p;
		n[i].N=p;
		n[i].number=i+1;
	}
	sort(n.begin(),n.end(),[](struct_in a, struct_in b){
		if(a.N==b.N)
			return a.number<b.number;
		return a.N>b.N;});
	p=n[0].N;
	vector <int> a (p);
	for(int i=0;i<p;i++)
		a[i]=n[0].number;
	count=-1;	
	vector<int>::iterator it;
	it=a.begin();
	for(int i=1;i<k;i++){
		for(int j=0;j<n[i].N;j++){
			count+=2;
			if(count<p*2){
				a.insert(it+count,n[i].number);
				it=a.begin();
			}else{
				count=0;
				it=a.begin();
				p=p*2;
				a.insert(it+count,n[i].number);
				it=a.begin();
			}
		}
	}
	for(int i=0;i<a.size();i++)
		cout<< a[i]<<" ";
	cout<<endl;	
	return 0;
}