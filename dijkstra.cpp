#include "graph.h"

deque<int> Graph::dijkstra_classic(const int& start)
{
    auto dist = deque<int>(nodes, inf);
    auto visited = vector<bool>(nodes);

    dist[start] = 0;

	for (auto k = 0; k < nodes; ++k)
	{
		auto min_dist = inf;
        auto min_index = start;

		for (auto j = 0; j < nodes; ++j)
			if(!visited[j] && min_dist > dist[j])
			{
				min_dist = dist[j];
				min_index = j;
			}

		visited[min_index] = true;

        for (auto&& [next, cost]: neighbours[min_index])
            if (dist[next] > dist[min_index] + cost)
				dist[next] = dist[min_index] + cost;
    }

    dist.pop_front();
    return dist;
}

deque<int> Graph::dijkstra_heap(const int& start)
{
    auto dist = deque<int>(nodes, inf);

    auto comp = [&](const int& x, const int& y)
    {
        return dist[x] > dist[y];
    };

    priority_queue<int, vector<int>,
                    decltype(comp)> heap(comp);
    dist[start] = 0;
    heap.push(start);

    while (!heap.empty())
    {
        auto node = heap.top(); heap.pop();

        for (auto&& [next, cost]: neighbours[node])
            if (dist[next] > dist[node] + cost)
            {
                dist[next] = dist[node] + cost;
                heap.push(next);
            }
    }

    dist.pop_front();
    return dist;
}
