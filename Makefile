all:
	g++ -Wall -g Graph.cpp GraphTests.cpp -o graph-GraphTests
	g++ -Wall -g Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests