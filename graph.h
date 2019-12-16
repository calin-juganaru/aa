#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <deque>
#include <queue>

using namespace std;

enum class COLOR
{
    WHITE, GRAY, BLACK
};

struct Graph
{
    static constexpr auto inf = 0x3F3F3F3F;
    using edge_t = vector<pair<int, int>>;
    using return_t = pair<bool, deque<int>>;

    vector<edge_t> neighbours;
    int nodes;

    Graph(const int& N):
        neighbours(vector<edge_t>(N + 1, edge_t())),
        nodes(N + 1) {}

    void add(const int& x, const int& y, const int& cost)
    {
        neighbours[x].push_back(pair(y, cost));
    }

    bool is_dag();
    deque<int> dijkstra_classic(const int&);
    deque<int> dijkstra_heap(const int&);
    return_t bellman_ford_classic(const int&);
    return_t bellman_ford_queue(const int&);
    return_t bellman_ford_topo(const int&);

    auto remove_last(const int& node)
    {
        neighbours[node].pop_back();
    }

private:
    bool has_cycle(const int&, vector<COLOR>&);
    void dfs(const int&, vector<bool>&, deque<int>&);
    deque<int> topological_sort();
};

#endif
