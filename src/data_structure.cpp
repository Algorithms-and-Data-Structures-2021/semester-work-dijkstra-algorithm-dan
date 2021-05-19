#include "data_structure.hpp"

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
    while (true){
      if (vertexes_[index].value <= vertexes_[get_left_child(index)].value
          && vertexes_[index].value <= vertexes_[get_right_child(index)].value){
        break;
      }
      if (get_left_child(index) >= vertexes_.size()){
        break;
      }
      swap(index, get_left_child(index));
      if (get_right_child(index) < vertexes_.size()
          && vertexes_[get_right_child(index)].value < vertexes_[index].value){
        swap(index, get_right_child(index));
      }
      index = get_left_child(index);
    }
  }
  void MinBinaryHeap::create_heap(std::vector<Vertex>& vertexes) {
    vertexes_ = vertexes;
    for (int i = 0; i < vertexes.size(); i++){
      position_of_vertexes.push_back(i);
    }
    for (int i = (vertexes.size() / 2) - 1; i >= 0; i--){
      heapify(i);
    }
  }
  void MinBinaryHeap::swap(int i, int j) {
    std::swap(position_of_vertexes[vertexes_[i].number], position_of_vertexes[vertexes_[j].number]);
    std::swap(vertexes_[i], vertexes_[j]);
  }
  Vertex& MinBinaryHeap::get_min_vertex() {
    swap(0, vertexes_.size() - 1);
    Vertex& min_vertex = vertexes_.back();
    vertexes_.pop_back();
    heapify(0);
    return min_vertex;
  }
  void MinBinaryHeap::change_value(int vertex_number, int new_value) {
    int index = get_position_in_heap(vertex_number);
    vertexes_[index].value = new_value;
    while (vertexes_[index].value < vertexes_[get_parent(index)].value
           && index != 0){
      swap(index, get_parent(index));
      index = get_parent(index);
    }
  }
  int MinBinaryHeap::get_position_in_heap(int vertex_number) {
    return position_of_vertexes[vertex_number];
  }

}  // namespace itis