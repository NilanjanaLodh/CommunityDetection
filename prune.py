"""This module prunes the graph to remove the edges with weights zeo"""
# pylint: disable=W0321
from sys import argv
script , infilename , outfilename = argv

f = open(infilename, "r")
out_f = open(outfilename, "w")

## The variable "lines" is a list containing all lines
lines = f.readlines()

for line in lines:
	split_line = line.strip().split(",")
	#print split_line
	if split_line[2]!='0':
		#print split_line
		out_f.write(line)
		
f.close()
out_f.close()
