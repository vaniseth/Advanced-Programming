#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
class Graph {
private:
	std::unordered_map<int, std::vector<int> >graph; 
	int V; 
public:
	Graph(int vertices)
		: V(vertices)
	{
}
	void addEdge(int u, int v) { graph[u].push_back(v); }
	void nonRecursiveTopologicalSort()
	{
		std::vector<bool> visited(V,false);
std::stack<int> stack; 
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				nonRecursiveTopologicalSortUtil(i, visited,
												stack);
			}
		}
		std::vector<int> sorted;
		while (!stack.empty()) {
			sorted.push_back(stack.top());
			stack.pop();
		}
		std::cout << "The following is a Topological Sort ""of the given graph:\n";
		for (auto& i : sorted) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

private:
	void nonRecursiveTopologicalSortUtil(
		int v, std::vector<bool>& visited,
		std::stack<int>& stack)
	{
		visited[v] = true;
		for (auto& next_neighbor : graph[v]) {
			if (!visited[next_neighbor]) {
				nonRecursiveTopologicalSortUtil(
					next_neighbor, visited, stack);
			}
		}
		stack.push(v);
	}
};

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	g.nonRecursiveTopologicalSort();
	return 0;
}
