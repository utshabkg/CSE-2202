/// 8 puzzle. print path from root node to destination node

#include <bits/stdc++.h>
using namespace std;
#define N 3
// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

struct Node
{
	Node* parent;   // stores parent node of current node
	int mat[N][N];  // stores matrix
	int x, y;	    // stores blank tile coordinates
	int cost;       // stores the number of misplaced tiles
	int level;  	// stores the number of moves so far
};

int printMatrix(int mat[N][N])///Function to print N x N matrix
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

///Function to allocate a new node
Node* newNode(int mat[N][N], int x, int y, int newX,
			int newY, int level, Node* parent)
{
	Node* node = new Node;
	node->parent = parent;	// set pointer for path to root

	// copy data from parent node to current node
	memcpy(node->mat, mat, sizeof node->mat);

	// move tile by 1 position
	swap(node->mat[x][y], node->mat[newX][newY]);

	node->cost = INT_MAX;   // set number of misplaced tiles
	node->level = level;    // set number of moves so far

	node->x = newX;         // update new blank tile coordinates
	node->y = newY;

	return node;
}

///Function to calculate the the number of misplaced tiles
///ie. number of non-blank tiles not in their goal position
int calculateCost(int initial[N][N], int final[N][N])
{
	int count = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		if (initial[i][j] && initial[i][j] != final[i][j])
		count++;
	return count;
}

///Function to check if (x, y) is a valid matrix coordinate
int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

///print path from root node to destination node
void printPath(Node* root)
{
	if (root == NULL)
		return;
	printPath(root->parent);
	printMatrix(root->mat);

	printf("\n");
}

///Comparison object to be used to order the heap
struct comp
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
	}
};

///Function to solve N*N - 1 puzzle algorithm using
///Branch and Bound. x and y are blank tile coordinates
///in initial state
void solve(int initial[N][N], int x, int y,
		int final[N][N])
{
	// Create a priority queue to store live nodes of
	// search tree;
	priority_queue<Node*, std::vector<Node*>, comp> pq;

	// create a root node and calculate its cost
	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);

	pq.push(root);      // Add root to list of live nodes;

	// Finds a live node with least cost,
	// add its children to list of live nodes and
	// finally deletes it from the list.
	while (!pq.empty())
	{
		// Find a live node with least estimated cost
		Node* min = pq.top();

		// The found node is deleted from the list of
		// live nodes
		pq.pop();

		if (min->cost == 0)     // if min is an answer node
		{
			// print the path from root to destination;
			printPath(min);
			return;
		}

		// do for each child of min
		// max 4 children for a node
		for (int i = 0; i < 4; i++)
		{
			if (isSafe(min->x + row[i], min->y + col[i]))
			{
				// create a child node and calculate
				// its cost
				Node* child = newNode(min->mat, min->x,
							min->y, min->x + row[i],
							min->y + col[i],
							min->level + 1, min);
				child->cost = calculateCost(child->mat, final);

				// Add child to list of live nodes
				pq.push(child);
			}
		}
	}
}

int main()
{
	int initial[N][N] =
	{
		{1, 2, 3},
		{5, 6, 0},
		{7, 8, 4}
	};

	int final[N][N] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0}
	};

	int x = 1, y = 2;// Blank tile coordinates in initial configuration

	solve(initial, x, y, final);

	return 0;
}
