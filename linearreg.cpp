#include<bits/stdc++.h>
using namespace std;
int main()
{
	float n,x[50],y[50],X=0,Y=0,XY=0,X2=0;
	cout<<"Enter number of datapoints:";
	cin>>n;
	cout<<"Enter datapoints:";
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		X+=x[i];
		Y+=y[i];
		XY+=(x[i]*y[i]);
		X2+=pow(x[i],2);
	}
	float a1=((n*XY)-(X*Y))/((n*X2)-(pow(X,2)));
	float a0=(Y-(a1*X))/n;
	cout<<"Y=("<<a1<<"x)+("<<a0<<")";
	return 1;
}