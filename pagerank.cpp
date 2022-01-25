#include<bits/stdc++.h>
using namespace std;
int main()
{
	int out[10],n,i,j,k,iter;
	float pr[10],sum,in[10][10]	,d=0.85;
	cout<<"Enter number of nodes";
	cin>>n;
	cout<<"Enter graph matrix (nxn)"<<endl;
	for(i=0;i<n;i++)
	{
		out[i]=0;
		for(j=0;j<n;j++)
		{
			cin>>in[i][j];
			out[i]+=in[i][j];
		}
	}
	cout<<"Array:";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<in[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"The outgoing edge array for the nodes are:";
	for(i=0;i<n;i++)cout<<out[i]<<" ";
	//initailizing page rank as 1
	for(i=0;i<n;i++) pr[i]=1;
	cout<<"Enter number of iterations:";
	cin>>iter;
	for(i=0;i<iter;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0.0;
			for(k=0;k<n;k++)
			{
				if(in[k][j]==1)
					sum+=(pr[k])/out[k];
			}
			cout<<"Su"<<sum;
			pr[j]=(1-d)+(d*sum);
		}
		cout<<"For iteration :"<<i<<endl<<"The page rank array is:";
		for(j=0;j<n;j++) cout<<pr[j]<<" ";
		cout<<endl;
	}
	return 1;
}
