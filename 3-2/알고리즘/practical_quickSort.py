import matplotlib.pyplot as plt

size = []
time = []
size2 = []
time2 = []

flag = False
with open("time_graph.txt", "r") as fp:
    for line in fp:
        if (line.strip() == ""):
            flag = True
            continue
        
        if (flag == True):
            graph = line.split()
            size2.append(graph[0])
            time2.append(graph[1])
        else:
            graph = line.split()
            size.append(graph[0])
            time.append(graph[1])
        
        
plt.plot(size, time)
plt.plot(size2, time2)
plt.show()