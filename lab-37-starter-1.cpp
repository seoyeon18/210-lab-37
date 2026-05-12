#include <iostream>
#include <string>
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
    string test = "ABC";

    cout << "Test string: " << test << endl;
    cout << "ASCII sum: " << sum_ascii(test) << endl;

    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
