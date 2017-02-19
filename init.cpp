/*reference - geeksforgeeks*/
#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int el)
    {
        data = el;
        next = NULL;
    }
};

class AdjList
{
    struct node **arr;
    int V;
    public:
        AdjList(int size)
        {
            V = size;
            arr = new struct node* [V];
            for(int i = 0;i<V;i++)
                arr[i] = NULL;
        }
        void addEdge(int a, int b)
        {
            struct node *newNode = new node(b);
            newNode->next = arr[a];
            arr[a] = newNode;
            /*If undirected graph*/
            struct node* newNode2 = new node(a);
            newNode2->next = arr[b];
            arr[b] = newNode2;
        }
        void printList()
        {
            for(int i = 0;i<V;i++)
            {
                struct node *temp = arr[i];
                while(temp)
                {
                    cout<<temp->data<<' ';
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
};

int main()
{
    AdjList G(5);
    G.addEdge(0,1);
    G.addEdge(0,4);
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(1,4);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.printList();
    return 0;
}
