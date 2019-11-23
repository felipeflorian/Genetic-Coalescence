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




# G = nx.Graph()
# #parent
# G.add_node(0, pos = (1000,1000))
#
# print(int(s))
# for i in range(1,int(r)):
#     G.add_node(i,pos=(10*(i+1),10*(i+1)))
#
#
#
# # pos2 = nx.get_node_attributes(P, 'pos')
# #         weight2 = nx.get_edge_attributes(P,'weight')
# #
# #         plt.figure()
# #
# #         nx.draw_networkx(P,pos2,nodelist=nodesP,node_color= color)
# #         nx.draw_networkx_edge_labels(P,pos2,edge_labels = weight2)
# #         plt.show()
#
# pos = nx.get_node_attributes(G, 'pos')
# nx.draw(G,pos, with_labels = True)
# plt.show()
