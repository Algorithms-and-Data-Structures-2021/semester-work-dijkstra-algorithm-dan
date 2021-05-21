#include "min_binary_heap.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры

  int MinBinaryHeap::get_left_child(int index) {
    return 2 * index + 1;
  }
  int MinBinaryHeap::get_right_child(int index) {
    return 2 * index + 2;
  }
  int MinBinaryHeap::get_parent(int index) {
    return (index - 1) / 2;
  }
  void MinBinaryHeap::heapify(int index) {
    while (true) {
      if (vertexes[index].value <= vertexes[get_left_child(index)].value
          && vertexes[index].value <= vertexes[get_right_child(index)].value) {
        break;
      }
      if (get_left_child(index) >= vertexes.size()) {
        break;
      }
      swap(index, get_left_child(index));
      if (get_right_child(index) < vertexes.size() && vertexes[get_right_child(index)].value < vertexes[index].value) {
        swap(index, get_right_child(index));
      }
      index = get_left_child(index);
    }
  }
  void MinBinaryHeap::create_heap(std::vector<Vertex>& vertexes) {
    this->vertexes = vertexes;
    for (int i = 0; i < vertexes.size(); i++) {
      position_of_vertexes.push_back(-1);
    }
    for (int i = 0; i < vertexes.size(); i++) {
      position_of_vertexes[vertexes[i].number] = i;
    }
    for (int i = (vertexes.size() / 2) - 1; i >= 0; i--) {
      heapify(i);
    }
  }
  void MinBinaryHeap::swap(int i, int j) {
    std::swap(position_of_vertexes[vertexes[i].number], position_of_vertexes[vertexes[j].number]);
    std::swap(vertexes[i], vertexes[j]);
  }
  Vertex& MinBinaryHeap::get_min_vertex() {
    swap(0, vertexes.size() - 1);
    Vertex& min_vertex = vertexes.back();
    vertexes.pop_back();
    position_of_vertexes[min_vertex.number] = -1;
    heapify(0);
    return min_vertex;
  }
  void MinBinaryHeap::change_vertex(int vertex_number, int new_value, Vertex* previous_vertex) {
    int index = get_position_in_heap(vertex_number);
    vertexes[index].value = new_value;
    vertexes[index].previous_vertex = previous_vertex;
    while (vertexes[index].value < vertexes[get_parent(index)].value && index != 0) {
      swap(index, get_parent(index));
      index = get_parent(index);
    }
  }
  int MinBinaryHeap::get_position_in_heap(int vertex_number) {
    return position_of_vertexes[vertex_number];
  }
  bool MinBinaryHeap::isEmpty() {
    return vertexes.size() == 0;
  }
  Vertex& MinBinaryHeap::get_vertex(int vertex_number) {
    return vertexes[get_position_in_heap(vertex_number)];
  }
}  // namespace itis