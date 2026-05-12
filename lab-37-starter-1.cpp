#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>

using namespace std;

int gen_hash_index(string text)
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
    ifstream inputFile("lab-37-data-3.txt");

    if (!inputFile)
    {
        cout << "Error: Could not open lab-37-data.txt" << endl;
        return 1;
    }

    string code;
    long long grand_total = 0;

    map<int, list<string>> hash_table;

    while (inputFile >> code)
    {
        int hash_index = gen_hash_index(code);
        grand_total += hash_index;
        hash_table[hash_index].push_back(code);
    }

    inputFile.close();

    cout << "Grand total: " << grand_total << endl;

    cout << endl;
    cout << "First 100 hash table entries:" << endl;

    int count = 0;

    for (map<int, list<string>>::iterator it = hash_table.begin(); it != hash_table.end(); it++)
    {
        if (count >= 100)
        {
            break;
        }

        cout << "Hash index:" << it->first<< " -> ";

        for (list<string>::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
        {
            cout << *listIt<< " ";
        }

        cout << endl;
        count++;
    }
    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
