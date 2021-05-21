#pragma once

// Заголовочный файл с объявлением структуры данных

#include <vector>
namespace itis {
  struct Vertex {
    Vertex* previous_vertex;
    int number;
    int value;
  };
  struct MinBinaryHeap {
   public:
    void create_heap(std::vector<Vertex>& vertexes);
    Vertex& get_min_vertex();
    void change_vertex(int vertex_number, int new_value, Vertex* previous_vertex);
    bool isEmpty();
    int get_position_in_heap(int vertex_number);
    Vertex& get_vertex(int vertex_number);

   private:
    static int get_left_child(int index);
    static int get_right_child(int index);
    static int get_parent(int index);
    void heapify(int index);
    void swap(int i, int j);
    std::vector<int> position_of_vertexes;
    std::vector<Vertex> vertexes;
  };

}  // namespace itis