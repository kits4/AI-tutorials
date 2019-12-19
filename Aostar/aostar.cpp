#include<bits/stdc++.h>
using namespace std;
vector<vector<int > >graph;
vector<int>h;
vector<int>goal;
int val;
int store;

void updatefn(int node)
{
h[node]=INT_MAX;
for(int i=0;i<graph[node].size()/2;i++)
{
if(graph[node][2*i+1]==-1)
{
if(h[node]>h[graph[node][2*i]]+1)
h[node]=h[graph[node][2*i]]+1;
}
else
if(h[node]>h[graph[node][2*i+1]]+h[graph[node][2*i]]+2)
h[node]=h[graph[node][2*i+1]]+h[graph[node][2*i]]+2;
}
}

int recur(int node)
{
if(node==-1)
return 0;

int minval=INT_MAX;
for(int i=0;i<graph[node].size()/2;i++)
{
if(graph[node][2*i+1]==-1)
{
cout<<node;
minval=min(h[graph[node][2*i]],minval);
node = graph[node][2*i];
store=node;
cout<<"-->";
cout<<node;
}
else
{
cout<<node;
minval=min(h[graph[node][2*i+1]]+h[graph[node][2*i]],
minval);
if(h[graph[node][2*i+1]]<h[graph[node][2*i]])
{
node = graph[node][2*i+1];
store=node;
cout<<"-->";
cout<<node;
}
else
{
node = graph[node][2*i];
store=node;
cout<<"-->";
cout<<node;
}
}
}
int flag=0;
int nextnode1,nextnode2;

for(int a=0;a<goal.size();a++)
{
if(node==goal[a])
{
cout<<"-->"<<node;
return 1;
}
}

for(int i=0;i<graph[node].size()/2;i++)
{
if(graph[node][2*i+1]==-1)
{
if(h[graph[node][2*i]]+1==h[node])
{
flag=1;
nextnode1=graph[node][2*i];
nextnode2=graph[node][2*i+1];
break;
}
}
else
{
if(h[node]==h[graph[node][2*i+1]]+h[graph[node][2*i]]+2)
{
flag=1;
nextnode1=graph[node][2*i];
nextnode2=graph[node][2*i+1];
break;
}
}
}
if(flag==1)
{
int ab = recur(nextnode1)+recur(nextnode2);
val = h[store];
return ab;
}
else
{
updatefn(node);
return 0;
}

}

int main()
{
int n;
cout<<"Enter the number of nodes"<<endl;
cin>>n;
graph.resize(n);
h.resize(n);
for(int a=0;a<n;a++)
h[a]=INT_MAX;
for(int i=0;i<n;i++)
{
int nn;
cout<<"Enter number of connnections for"<<" "<<i<<endl;
cin>>nn;
if(nn==0)
{
goal.push_back(i);
}
for(int j=0;j<nn;j++)
{
int nodee;
cin>>nodee;
graph[i].push_back(nodee);
}
}
for(int a=1;a<n;a++)
{
cout<<"Enter the heuristic value for"<<" "<<a<<endl;
cin>>h[a];
}

int f=0;
while(f==0)
{
f=recur(0);
cout<<endl;
}
int sk=val+1;
cout<<sk;
return 0;
}
