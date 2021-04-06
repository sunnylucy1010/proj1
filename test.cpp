#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
    using namespace std;

    ifstream file("Proj1_Ex1_SortingAlgos_DataFile.txt");
    if (file.is_open())
    {
        string myArray[10];

        for (int i = 0; i < 10; ++i)
        {
            file >> myArray[i];
            stringstream geek(myArray[i]);
            int x = 0;
            geek >> x;
            cout << x << " ";
        }
    }
}