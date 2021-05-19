#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int n,a[30][30],visited[30];
void topo(int v)
{
	visited[v]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[v][i]==1 && !visited[i])
			topo(i);
	}
	s.push(v);
}

int main()
{
	cout<<"Enter the no of vertices"<<endl;
	cin>>n;
	cout<<"Enter the adjacency matrix"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
		visited[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			topo(i);
	}
	
	cout<<"The topological ordering of vertices is"<<endl;

	while(s.empty()==false)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\n";
	return 0;
}
