#include "graph.h"

bool Graph::has_cycle(const int& node, vector<COLOR>& visited)
{
    visited[node] = GRAY;
    auto ret = false;
    for (auto&& [next, cost]: neighbours[node])
        if (visited[next] == WHITE)
            ret |= this->has_cycle(next, visited);
        else if (visited[next] == GRAY)
            return true;
    
    visited[node] = BLACK;
    return ret;
}

bool Graph::is_dag()
{   
    auto visited = vector<COLOR>(nodes, WHITE);
    for (auto node = 0; node < nodes; ++node)
        if (visited[node] == WHITE)
            if (this->has_cycle(node, visited))
                return false;
    return true;
}

void Graph::dfs(const int& node, vector<bool>& visited, deque<int>& topo)
{
    visited[node] = true;
    for (auto&& [next, cost]: neighbours[node])
        if (!visited[next])
            this->dfs(next, visited, topo);
    topo.emplace_front(node);
}

deque<int> Graph::topological_sort()
{
    auto visited = vector<bool>(nodes);
    auto topo = deque<int>();

    for (auto node = 1; node < nodes; ++node)
        if (!visited[node])
            this->dfs(node, visited, topo);

    return topo;
}

Graph::return_t Graph::bellman_ford_topo(const int& start)
{
    if (!this->is_dag())
        return pair(false, deque<int>());
    
    auto dist = deque<int>(nodes, inf);
    auto topo = topological_sort();

    dist[start] = 0;
    
    for (auto&& node: topo)
        if (dist[node] != inf)
            for (auto&& [next, cost]: neighbours[node])
                if (dist[next] > dist[node] + cost)
                    dist[next] = dist[node] + cost;

    dist.pop_front();
    return pair(true, dist);
}
