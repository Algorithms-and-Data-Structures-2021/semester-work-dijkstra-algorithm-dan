#include <set>
#include <iostream>
#include <algorithm>
#include <stack>
#include "dijkstra_algorithm.hpp"
using namespace itis;
void DijkstraAlgorithm::go_dijkstra(const int start_vertex_number) {
  const int inf = std::numeric_limits<int>::max();
  Vertex start_vertex{nullptr, start_vertex_number, 0};
  vertexes.push_back(start_vertex);
  for (int i = 0; i < adjacency_list.size(); i++) {
    if (i != start_vertex_number) {
      Vertex vertex{nullptr, i, inf};
      vertexes.push_back(vertex);
    }
    shortest_paths.push_back(0);
  }
  minBinaryHeap.create_heap(vertexes);
  Vertex* previous_vertex = &minBinaryHeap.get_min_vertex();
  vertexes.clear();
  vertexes.push_back(*previous_vertex);
  while (!minBinaryHeap.isEmpty()) {
    for (auto pair : adjacency_list[previous_vertex->number]) {
      if (minBinaryHeap.get_position_in_heap(pair.first) == -1) {
        continue;
      }
      Vertex& adjacent_vertex = minBinaryHeap.get_vertex(pair.first);
      if (pair.second + previous_vertex->value < adjacent_vertex.value) {
        minBinaryHeap.change_vertex(pair.first, pair.second + previous_vertex->value, previous_vertex);
      }
    }
    previous_vertex = &minBinaryHeap.get_min_vertex();
    vertexes.push_back(*previous_vertex);
    shortest_paths[previous_vertex->number] = previous_vertex->value;
  }
}

void DijkstraAlgorithm::adjacency_matrix_to_adjacency_list(const std::vector<std::vector<int>>& adjacency_matrix) {
  for (int i = 0; i < adjacency_matrix.size(); i++) {
    std::vector<std::pair<int, int>> vector;
    adjacency_list.push_back(vector);
    for (int j = 0; j < adjacency_matrix.size(); j++) {
      if (adjacency_matrix[i][j] != 0) {
        adjacency_list[i].push_back({j, adjacency_matrix[i][j]});
      }
    }
  }
}
std::vector<int> DijkstraAlgorithm::get_shortest_paths_values() {
  return shortest_paths;
}
std::vector<std::string> DijkstraAlgorithm::get_shortest_paths() {
  //  auto lambda = [](Vertex left, Vertex right){return left.number < right.number;};
  //  auto ordered_vertexes = std::set<Vertex, decltype(lambda)>(lambda);
  std::sort(vertexes.begin(), vertexes.end(), [](Vertex left, Vertex right) { return left.number < right.number; });
  std::vector<std::string> ans;
  for (auto vertex : vertexes) {
    std::stack<int> path;
    path.push(vertex.number);
    Vertex* previous_vertex = vertex.previous_vertex;
    while (previous_vertex != nullptr) {
      path.push(previous_vertex->number);
      previous_vertex = previous_vertex->previous_vertex;
    }
    int vertex_number = path.top();
    path.pop();
    std::string str_path = std::to_string(vertex_number);
    while (!path.empty()) {
      str_path.append(" -> ").append(std::to_string(path.top()));
      path.pop();
    }
    ans.push_back(str_path);
  }
  return ans;
}
void DijkstraAlgorithm::print_shortest_paths() {
  std::vector<std::string> paths = get_shortest_paths();
  int start_vertex = paths[0][0] - '0';
  std::cout << "Shortest paths from vertex " << start_vertex << " are:" << std::endl;
  for (int i = 0; i < shortest_paths.size(); i++) {
    std::cout << "To vertex " << i << " is " << shortest_paths[i] << ". The path is - " << paths[i] << std::endl;
  }
}
