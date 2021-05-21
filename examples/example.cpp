#include "dijkstra_algorithm.hpp"
using namespace std;
using namespace itis;
int main() {
  vector<vector<int>> adjacency_matrix = {{0, 1, 0, 0, 0, 0, 0, 0},
                                          {0, 0, 5, 0, 0, 5, 7, 0},
                                          {0, 0, 0, 1, 0, 0, 0, 2},
                                          {0, 0, 0, 0, 1, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 3},
                                          {2, 0, 1, 0, 2, 0, 0, 0},
                                          {0, 0, 0, 7, 0, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 3, 0, 0}};
  DijkstraAlgorithm dijkstraAlgorithm;
  dijkstraAlgorithm.adjacency_matrix_to_adjacency_list(adjacency_matrix);
  dijkstraAlgorithm.go_dijkstra(0);
  dijkstraAlgorithm.print_shortest_paths();
  return 0;
}