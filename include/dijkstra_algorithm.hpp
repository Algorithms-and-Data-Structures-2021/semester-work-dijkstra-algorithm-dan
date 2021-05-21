#pragma once
#include <string>
#include "min_binary_heap.hpp"
class DijkstraAlgorithm {
 public:
  void go_dijkstra(int start_vertex_number);
  void adjacency_matrix_to_adjacency_list(const std::vector<std::vector<int>>& adjacency_matrix);

 private:
  itis::MinBinaryHeap minBinaryHeap;
  std::vector<std::vector<std::pair<int, int>>> adjacency_list;
};