#include "algo.h"

vector<int> shortest_path(const vector<Graph::edge_t>& adj_list, const int& source)
{
    auto graph = Graph(adj_list.size() - 1);
    for (auto i = 1u; i < adj_list.size(); ++i)
        for (auto&& [j, cost]: adj_list[i])
            graph.add(i, j, cost);

    auto dist = graph.bellman_ford_queue(source).second;
    return vector(begin(dist), end(dist));
}
