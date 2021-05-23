#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <filesystem>
// подключаем вашу структуру данных
#include "dijkstra_algorithm.hpp"

using namespace std;
using namespace itis;
namespace fs = std::filesystem;

int main(int argc, char **argv) {

  // абсолютный путь до файла с настройками
  ifstream setting_file(argv[0]);
  vector<string> settings;
  if (setting_file.is_open()) {
    string line;
    while (getline(setting_file, line)) {
      settings.push_back(line.substr(line.find('=') + 1, line.length()));
    }
  }
  // абсолютный путь до папки с тестовыми данными
  const string absolute_input_path = settings[0];
  // абсолютнуй путь до папки, в которую хотим сохранить результаты тестов
  const string absolute_output_path = settings[1];
  // парсим названия файлов из документа с настройками
  vector<string> file_names;
  settings[2].erase(0, settings[2].find("=") + 1);
  int start = 0;
  string delim = ",";
  auto end = settings[2].find(delim);
  while (end != std::string::npos) {
    file_names.push_back(settings[2].substr(start, end - start));
    start = end + delim.length();
    end = settings[2].find(delim, start);
  }
  file_names.push_back(settings[2].substr(start, end - start));

  int count_of_test_repeat = stoi(settings[3]);
  // проходимся по всем файлам поочередно
  for (int i = 0; i < file_names.size(); i++) {
    string file_name = file_names[i];
    int vertex_count = stoi(file_name.substr(0, file_name.find('.')));
    // будем писать результаты в файл, с тем же названием, что и тестовый набор данных
    fs::path dir(absolute_output_path);
    fs::path file(file_name);
    fs::path path = dir / file;
    ofstream output_file(path.c_str(), ios::app);
    // проходимся по всем директориям, дабы записать в один файл результаты по всем наборам
    for (int j = 0; j < 10; j++) {
      output_file << to_string(j + 1) + "-й набор данных" << endl;
      // получаем путь к тестовым данным так, чтобы его составление не зависело от используемой ОС
      fs::path input_dir(absolute_input_path);
      fs::path input_sub_dir(to_string(j));
      fs::path input_file_name(file_name);
      fs::path input_path = input_dir / input_sub_dir / input_file_name;
      ifstream input_file(input_path);

      if (input_file.is_open()) {
        // создаем нашу матрицу смежности
        vector<vector<int>> adjacency_matrix;
        adjacency_matrix.reserve(vertex_count);
        string adjacency_list_line;
        // считываем матрицу смежности из файла
        while (getline(input_file, adjacency_list_line)) {
          vector<int> line;
          line.reserve(vertex_count);
          int start = 0;
          auto end = adjacency_list_line.find(delim);
          while (end != std::string::npos) {
            line.push_back(stoi(adjacency_list_line.substr(start, end)));
            start = end + delim.length();
            end = adjacency_list_line.find(delim, start);
          }
          line.push_back(stoi(adjacency_list_line.substr(start, end)));
          adjacency_matrix.push_back(line);
        }

        // чтобы быть более точными, для одного набора проводим тест count_of_test_repeat раз
        for (int k = 0; k < count_of_test_repeat; k++) {
          DijkstraAlgorithm dijkstraAlgorithm;
          dijkstraAlgorithm.adjacency_matrix_to_adjacency_list(adjacency_matrix);
          const auto time_point_before = chrono::high_resolution_clock::now();
          dijkstraAlgorithm.go_dijkstra(0);
          const auto time_point_after = chrono::high_resolution_clock::now();
          const auto time_diff = time_point_after - time_point_before;
          const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
          if (output_file.is_open()) {
            output_file << time_elapsed_ns << endl;
          }
        }
      }
      input_file.close();
      output_file << endl << endl;
    }
  }
  return 0;
}
