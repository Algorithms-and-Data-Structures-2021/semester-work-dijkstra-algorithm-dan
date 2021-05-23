#pragma once

// Заголовочный файл с объявлением структуры данных

#include <vector>
namespace itis {

  // Структура вершины графа

  struct Vertex {
    Vertex* previous_vertex;
    int number;
    int value;
  };

  struct MinBinaryHeap {
   public:
    // Метод создания бинарной кучи. Ключом является значение вершины.
    // Принимает на вход массив вершин. T = O(n), M = O(n)
    void create_heap(std::vector<Vertex>& vertexes);
    // Получение минимального элемента из кучи. T = O(log n)
    Vertex& get_min_vertex();

    // Изменение значения у какой-то вершины. Принимает номер вершины, новое значение и вершину,
    // из которой мы проставляем метки на данном этапе алгоритма,
    // поскольку данный метод используется именно в процессе выполнения алгоритма
    void change_vertex(int vertex_number, int new_value, Vertex* previous_vertex);

    // Проверка, является ли куча пустой или нет
    bool isEmpty();

    // Узнать индекс вершины в массиве, по которому была построена куча. Принимает номер вершины
    int get_position_in_heap(int vertex_number);

    // По номеру вершины возвращает саму вершину из массива, который хранит вершины для кучи
    Vertex& get_vertex(int vertex_number);

   private:

    // Служебные методы для получения индексов детей, родителя
    static int get_left_child(int index);
    static int get_right_child(int index);
    static int get_parent(int index);

    // Метод, который начиная с заданного индекса перестраивает два поддерева, исходящих из данной вершины, для того,
    // чтобы соблюдались свойства кучи
    void heapify(int index);

    // Метод меняет значения вершин и их позиции в массиве с позициями. Принимает индексы вершин
    void swap(int i, int j);

    // Массив, который хранит в себе под индексом i индекс в массиве вершин(vertexes),
    // под которым там хранится  вершина i
    std::vector<int> position_of_vertexes;

    // Массив вершин, которые используются в бинарной куче
    std::vector<Vertex> vertexes;
  };

}  // namespace itis