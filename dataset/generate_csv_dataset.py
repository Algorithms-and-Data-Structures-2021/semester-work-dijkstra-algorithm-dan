import csv
import os
import random
import numpy as np


def main():
    folder = 'dijkstra-algorithm'
    files = ['100.csv', '200.csv', '300.csv', '400.csv', '500.csv', '600.csv', '700.csv', '900.csv', '1000.csv',
             '1100.csv']
    for i in range(10):
        for file in files:
            filename = os.path.join(folder, str(i), file)
            matrix_size = int(file.split('.')[0])
            os.makedirs(os.path.dirname(filename), exist_ok=True)
            with open(filename, 'w') as csv_file:
                writer = csv.writer(csv_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
                matrix = np.zeros((matrix_size, matrix_size), dtype='int8')
                for line in matrix:
                    for j in range(matrix_size // 6):
                        line[random.randint(0, matrix_size - 1)] = random.randint(1, 10)
                writer.writerows(matrix)


if __name__ == '__main__':
    main()
