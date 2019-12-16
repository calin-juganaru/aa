#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main()
{   
    for (auto testID = 0; testID < 10; ++testID)
    {
        auto time = vector<long double>(5, 0.0);
        auto input_test_file  = "./time/test"s + to_string(testID) + ".time"s;
        ifstream input(input_test_file);    
    
        for (auto testNr = 0; testNr < 100; ++testNr)
        {        
            long double aux;

            for (auto&& it: time)
            {
                input >> aux;
                it += aux;
            }            
        }
        
        cout << input_test_file << '\n';
        for (auto&& it: time)
        {
            cout << (long double)it / 100000000.0
                 << " sec \n";
        }
        cout << '\n';
    
        input.close();
    }
}
