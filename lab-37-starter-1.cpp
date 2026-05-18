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

void print_menu()
{
    cout << endl;
    cout << "========== Lab 38 Hash Table Menu ==========" << endl;
    cout << "1. Print first 100 entries" << endl;
    cout << "2. Search for a key" << endl;
    cout << "3. Add a key" << endl;
    cout << "4. Remove a key" << endl;
    cout << "5. Modify a key" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

void print_first_100_entries(map<int, list<string>> hash_table){
    cout << endl;
    cout << "First 100 hash table entries:" << endl;
    cout << "---------------------" << endl;

    int count = 0;

    for (map<int, list<string>>::iterator it = hash_table.begin(); it != hash_table.end(); it++)
    {
        if (count >= 100)
        {
            break;
        }

        cout << "Entry " << count + 1<< endl;
        cout << "Hash index: " << it->first << endl;
        cout << "Number of codes: " << it->second.size() << endl;
        cout << "Codes: ";

        for (list<string>::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
        {
            cout << *listIt;
        }

        cout << endl;
        cout << "------------------------" << endl;

        count++;
    }
}

bool search_key(map<int, list<string>> hash_table, string key)
{
    int hash_index = gen_hash_index(key);
    map<int, list<string>>::iterator it = hash_table.find(hash_index);

    for(list<string>::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
    {
        if (*listIt == key)
        {
            return true;
        }
    }

    return false;
}

void add_key(map<int, list<string>>& hash_table)
{
    string key;

    cout << "Enter the key: ";
    cin >> key;

    if (search_key(hash_table, key))
    {
        return;
    }

    int hash_index = gen_hash_index(key);
    hash_table[hash_index].push_back(key);

    cout << "Key add successfully" << endl;
    cout << "Hash index: " << hash_index << endl;
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
    cout << "loaded successfully." << endl;
    cout << "Grand total: " << grand_total << endl;



    int choice = 0;

while (choice != 6)
{
    print_menu();
    cin >> choice;

    if (choice == 1){
        print_first_100_entries(hash_table);
    }
    else if (choice == 2){
        string key;

            cout << "Enter the key to search for: ";
            cin >> key;

            if (search_key(hash_table, key))
            {
                cout << "Key found" << endl;
                cout << "Hash index: " << gen_hash_index(key) << endl;
            }
            else
            {
                cout << "Key not found" << endl;
            }
    }
    
    else if (choice == 3){
        add_key(hash_table);
    }
    else if (choice == 4){
        cout << "Remove selected" << endl;
    }
    else if (choice == 5){
        cout << "Modify selected" << endl;
    }
    else if (choice == 6){
        cout << "Exiting program" <<endl;
    }
    else
    {
        cout << "Invalid choice" <<endl;
    }
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
