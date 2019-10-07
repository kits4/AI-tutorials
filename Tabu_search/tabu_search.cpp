
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
vector<int> tabu(4, 0);
void change_1(string start, string target, int tenure)
{
    if(start==target)
    {
        cout<<start<<" --> "<<target<<endl;
    }
    else
    {
        cout<<start;
    }
    bool flag=false;
    for(int i=0;i<100;i++)
    {
        int y=rand()%4;
        // cout<<y<<" "<<endl;
        if(tabu[y]==0)
        {
            (start[y]=='0')?(start[y]='1'):(start[y]='0');
            tabu[y]=tenure;
            cout<<" --> "<<start;
        }
        else
        {
            tabu[y]--;
        }
        if(start==target)
        {
            cout<<endl<<"Target achieved!!!"<<endl;
            flag=true;
            break;
        }
    }
    if(!flag)
    {
        cout<<"Target not achievable."<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string start, target;
    int tenure;
    cout<<"Starting State"<<endl;
    cin>>start;
    cout<<"Target State"<<endl;
    cin>>target;
    cout<<"Tabu Tenure"<<endl;
    cin>>tenure;

    change_1(start, target, tenure);
    return 0;
}