CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -O3

build: algo.o

main: main.o algo.o bellman_ford.o
	$(CC) $^ $(CFLAGS) -o main

main.o: main.cpp
	$(CC) $^ -c $(CFLAGS)

algo.o: algo.cpp
	$(CC) $^ -c $(CFLAGS)

test_algo_time: test_algo_time.o dijkstra.o bellman_ford.o bellman_ford_topo.o
	$(CC) $^ $(CFLAGS) -o test_algo_time

test_algo_time.o: test_algo_time.cpp
	$(CC) $^ -c $(CFLAGS)

test_algo_res: test_algo_res.o dijkstra.o bellman_ford.o bellman_ford_topo.o
	$(CC) $^ $(CFLAGS) -o test_algo_res

test_algo_res.o: test_algo_res.cpp
	$(CC) $^ -c $(CFLAGS)

dijkstra.o: dijkstra.cpp
	$(CC) $^ -c $(CFLAGS)

bellman_ford.o: bellman_ford.cpp
	$(CC) $^ -c $(CFLAGS)

test_gen: test_gen.o bellman_ford_topo.o
	$(CC) $^ $(CFLAGS) -o test_gen

test_gen.o: test_gen.cpp
	$(CC) $^ -c $(CFLAGS)

bellman_ford_topo.o: bellman_ford_topo.cpp
	$(CC) $^ -c $(CFLAGS)

comp_files: comp_files.cpp
	$(CC) $^ $(CFLAGS) -o comp_files

.PHONY: clean
clean:
	rm -rf *.o
