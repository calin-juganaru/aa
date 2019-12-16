#include "algo.h"

using namespace std;

int main()
{   
    for (auto testID = 0; testID < 10; ++testID)
    {
        auto input_test_file  = "./in/test"s + to_string(testID) + ".in"s;
        auto time_output_file = "./time/test"s + to_string(testID) + ".time";
        auto [graph, source] = read_input(input_test_file);
        ofstream time_output(time_output_file);
        double begin, end;
        
        // ------------------------------------------------------------
        begin = clock();
        graph.dijkstra_classic(source);
        end = clock();
        print_time("    dijkstra classic:", begin, end, time_output);
        // ------------------------------------------------------------

        // ------------------------------------------------------------
        begin = clock();
        graph.dijkstra_heap(source);
        end = clock();
        print_time("    dijkstra    heap:", begin, end, time_output);
        // ------------------------------------------------------------

        // ------------------------------------------------------------
        begin = clock();
        graph.bellman_ford_classic(source);
        end = clock();
        print_time("bellman-ford classic:", begin, end, time_output);
        // ------------------------------------------------------------

        // ------------------------------------------------------------
        begin = clock();
        graph.bellman_ford_queue(source);
        end = clock();
        print_time("bellman-ford   queue:", begin, end, time_output); 
        // ------------------------------------------------------------

        // -----------------------------------------------------------------
        if (graph.is_dag())
        {
            begin = clock();
            graph.bellman_ford_topo(source);
            end = clock();
            print_time("bellman-ford    topo:", begin, end, time_output);
        }
        // -----------------------------------------------------------------

        time_output.close();
    }
}
