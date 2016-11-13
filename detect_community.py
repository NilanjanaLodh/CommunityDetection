"""This module runs the lovain algortihm on pruned output"""
import pickle
import community
import networkx as nx
import matplotlib.pyplot as plt
from sys import argv


script , infilename , outfilename = argv

def read_graph(G):
	f = open(infilename, 'r')
	lines = f.readlines()

	for line in lines:
		u , v , w=[int(val) for val in line.strip().split(",")]
		G.add_edge(u , v, weight = w)
		#print u,v,w
	print G.number_of_nodes() , "nodes"
	print G.number_of_edges() , "edges"
	save_obj(G,'Graph_obj_pickle')
	f.close()

def save_obj(obj, filename):
   f = open(filename, 'wb')
   pickle.dump(obj, f)
   f.close()

def main():
	"""partitions the graph G into communities"""
	G = nx.Graph()
	read_graph(G)
	print 'Computing clusters ...'
	part = community.best_partition(G)
	print 'Writing to file ...'
	#node1 community_of_node1
	#node2 community_of_node2
	
	f = open(outfilename,'w')
	for node in part:
		line = str(node) + " " + str(part[node]) + "\n"
		f.write(line)
	f.close()

main()
