
import matplotlib.pyplot as plt
import sys
import csv

NUM_TICKS = 5
DATA_FILE = "data/read_data.csv"
OUTPUT_PATH = "images/"

# def generateGraph(yValues, graphNumber, savePath):
def generateGraph(savePath, yValues, namePt1, namePt2, namePt3, graphNumber):
    # Create subplot
    ax = plt.subplot(111)
    # Generate the graph
    ax.bar(range(0 ,len(yValues)), yValues)
    # Set the window title
    plt.gcf().canvas.manager.set_window_title(f'{namePt1}, Using: {namePt2}, Size: {namePt3}')
    # Set the graph title
    plt.title(f'{namePt1}, Using: {namePt2}, Size: {namePt3}')
    # Label the x axis
    plt.xlabel('Number of Iterations')
    # Label the y axis
    plt.ylabel('Cumulative Reads')
    # Make x-ticks consistent
    plt.xticks(range(0, len(yValues) + 1, len(yValues) // 5))
    # Make y-ticks consistent
    plt.yticks(range(0, yValues[-1] + 1, yValues[-1] // 5))
    # Save plot
    plt.savefig(f'{savePath}graph{graphNumber}.png')
    # Close plot
    plt.close()

listType = ("Separate Chaining", "Open Addressing")
keyType = ("Key 1", "Key 2")
listSize = (2500, 3500, 4500, 5500, 6500)

graphs = []
for i in range(0, 20):
    graphs.append([])


with open(DATA_FILE, "r") as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        for i in range(0, 20):
            graphs[i].append(int(row[i+1]))

for i in range(0, 20):
    # generateGraph(graphs[i], i + 1, outputPath)

    typeIndex = 0
    keyIndex = 0
    sizeIndex = 0

    typeIndex = i // 10
    keyIndex = (i % 10) // 5
    sizeIndex = i % 5

    generateGraph(OUTPUT_PATH, graphs[i], listType[typeIndex], keyType[keyIndex], listSize[sizeIndex], i + 1)
