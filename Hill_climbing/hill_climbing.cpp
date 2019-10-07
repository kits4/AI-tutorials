#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
map<string, bool> visited;
map<string, string> parent;
int eval_heuristic(string curr, string target)
{
    int count=0;
    for(int i=0;i<4;i++)
    {
        if(curr[i]==target[i])
        {
            count++;
        }
    }
    return count;
}
void print_path(string target)
{
    cout<<endl;
    stack<string >path;
    string f=target;
    path.push(target);
    while(f!="hello")
    {
        path.push(parent[f]);
        f=parent[f];
    }
    path.pop();
    cout<<path.top();
    path.pop();
    while(!path.empty())
    {
        cout<<" --> "<<path.top();
        path.pop();
    }
    cout<<endl;
}
void fun_1(string start, string target)
{
    string curr=start;
    string next=curr;
    int curr_heuristic_val=eval_heuristic(curr, target);
    while(1)
    {
        for(int i=0;i<4;i++)
        {
            (curr[i]-'0'==0)?(curr[i]=1+'0'):(curr[i]=0+'0');
            if(!visited[curr])
            {
                int get=eval_heuristic(curr, target);
                if(get>curr_heuristic_val)
                {
                    curr_heuristic_val=get;
                    next=curr;
                }
            }
            (curr[i]-'0'==0)?(curr[i]=1+'0'):(curr[i]=0+'0');
        }
        if(next!=curr)
        {
            parent[next]=curr;
            curr=next;
            visited[next]=true;
        }
        else
        {
            cout<<endl;
            cout<<"Destination is not reachable !!!\n Try some other neighbourhood function"<<endl;
            break;
        }
        if(curr==target)
        {
            print_path(target);
            break;
        }
    }
}

void fun_2(string start, string target)
{
    string curr=start;
    string next=curr;
    int curr_heuristic_val=eval_heuristic(curr, target);
    while(1)
    {
        for(int i=0;i<4;i++)
        {
            (curr[i]-'0'==0)?(curr[i]=1+'0'):(curr[i]=0+'0');
            for(int j=i+1;j<=3;j++)
            {
                (curr[j]-'0'==0)?(curr[j]=1+'0'):(curr[j]=0+'0');
                if(!visited[curr])
                {
                    int get=eval_heuristic(curr, target);
                    if(get>curr_heuristic_val)
                    {
                        curr_heuristic_val=get;
                        next=curr;
                    }
                }
                (curr[j]-'0'==0)?(curr[j]=1+'0'):(curr[j]=0+'0');
            }
            (curr[i]-'0'==0)?(curr[i]=1+'0'):(curr[i]=0+'0');
        }
        if(next!=curr)
        {
            parent[next]=curr;
            curr=next;
            visited[next]=true;
        }
        else
        {
            cout<<endl;
            cout<<"Destination is not reachable !!!\n Try some other neighbourhood function"<<endl;
            break;
        }
        if(curr==target)
        {
            print_path(target);
            break;
        }
    }
}
void fun_3(string start, string target)
{
    string curr=start;
    string next=curr;
    int curr_heuristic_val=eval_heuristic(curr, target);
    while(1)
    {
        for(int i=0;i<4;i++)
        {
            (curr[i]-'0'==0)?(curr[i]=1+'0'):(curr[i]=0+'0');
            for(int j=i+1;j<=3;j++)
            {
                (curr[j]-'0'==0)?(curr[j]=1+'0'):(curr[j]=0+'0');
                for(int k=j+1;k<=3;k++)
                {
                    (curr[k]-'0'==0)?(curr[k]=1+'0'):(curr[k]=0+'0');
                    if(!visited[curr])
                    {
                        int get=eval_heuristic(curr, target);
                        if(get>curr_heuristic_val)
                        {
                            curr_heuristic_val=get;
                            next=curr;
                        }
                    }
                    (curr[k]-'0'==0)?(curr[k]=1+'0'):(curr[k]=0+'0');
                }
                (curr[j]-'0'==0)?(curr[j]=1+'0'):(curr[j]=0+'0');
            }
            (curr[i]-'0'==0)?(curr[i]=1+'0'):(curr[i]=0+'0');
        }
        if(next!=curr)
        {
            parent[next]=curr;
            curr=next;
            visited[next]=true;
        }
        else
        {
            cout<<endl;
            cout<<"Destination is not reachable !!!\n Try some other neighbourhood function"<<endl;
            break;
        }
        if(curr==target)
        {
            print_path(target);
            break;
        }
    }
}
void fun_4(string start, string target)
{
    string curr=start;
    for(int i=0;i<4;i++)
    (curr[i]-'0'==0)?(curr[i]=1+'0'):(curr[i]=0+'0');
    if(curr==target)
    {
        cout<<start<<" --> "<<target<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Destination is not reachable !!!\n Try some other neighbourhood function"<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<=15;i++)
    {
        string str;
        int u=i;
        while(u)
        {
            int r=u%2;
            if(r)
            str='1'+str;
            else
            str='0'+str;
            u=u/2;
        }
        visited[str]=false;
    }
    cout<<"Enter the starting state";
    string start;
    cin>>start;

    cout<<"Enter the destination";
    string target;
    cin>>target;

    cout<<"Enter the Number of bits to be changed";
    int a;
    cin>>a;
    parent[start]="hello";
    switch(a)
    {
        case 1:
            fun_1(start,target);
            break;
        case 2:
            fun_2(start,target);
            break;
        case 3:
            fun_3(start,target);
            break;
        case 4:
            fun_4(start,target);
            break;
        default:
            cout<<"wrong input"<<endl;
    }

    return 0;
}