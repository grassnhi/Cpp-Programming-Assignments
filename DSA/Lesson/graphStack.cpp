#include <iostream>
#include <stack>
#include <vector>

class Graph {
 public:
  Graph(int num_vertices) : num_vertices_(num_vertices) {
    adjacency_list_.resize(num_vertices);
  }

  void AddEdge(int u, int v) {
    adjacency_list_[u].push_back(v);
  }

  void DFS(int start) {
    std::vector<bool> visited(num_vertices_, false);
    std::stack<int> stack;

    stack.push(start);
    while (!stack.empty()) {
      int current = stack.top();
      stack.pop();
      if (!visited[current]) {
        std::cout << current << " ";
        visited[current] = true;
        for (int i = adjacency_list_[current].size() - 1; i >= 0; i--) {
          int next = adjacency_list_[current][i];
          if (!visited[next]) {
            stack.push(next);
          }
        }
      }
    }
  }

 private:
  int num_vertices_;
  std::vector<std::vector<int>> adjacency_list_;
};

int main() {
  Graph graph(5);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);

  std::cout << "DFS starting from vertex 0: ";
  graph.DFS(0);
  std::cout << std::endl;

  return 0;
}
