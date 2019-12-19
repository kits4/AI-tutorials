#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int level;
    Node *left, *right;
    Node(int val, int lvl): data(val), level(lvl), left(NULL), right(NULL){}
};

Node* constructBST(queue<Node*> helper)
{
    while(1)
    {
        Node *left=helper.front();
        helper.pop();
        if(helper.empty())
        return left;
        Node *right=helper.front();
        helper.pop();
        Node *g=new Node(0, right->level-1);
        g->left=left;
        g->right=right;
        helper.push(g);
    }
}
int AlphaBeta(Node *curr, int alpha, int beta)
{
    if(!curr->left&&!curr->right)
    {
        return curr->data;
    }
    if(curr->level%2)
    {
        beta=min(beta, AlphaBeta(curr->left, alpha, beta));
        if(alpha>=beta){
            cout<<"Alpha cutoff at "<<beta<<endl;
            return beta;
        }
        beta=min(beta, AlphaBeta(curr->right, alpha, beta));
        if(alpha>=beta){
            cout<<"Alpha cutoff at "<<beta<<endl;
            return beta;
        }
        return beta;
    }
    else
    {
        alpha=max(alpha, AlphaBeta(curr->left, alpha, beta));
        if(alpha>=beta){
            cout<<"Beta cutoff at "<<alpha<<endl;
            return alpha;
        }
        alpha=max(alpha, AlphaBeta(curr->right, alpha, beta));
        if(alpha>=beta){
            cout<<"Beta cutoff at "<<alpha<<endl;
            return alpha;
        }
        return alpha;
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int levels;
	cout<<"Enter the number of levels in a conplete BST"<<endl;
	cin>>levels;
	cout<<"Enter "<<(1<<levels)<<" leaf nodes from left to right."<<endl;
	queue<Node *> helper;
	for(int i=0;i<(1<<levels);i++)
	{
	    int val;
	    cin>>val;
	    Node *g=new Node(val, levels);
	    helper.push(g);
	}
	Node *head=constructBST(helper);
	int minimax_value=AlphaBeta(head, INT_MIN, INT_MAX);
	cout<<"The minimax value is "<<minimax_value<<endl;
	return 0;
}

// input:
// 4
// 10 5 7 11 12 8 9 8 5 12 11 12 9 8 7 10

// output:
// Enter the number of levels in a conplete BST
// Enter 16 leaf nodes from left to right.
// Beta cutoff
// Alpha cutoff
// Alpha cutoff
// The minimax value is 8
