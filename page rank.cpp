#include<bits/stdc++.h>
using namespace std;
int main()
{
	int in[10][10],out[10],n,i,j;
	cout<<"Enter number of nodes";
	cin>>n;
	cout<<"Enter graph matrix (nxn)";
	for(i=0;i<n;i++)
	{
		out[i]=0;
		for(j=0;j<n;j++)
		{
			cin>>in[i][j];
			out[i]+=in[i][j];
		}
	}
	cout<<"The outgoing edge array for the nodes are:";
	for(i=0;i<n;i++)
	{
		cout<<out[i]<<" ";
	}
	return 1;
}
