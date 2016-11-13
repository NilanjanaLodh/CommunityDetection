
run : f_score.bin community_node_list.out dataset/ground-truth.txt
	./f_score.bin dataset/ground-truth.txt community_node_list.out fscorecomp.out

f_score.bin : f_score.cpp
	g++ f_score.cpp -std=c++11 -o f_score.bin 

community_node_list.out : node_community.out listcommunities.bin
	./listcommunities.bin < node_community.out >community_node_list.out

listcommunities.bin : listcommunities.cpp
	g++ listcommunities.cpp -o listcommunities.bin

node_community.out : pruned_weighted_graph.out detect_community.py
	python detect_community.py pruned_weighted_graph.out node_community.out

pruned_weighted_graph.out : prune.py weighted_graph.out
	python prune.py  weighted_graph.out  pruned_weighted_graph.out

weighted_graph.out : take_votes.bin
	./take_votes.bin

take_votes.bin : take_votes.cpp dataset/*.txt
	g++ take_votes.cpp -o take_votes.bin

clean:
	rm *.bin 
	rm *.out
	rm Graph_obj_pickle
