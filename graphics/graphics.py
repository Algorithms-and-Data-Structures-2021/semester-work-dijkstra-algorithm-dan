import matplotlib.ticker
import matplotlib.pyplot as plt
import csv
import math

lengths = []
results = []
with open('data.csv', 'r') as data_file:
    reader = csv.reader(data_file, delimiter=',', quotechar='|')
    for row in reader:
        if row[0].find('string') != -1:
            continue
        lengths.append(int(row[0]))
        results.append(int(row[1]) / 1000000)
plt.style.use("fivethirtyeight")
fig, ax = plt.subplots(figsize=(11, 11))
y = [(math.log2(number)*(number + (number*number) // 6)) / 1000000 for number in lengths]
y1 = [num * 2 for num in y]
ax.set_title('Зависимость времени работы алгоритма\n от количества вершин')
ax.set_xlabel('Количество вершин')
ax.set_ylabel('Время в мс')
ax.xaxis.set_major_formatter(matplotlib.ticker.FormatStrFormatter('%d'))
ax.yaxis.set_major_formatter(matplotlib.ticker.FormatStrFormatter('%d'))
ax.plot(lengths, results, color='red', linestyle='-', marker='o', label='проведенные замеры')
ax.plot(lengths, y, color='green', linestyle='-', marker='o', label='O(nlogn + mlogn)')
ax.plot(lengths, y1, color='blue', linestyle='--', marker='>', label='O(nlogn + mlogn)*2')
locations, ticks = plt.xticks()
locations = lengths
plt.xticks(locations, locations)
ax.legend(loc='lower right')
fig.savefig('dijkstra-algorithm.png')
