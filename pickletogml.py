import pickle
import networkx as nx

fileObject = open('Outputfiles/Graph_obj_pickle','r')
G =pickle.load(fileObject)
outfile = open('Graph.gml', 'w')
nx.write_gml(G, outfile)