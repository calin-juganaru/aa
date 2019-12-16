#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    for (auto testID = 0; testID < 10; ++testID)
    {
        auto file_1 = "./out/test"s + to_string(testID) + ".out";
        auto file_2 = "./other_out/test"s + to_string(testID) + ".out";

        ifstream input1(file_1);
        ifstream input2(file_2);

        cout << "TEST " << testID << ": ";

        while (input1 >> file_1)
        {
            input2 >> file_2;
            if (file_1 != file_2)
            {
                cout << "WRONG!\n";
                break;
            }
        }

        cout << "OK\n";
    }
}