#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    int V;
    int** adjMatrix;
} Graph;

Graph* creategraph(int V)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int**)calloc(V, sizeof(int*));
    for (int i = 0; i < V; i++)
        graph->adjMatrix[i] = (int*)calloc(V, sizeof(int));
    return graph;
}

void addedge(Graph* graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
}

void topologicalsort(Graph* graph)
{
    int v = graph->V, indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (graph->adjMatrix[i][j] == 1)
                indegree[j]++;
    
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            queue[++rear] = i;
    
    printf("Topological ordering of vertices: ");
    
    while (front <= rear)
    {
        int vertex = queue[front++];
        printf("%d ", vertex);
        
        for (int i = 0; i < v; i++)
            if (graph->adjMatrix[vertex][i] == 1 && --indegree[i] == 0)
                queue[++rear] = i;
    }
    printf("\n");
}

int main()
{
    int v, e;
    printf("Enter the number of Vertices: ");
    scanf("%d", &v);
    Graph* graph = creategraph(v);
    
    printf("Enter the number of Edges: ");
    scanf("%d", &e);
    printf("Enter the edges (source, destination):\n");
    
    for (int i = 0, src, dest; i < e; i++)
    {
        scanf("%d%d", &src, &dest);
        addedge(graph, src, dest);
    }
    
    topologicalsort(graph);


    return 0;
}

