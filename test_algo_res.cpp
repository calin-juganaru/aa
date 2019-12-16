#include <iostream>
#include "algo.h"

using namespace std;

int main()
{
    int algoID; cin >> algoID;
    for (auto testID = 0; testID < 10; ++testID)
    {
        auto input_test_file  = "./in/test"s + to_string(testID) + ".in"s;
        auto res_output_file = "./other_out/test"s + to_string(testID) + ".out";
        auto [graph, source] = read_input(input_test_file);
        ofstream result_output(res_output_file);
        auto min_dist = deque<int>();

        switch (algoID)
        {
            case 1: min_dist = graph.dijkstra_classic(source); break;
            case 2: min_dist = graph.dijkstra_heap(source); break;
            case 3: min_dist = graph.bellman_ford_classic(source).second; break;
            case 4: min_dist = graph.bellman_ford_queue(source).second; break;
            case 5: min_dist = graph.bellman_ford_topo(source).second; break;
            default: break;
        }

        print_dist(min_dist, result_output);
        result_output.close();
    }
}
