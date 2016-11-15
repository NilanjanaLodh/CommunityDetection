# Community Detection in undirected social networks

This project aims to merge the results of different community detection algorithms for undirected ,weighted graphs and come up with a (hopefully) better results.

## Dependencies ##
Python 2.7 must be installed and the following python libraries must be installed for the project to run.
* [NetworkX](https://networkx.github.io/)
* [python-louvain](https://pypi.python.org/pypi/python-louvain/0.3/)
* [MatplotLib](http://matplotlib.org/)
* [Pickle](https://docs.python.org/2/library/pickle.html)

## Dataset ##

The algorithm has been tested on the [DBLP dataset](https://snap.stanford.edu/data/com-DBLP.html) from SNAP.
The graph was partitioned using the following algorithms and the corresponding files were generated.

Algorithm           | file generated
------------------- | -------------
Infomap             | input1.txt
Louvain             | input2.txt
Markov Clustering   | input3.txt
OSLOM               | input4.txt
WalkTrap            | input5.txt

All these files (including the original DBLP dataset) are available in *dataset/* directory

## Running and Testing
Download/clone [this repository](https://github.com/NilanjanaLodh/CommunityDetection) and then, cd to the project directory and type :
```bash
$ make run
```
This prints the fscore of our merged community detection algorithm.

Apart from that , it also generates the following output files
* weighted\_graph.out : The 'merged' weighted graph formed from input1.txt .. input5.txt
* pruned\_weighted\_graph.out : The above graph has been pruned by removing edges with 0 weights
* node\_community.out : gives the nodenumber and the corresponding community to which it belongs on each line
* community\_node\_list.out : Gives the community wise list of nodes. A new line starts a new community
* fscorecomp.out : the fscore of our algorithm
* Graph.gml : The pruned weighted graph stored in gml ( graph markup language ) format. The primary purpose of generating this file is to be able to visualize using the software Gephi. 

These output and binary files may be removed from the project directory by using :
```bash
$ make clean
```
Since running the entire project and generating the output files may take some time ( ~ 30 minutes) , the output files generated on a single run have been included in the *Outputfiles/* directory.

## Visualizing the graph structure

The Graph.gml file can be directly opened using **Gephi** and visualized.
