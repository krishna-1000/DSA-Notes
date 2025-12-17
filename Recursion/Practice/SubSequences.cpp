#include <iostream>
#include <string>
#include <vector>
using namespace std;

void SubSequences(string s, int index, string current)
{

    if (index == s.length())
    {
        if (current == "")
        {
            cout << "_";
        }
        else
        {

            cout << current << endl;
        }
        return;
    }

    SubSequences(s, index + 1, current + s[index]);
    SubSequences(s, index + 1, current);
}

void SubSet(int arr[], int index, int size, vector<int> current)
{

    if (index == size)
    {
        for (int i = 0; i < current.size(); i++)
        {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

        SubSet(arr,index+1,size,current);
    current.push_back(arr[index]);

    SubSet(arr,index+1,size,current);


}

int main()
{
    int arr[3] = {1, 2, 3};
    // SubSequences(s, 0,"");
    vector<int> current;
    SubSet(arr, 0, 3,current);
    return 0;
}
