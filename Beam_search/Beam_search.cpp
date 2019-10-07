#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
vector<int> *adj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int vertices, edges, beam_width, start, target;

    ifstream fin;
    ofstream fout;
    
    fin.open("input.txt");
    fout.open("output.txt");
    fin>>vertices>>edges;
    adj=new vector<int>[vertices+1];    //vertex numbering starts from 1
    
    for(int i=0;i<edges;i++)
    {
        int u,v;
        fin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> heuristics(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        fin>>heuristics[i];
    }
    fin>>beam_width>>start>>target;
    fin.close();

    priority_queue<pair<int, int > , vector<pair<int,int> >, greater<pair<int, int> > >pq;  //minimum priority_queue
    pq.push(make_pair(heuristics[start],start));
    vector<bool > visited(vertices+1, false);
    vector<int >parent(vertices+1, 0);

    while(1)
    {
        vector<int> arr;
        for(int i=0;i<beam_width;i++)
        {
            if(pq.empty())
            break;
            if(pq.top().second==target)
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
            }
            else
            {
                arr.push_back(pq.top().second);
                visited[pq.top().second]=true;
            }
            pq.pop();
        }
        while(!pq.empty()) pq.pop();    //empty the priority_queue (local_search)

        for(int i=0;i<arr.size();i++)
        {
            int u=arr[i];
            for(int j=0;j<adj[u].size();j++)
            {
                int v=adj[u][j];
                if(!visited[v])
                {
                    pq.push(make_pair(heuristics[v],v));
                    parent[v]=u;
                }
            }
        }
        if(pq.empty())break;
    }
    fout.close();
    return 0;
}