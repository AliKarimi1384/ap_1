#include <bits/stdc++.h>
using namespace std;
float a[4];
int main() {	
	
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	float sum = a[0] + a[1] + a[2] + a[3];
	sort(a,a+4);
	
	float av = sum / 4;
	float pr = a[0] * a[1] * a[2] * a[3];
	float mn = a[0];
	float mx = a[3];
	cout<<"Sum : "<<fixed<<setprecision(6)<<sum<<endl;
	cout<<"Average : "<<fixed<<setprecision(6)<<av<<endl;
	cout<<"Product : "<<fixed<<setprecision(6)<<pr<<endl;
	cout<<"MAX : "<<fixed<<setprecision(6)<<mx<<endl;
	cout<<"MIN : "<<fixed<<setprecision(6)<<mn<<endl;
	
	
}