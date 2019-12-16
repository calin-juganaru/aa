#ifndef _ALGO_H_
#define _ALGO_H_

#include <fstream>
#include <ctime>

#include "graph.h"

using namespace std;

auto read_input = [&](string file)
{
    ifstream fin(file);
    
    int N, M, source, x, y, z;
    fin >> N >> M >> source;
    auto graph = Graph(N);

    while (M--)
    {
        fin >> x >> y >> z;
        graph.add(x, y, z);
    }

    fin.close();
    return pair(graph, source);
};

auto print_dist = [&](auto&& dist, auto&& stream)
{
    for (auto&& it: dist)
        if (it == Graph::inf)
             stream << "inf ";
        else stream << it << " ";
    stream << "\n";
};

auto print_time = [&](const string& name, const double& begin,
                      const double& end, auto&& stream)
{
    stream << name << " " << (end - begin) / CLOCKS_PER_SEC << "\n";
};

vector<int> shortest_path(const vector<Graph::edge_t>& adj_list, const int& source);

#endif
