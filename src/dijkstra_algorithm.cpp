
#include <iostream>
#include "dijkstra_algorithm.hpp"
using namespace itis;
void DijkstraAlgorithm::go_dijkstra(const int start_vertex_number) {
  const int inf = std::numeric_limits<int>::max();
  Vertex start_vertex{nullptr, start_vertex_number, 0};
  std::vector<Vertex> vertexes;
  vertexes.push_back(start_vertex);
  for (int i = 0; i < adjacency_list.size(); i++) {
    if (i != start_vertex_number) {
      Vertex vertex{nullptr, i, inf};
      vertexes.push_back(vertex);
    }
  }
  minBinaryHeap.create_heap(vertexes);
  vertexes.clear();
  Vertex* previous_vertex = &minBinaryHeap.get_min_vertex();
  vertexes.push_back(*previous_vertex);

  while (!minBinaryHeap.isEmpty() && previous_vertex->value != inf) {
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
  }
  for (auto vertex : vertexes) {
    std::cout << "For vertex number " << vertex.number << " shortest path is " << vertex.value << std::endl;
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
