# CommunityDetection

This project aims to merge the results of different community detection algorithms for undirected ,weighted graphs.

## Dependencies ##
Python 2.7 must be installed and the following python libraries must be installed for the project to run.
*[NetworkX](https://networkx.github.io/)
*[python-louvain](https://pypi.python.org/pypi/python-louvain/0.3/)
*[MatplotLib](http://matplotlib.org/)
*[Pickle](https://docs.python.org/2/library/pickle.html)

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
cd to  the project directory and type :
```bash
username:~/custom_path_here/CommunityDetection$ make run
```
This prints the fscore of our merged community detection algorithm.


