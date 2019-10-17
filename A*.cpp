#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
vector<pair<int, int> > *adj;
priority_queue<pair<int, int > , vector<pair<int,int> >, greater<pair<int, int> > >open;      //minimum priority_queue

void propogate_improvement(int start, vector<bool > &op , vector<bool > &visited, vector<int > &parent, vector<int > &g, vector<int > heuristics, vector<int > &f)
{
    for(int i=0;i<adj[start].size();i++)
    {
        int v=adj[start][i].first;
        int weight=adj[start][i].second;
        if(g[start]+weight<g[v])
        {
            parent[v]=start;
            g[v]=g[start]+weight;
            f[v]=g[v]+heuristics[v];
            if(op[v])
            {
                stack<pair<int, int> > hello;
                while(open.top().second!=v)
                {
                    hello.push(open.top());
                    open.pop();
                }
                open.pop();
                open.push(make_pair(f[v],v));
                while(!hello.empty())
                {
                    open.push(hello.top());
                    hello.pop();
                }
            }
            else if(visited[v])  propogate_improvement(v, op, visited, parent, g, heuristics, f);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int vertices, edges, start, target;

    ifstream fin;
    ofstream fout;
    
    fin.open("input.txt");
    fout.open("output.txt");
    fin>>vertices>>edges;
    adj=new vector<pair<int, int > >[vertices+1];                                             //vertex numbering starts from 1
    
    for(int i=0;i<edges;i++)
    {
        int u, v, w;
        fin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));                                                     //directed_graph
    }
    
    vector<int> heuristics(vertices+1,0);
    vector<int> g(vertices+1, 0);
    vector<int> f(vertices+1, 0);
    
    for(int i=1;i<=vertices;i++)
    {
        fin>>heuristics[i];
    }
    
    fin>>start>>target;
    fin.close();
    g[start]=0;
    f[start]=heuristics[start];

    open.push(make_pair(f[start],start));
    vector<bool > visited(vertices+1, false);
    vector<bool > op(vertices+1, false);
    vector<int >parent(vertices+1, 0);
    op[start]=true;
    while(1)
    {
        if(open.empty())
            break;
            
        int u=open.top().second;
        visited[u]=true;
        op[u]=false;
        open.pop();
        
        if(u==target)
        {
            stack<int> path;
            int y=target;
            path.push(y);
            while(y!=start)
            {
                path.push(parent[y]);
                y=parent[y];
            }
            fout<<path.top();
            path.pop();
            while(!path.empty())
            {
                fout<<" --> "<<path.top();
                path.pop();
            }
            fout<<endl;
			fout<<"Optimal Cost is --> "<<g[target]<<endl;
            break;
        }
        else
        {
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i].first;
                int weight= adj[u][i].second;
                if(!visited[v]&&!op[v])
                {
                    parent[v]=u;
                    g[v]=g[u]+weight;
                    f[v]= g[v]+heuristics[v];
                    op[v]=true;
                    open.push(make_pair(f[v],v));
                }
                else if(op[v]&&!visited[v])
                {
                    if(g[u]+weight<g[v])
                    {
                        parent[v]=u;
                        g[v]=g[u]+weight;
                        f[v]=g[v]+heuristics[v];
                        stack<pair<int, int> > hello;
                        while(open.top().second!=v)
                        {
                            hello.push(open.top());
                            open.pop();
                        }
						open.pop();
                        open.push(make_pair(f[v],v));
                        while(!hello.empty())
                        {
                            open.push(hello.top());
                            hello.pop();
                        }
                    }
                }
                else
                {
                    if(g[u]+weight<g[v])
                    {
                        parent[v]=u;
                        g[v]=g[u]+weight;
                        f[v]=g[v]+heuristics[v];
                        propogate_improvement(v, op, visited, parent, g, heuristics, f);
                    }
                }
            }
        }
    }
    fout.close();
    return 0;
}
