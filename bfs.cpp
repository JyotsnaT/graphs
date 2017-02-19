/*Reference - geeksforgeeks*/
#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph
{
    list<int> *AdjList;
    int V;
    public:
        Graph(int size)
        {
            V = size;
            AdjList = new list<int>[V];
        }
        
        void addEdge(int a, int b)
        {
            AdjList[a].push_back(b);
        }
            
        void BFS(int source)
        {
            bool visited[V];
            for(int i = 0;i<V;i++)
                visited[i] = false;
                
            queue<int> Q;
            Q.push(source);
            
            while(!Q.empty())
            {
                int T = Q.front();
                Q.pop();
                visited[T] = true;
                cout<<T<<' ';
                
                list<int>::iterator it;
                for(it = AdjList[T].begin(); it != AdjList[T].end(); ++it)
                    if(!visited[*it])
                        Q.push(*it);
            }
        }
};

int main()
{
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(2,0);
    G.addEdge(2,3);
    G.addEdge(3,3);
    
    G.BFS(0);
    return 0;
}
