#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

list<int> eulerCircuit;

void addEdge(list<int> *adjList, int v1, int v2) {
	
	adjList[v1].push_back(v2);
	adjList[v2].push_back(v1);

}

void removeEdge(list<int> *adjList, int v1, int v2) {
	
	adjList[v1].remove(v2);
	adjList[v2].remove(v1);

}

list<int>* createGraph(int numVertices, int numEdges) {
	
	list<int> *adjList = new list<int>[numVertices];
	
	printf("Enter edges (Zero-based indexing): \n");
	int e = numEdges, v1, v2;

	while(e--) {
		scanf("%d%d", &v1, &v2);
		addEdge(adjList, v1, v2);
	}

	return adjList;
}

void printGraph(list<int> *adjList, int numVertices) {

	printf("\nGiven graph as Adjacency List: \n");
	for (int i = 0; i < numVertices; ++i) {
		printf("%d => ", i);
		
		list<int>::iterator j;
		for (j = adjList[i].begin(); j != adjList[i].end(); ++j) {
			printf("%d  ", *j);
		}
		printf("\n");
	}
	printf("\n");
}

bool isEuler(list<int> *adjList, int numVertices) {
	
	for (int i = 0; i < numVertices; ++i) {
		if (adjList[i].size() & 1) {
			return false;
		}
	}

	return true;
}

int DFSCount(list<int> *adjList, int u, bool *visited) {
	
	visited[u] = true;
	int count = 1;

	for (list<int>::iterator i = adjList[u].begin(); i != adjList[u].end(); ++i) {
		
		if (*i != -1 && !visited[*i])
			count += DFSCount(adjList, *i, visited);;
		
	}

	return count;
}

bool isBridge(list<int> *adjList, int numVertices, int u, int v) {

	// Logic:
	// Count no. of vertices reachable from u
	// Remove edge u-v
	// Again count the no. of vetices reachable from u (DFS or BFS)
	// If this number reduces, then edge u-v is a bridge
	// Else, u-v is not a bridge
	//

	bool visited[numVertices];
	memset(visited, false, numVertices);

	// Count of num of vertices reachable from u
	int countBeforeEdgeRemoval = DFSCount(adjList, u, visited);
	// printf("Count before edge removal: %d\n", countBeforeEdgeRemoval);

	// printf("Removing edge %d - %d\n", u, v);
	removeEdge(adjList, u, v);
	memset(visited, false, numVertices);

	// Count of num of vertices reachable from u after removing u-v edge
	int countAfterEdgeRemoval = DFSCount(adjList, u, visited);
	// printf("Count after edge removal: %d\n", countAfterEdgeRemoval);

	// Add the removed edge back
	addEdge(adjList, u, v);

	return !(countBeforeEdgeRemoval == countAfterEdgeRemoval);
}	

bool isValidNextEdge(list<int> *adjList, int numVertices, int u, int v) {
	
	// Steps:
	// If only 1 adjacent edge, return true.
	// Else, ensure that given edge is not a bridge
	// 

	// printGraph(adjList, numVertices);
	// printf("Size of adjList[%d] = %d\n", u, (int)adjList[u].size());
	if (adjList[u].size() == 1) {
		return true;
	}

	return !isBridge(adjList, numVertices, u, v);
}

void constructEulerCircuit(list<int>* adjList, int numVertices, int u) {	
	
	// Fleury's Algorithm:

	// Start from any vertex (say, 0th)
	// Choose next "valid" edge
	// Remove this edge from the graph
	// Stop when no more edges left in graph

	//

	if (adjList[u].empty()) {
		return;
	}

	while (!adjList[u].empty()) {

		int v = adjList[u].front();
		
		if (isValidNextEdge(adjList, numVertices, u, v)) {
			
			printf("Choose edge: %d - %d\n", u, v);
			eulerCircuit.push_back(v);
			removeEdge(adjList, u, v);
			constructEulerCircuit(adjList, numVertices, v);

		} else {
			printf("Reject edge: %d - %d (Since it's a bridge)\n", u, v);
		}
	}
}

void printEulerCircuit() {
	
	printf("\nEuler Circuit: ");
	while(!eulerCircuit.empty()) {
		printf("%d", eulerCircuit.front());
		eulerCircuit.pop_front();
		if (eulerCircuit.size() >= 1) {
			printf(" - ");
		}
	} 
	printf("\n\n");

}

int main() {

	// Steps:
	
	// Take graph as user input.
	// Check if graph is connected. If no, exit. 
	// If yes, then check if graph is Euler.
	// If no, then Euler Circuit doesn't exist. Exit.
	// If yes, then:
	// Use DFS to print Euler circuit

	//

	int numVertices, numEdges;
	printf("Enter number of vertices & edges: ");
	scanf("%d%d", &numVertices, &numEdges);

	// Graph represented as adjacency list
	list<int> *adjList = createGraph(numVertices, numEdges); 

	printGraph(adjList, numVertices); 

	if (!isEuler(adjList, numVertices)) {
		printf("Given graph is not Eulerian.\n");
	} else {
		eulerCircuit.push_back(0);
		printf("Fleury's Algorithm steps:\n\n");
		constructEulerCircuit(adjList, numVertices, 0);
	}

	printEulerCircuit();

	return 0;
}