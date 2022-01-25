#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i1,i2,i,n,itr=0;
	float l[50],k1[50],sk1=0,k2[50],sk2=0;
	float m1,m2,c1,c2;
	cout<<"Enter number of elements";
	cin>>n;
	cout<<"Enter elememts:";
	for(i=0;i<n;i++)
	{
		cin>>l[i];
	}
	cout<<"Enter cluster centers:";
	cin>>m1>>m2;
	do
	{
		c1=m1;
		c2=m2;
		for(i=0,i1=0,i2=0;i<n;i++)
		{
			float t1=fabs(l[i]-c1);
			float t2=fabs(l[i]-c2);  
			//cout<<t1<<t2;	
			if(t1<t2)
			{
				k1[i1++]=l[i];sk1+=l[i];
			}
			else
			{
				k2[i2++]=l[i];sk2+=l[i];
			}
		}
		m1=sk1/(i1);
		m2=sk2/(i2);
		cout<<"Iteration:"<<++itr<<"\nCluster 1:";
		for(i=0;i<i1;i++) cout<<k1[i]<<" ";
		cout<<"\nCluster 2:";
		for(i=0;i<i2;i++) cout<<k2[i]<<" ";
		cout<<endl;
		cout<<"Cluster centers (m1,m2):("<<m1<<","<<m2<<")"<<endl;
		sk1=0;sk2=0;
	}while(m1!=c1 || m2!=c2);
	cin>>n;
	cout<<"Exit;";
	return 1;
}
