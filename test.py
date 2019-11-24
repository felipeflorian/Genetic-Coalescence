import networkx as nx
import matplotlib.pyplot as plt

average = open("average.txt")
iterations = open("iterations.txt")

l = iterations.readlines()
i = l[0].split()
it = int(i[0])


lines = average.readlines()

final_lines = []
for i in lines:
    x = i.split()
    final_lines.append(x)


sz = final_lines[0]
sz2 = int(sz[0])
count = 0
for i in range(1, len(final_lines)):
    x = final_lines[i]
    y = x[0]
    count += int(y)




r = count/sz2
s = r/10
u = 1 - 1/it
e = 2*u
print("Simulación: ", s)
print("Formula: ", e)



l = s
k = str(s)
e = ""
for f in range(3):
    e += k[f]
k = float(e)
G = nx.Graph()
for i in range(10):
    G.add_node(i, pos = (s,s))
    s -= 4*k

x = G.nodes()
for i in range(len(x)):
    if i + 1 < len(x):
        G.add_edge(i,i+1,weight = k)



pos = nx.get_node_attributes(G, 'pos')


n = []

for i in pos.values():
    n.append(i)
print(n)
for i in range(10,19):
    x = n[i-9]
    c = -x[0]
    d = x[1]
    G.add_node(i,pos = (c,d))

r = G.nodes()

G.add_edge(0,10,weight = k)

for i in range(10,18):
    if i + 1 <= len(r):
        G.add_edge(i,i+1,weight = k)

pos3 = nx.get_node_attributes(G, 'pos')


new = []
for i in range(19,27):
    new.append(i)

count = 1
for i in range(len(new)):
    x = n[len(n)-count]
    count += 1
    d = x[0]
    t = x[1]
    G.add_node(new[i], pos =(d/2,t))




new2 = []
for i in range(28,36):
    new2.append(i)

n2 = []
for i in pos3.values():
    n2.append(i)
count2 = 1
print(n2)

for i in range(len(new2)):
    x = n2[len(n2)-(i+1)]
    print(x)
    count += 1
    d = x[0]
    t = x[1]
    G.add_node(new2[i],pos=(d/2,t))

G.add_edge(1,26,weight=k)
G.add_edge(2,25,weight=k)
G.add_edge(3,24,weight=k)
G.add_edge(4,23,weight=k)
G.add_edge(5,22,weight=k)
G.add_edge(6,21,weight=k)
G.add_edge(7,20,weight=k)
G.add_edge(8,19,weight=k)
G.add_edge(28,17,weight=k)
G.add_edge(29,16,weight=k)
G.add_edge(30,15,weight=k)
G.add_edge(31,14,weight=k)
G.add_edge(32,13,weight=k)
G.add_edge(33,12,weight=k)
G.add_edge(34,11,weight=k)
G.add_edge(35,10,weight=k)

weight2 = nx.get_edge_attributes(G,'weight')
pos2 = nx.get_node_attributes(G, 'pos')
nx.draw_networkx(G,pos2)
nx.draw_networkx_edge_labels(G,pos2,edge_labels = weight2)
plt.show()
###
