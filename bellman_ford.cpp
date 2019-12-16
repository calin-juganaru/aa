#include "graph.h"

Graph::return_t Graph::bellman_ford_classic(const int& start)
{
    auto dist = deque<int>(nodes, inf);
    auto visited = vector<int>(nodes, 0);

    dist[start] = 0;

    for (auto i = 0; i < nodes; ++i)
        for (auto node = 1; node < nodes; ++node)
            if (dist[node] != inf)
                for (auto&& [next, cost]: neighbours[node])
                    if (dist[next] > dist[node] + cost)
                        dist[next] = dist[node] + cost;

    for (auto node = 1; node < nodes; ++node)
        if (dist[node] != inf)
            for (auto&& [next, cost]: neighbours[node])
                if (dist[next] > dist[node] + cost)
                    return pair(false, deque<int>());

    dist.pop_front();
    return pair(true, dist);
}

Graph::return_t Graph::bellman_ford_queue(const int& start)
{
    auto dist = deque<int>(nodes, inf);
    auto visited = vector<int>(nodes, 0);
    auto q = queue<int>();

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        visited[node]++;

        if (visited[node] == nodes)
            return pair(false, deque<int>());

        for (auto&& [next, cost]: neighbours[node])
            if (dist[next] > dist[node] + cost)
            {
                dist[next] = dist[node] + cost;
                q.push(next);
            }
    }

    dist.pop_front();
    return pair(true, dist);
}
