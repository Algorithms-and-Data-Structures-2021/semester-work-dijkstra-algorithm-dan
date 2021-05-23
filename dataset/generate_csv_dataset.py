import os
import random
import numpy as np


def main():
    folder = os.path.join('data', 'dijkstra-algorithm')
    files = ['100.csv', '200.csv', '400.csv', '600.csv', '800.csv', '1000.csv', '1200.csv', '1400.csv', '1600.csv',
             '1800.csv']
    for i in range(10):
        for file in files:
            filename = os.path.join(folder, str(i), file)
            matrix_size = int(file.split('.')[0])
            os.makedirs(os.path.dirname(filename), exist_ok=True)
            with open(filename, 'w') as csv_file:
                matrix = np.zeros((matrix_size, matrix_size), dtype='int8')
                for line in matrix:
                    for j in range(matrix_size // 6):
                        line[random.randint(0, matrix_size - 1)] = random.randint(1, 10)
                str_matrix = []
                for line in matrix:
                    line = ','.join(str(num) for num in line) + '\n'
                    str_matrix.append(line)
                str_matrix = ''.join(str_matrix)
                csv_file.write(str_matrix)


if __name__ == '__main__':
    main()
