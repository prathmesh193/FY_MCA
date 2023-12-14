#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//Stack Structure
typedef struct{
	int items[MAX];
	int top;
}Stack;

void initialize(Stack *s)
{
	s->top=-1;
}

int isEmpty(Stack *s)
{
	return s->top == -1;
}

void push(Stack *s, int value)
{
	if(s->top==MAX-1)
	{
		printf("Stack Overflow\n");
		exit(EXIT_FAILURE);
	}
	s->items[++(s->top)]=value;
}

int pop(Stack *s)
{
	if(isEmpty(s))
	{
		printf("Stack Underflow\n");
		exit(EXIT_FAILURE);
	}
	return s->items[(s->top)--];
}
//Stack structure end...

//DFS function
void DFS(int graph[MAX][MAX],int vertices,int startVertex)
{
	Stack stack;
	initialize(&stack);
	
	int visited[MAX]={0};
	push(&stack,startVertex);
	visited[startVertex] = 1;
	printf("DFS traversal starting from vertex %d : ",startVertex);
	
	while(!isEmpty(&stack))
	{
		int i;
		int currentVertex = pop(&stack);
		printf("%d ",currentVertex);
		
		for(i = 0; i < vertices; i++)
		{
			if(graph[currentVertex][i]==1 && !visited[i])
			{
				push(&stack,i);
				visited[i]=1;
			}
		}
	}
	printf("\n");
}

int main()
{
	int i,j;
	int vertices;
	printf("Enter the number of vertices :");
	scanf("%d",&vertices);
	
	int graph[MAX][MAX];
	
	printf("Enter the adjacency Matrix :\n");
	for(i=0;i<vertices;++i)
	{
		for(j=0;j<vertices;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	int startVertex;
	printf("Enter the starting vertex for DFS: ");
	scanf("%d",&startVertex);
	
	DFS(graph,vertices,startVertex);
	return 0;
}