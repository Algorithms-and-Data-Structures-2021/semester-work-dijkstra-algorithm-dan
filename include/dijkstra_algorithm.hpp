#pragma once
#include <string>
#include "min_binary_heap.hpp"
class DijkstraAlgorithm {
 public:

  // Основной метод - выполнение работы алгоритма от заданной вершины
  void go_dijkstra(int start_vertex_number);

  // Конвертация матрицы смежности в лист смежности, для последующей работы с ним
  void adjacency_matrix_to_adjacency_list(const std::vector<std::vector<int>>& adjacency_matrix);

  // Получить значения кратчайших путей для всех вершин. Под индексом i хранится значение для i-ой вершины
  std::vector<int> get_shortest_paths_values();

  // Получить сами пути в строковом представлении. Под индексом i хранится путь для i-ой вершины
  std::vector<std::string> get_shortest_paths();

  // Вывести результат работы алгоритма в красивом виде
  void print_shortest_paths();
 private:
  itis::MinBinaryHeap minBinaryHeap;
  std::vector<std::vector<std::pair<int, int>>> adjacency_list;
  std::vector<int> shortest_paths;
  std::vector<itis::Vertex> vertexes;
};