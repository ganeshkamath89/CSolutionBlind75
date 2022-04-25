#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct GraphNode
{
	int val;
	struct GraphNode** neighbours;//All the neighbours of a GraphNode
	int neighbourCount;
};

// A function which clones a Graph and returns the address to the cloned src node
struct GraphNode *cloneGraph(struct GraphNode *src)
{
	//A Map to keep track of all the nodes which have already been created
	map<struct GraphNode*, struct GraphNode*> m;
	queue<struct GraphNode*> q;

	// Enqueue src node
	q.push(src);

	// Make a clone Node
	struct GraphNode *node = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node->val = src->val;

	// Put the clone node into the Map
	m[src] = node;
	while (!q.empty())
	{
		//Get the front node from the queue and then visit all its neighbours
		struct GraphNode *u = q.front();
		q.pop();
		struct GraphNode** v = u->neighbours;
		m[u]->neighbourCount = u->neighbourCount;
		m[u]->neighbours = (struct GraphNode**)malloc(m[u]->neighbourCount * sizeof(struct GraphNode*));
		for (int i = 0; i < u->neighbourCount; i++)
		{
			// Check if this node has already been created
			if (m[v[i]] == NULL)
			{
				// If not then create a new Node and put into the HashMap
				node = (struct GraphNode*)malloc(sizeof(struct GraphNode));
				node->val = v[i]->val;
				m[v[i]] = node;
				q.push(v[i]);
			}

			// add these neighbours to the cloned graph node
			m[u]->neighbours[i] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
			m[u]->neighbours[i] = m[v[i]];
		}
	}

	// Return the address of cloned src Node
	return m[src];
}

// Build the desired graph
struct GraphNode *buildGraph()
{
	/*
		Note : All the edges are Undirected
		Given Graph:
		1--2
		| |
		4--3
	*/

	struct GraphNode *node1 = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	struct GraphNode *node2 = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	struct GraphNode *node3 = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	struct GraphNode *node4 = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node1->val = 1;
	node1->neighbourCount = 2;
	node1->neighbours = (struct GraphNode**)malloc(node1->neighbourCount * sizeof(struct GraphNode*));
	node1->neighbours[0] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node1->neighbours[0] = node2;
	node1->neighbours[1] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node1->neighbours[1] = node4;

	node2->val = 2;
	node2->neighbourCount = 2;
	node2->neighbours = (struct GraphNode**)malloc(node2->neighbourCount * sizeof(struct GraphNode*));
	node2->neighbours[0] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node2->neighbours[0] = node1;
	node2->neighbours[1] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node2->neighbours[1] = node3;

	node3->val = 3;
	node3->neighbourCount = 2;
	node3->neighbours = (struct GraphNode**)malloc(node3->neighbourCount * sizeof(struct GraphNode*));
	node3->neighbours[0] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node3->neighbours[0] = node2;
	node3->neighbours[1] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node3->neighbours[1] = node4;

	node4->val = 4;
	node4->neighbourCount = 2;
	node4->neighbours = (struct GraphNode**)malloc(node4->neighbourCount * sizeof(struct GraphNode*));
	node4->neighbours[0] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node4->neighbours[0] = node1;
	node4->neighbours[1] = (struct GraphNode*)malloc(sizeof(struct GraphNode));
	node4->neighbours[1] = node3;
	return node1;
}

// A simple bfs traversal of a graph to check for proper cloning of the graph
void bfs(struct GraphNode *src)
{
	map<struct GraphNode*, bool> visit;
	queue<struct GraphNode*> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty())
	{
		struct GraphNode *u = q.front();
		printf("Value of Node %d\n", u->val);
		printf("Address of Node %u\n", u);
		q.pop();
		struct GraphNode** v = u->neighbours;
		int n = u->neighbourCount;
		for (int i = 0; i < n; i++)
		{
			if (!visit[v[i]])
			{
				visit[v[i]] = true;
				q.push(v[i]);
			}
		}
	}
	printf("BFS Traversal before cloning\n");
}

int main()
{
	struct GraphNode *src = buildGraph();
	printf("BFS Traversal before cloning\n");
	bfs(src);
	struct GraphNode *newsrc = cloneGraph(src);
	printf("BFS Traversal after cloning\n");
	bfs(newsrc);
	return 0;
}