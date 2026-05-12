#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(string text)
{
    int sum = 0;

    for (int i = 0; i < text.length(); i++)
    {
        sum += (int)text[i];
    }

    return sum;
}

int main()
{
    ifstream inputFile("lab-37-data.txt");

    if (!inputFile)
    {
        cout << "Error: Could not open lab-37-data.txt" << endl;
        return 1;
    }

    string code;
    long long grand_total = 0;

    while (inputFile >> code)
    {
        grand_total += sum_ascii(code);
    }

    inputFile.close();

    cout << "Grand total: " << grand_total << endl;
    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
