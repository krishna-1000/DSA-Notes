#include <iostream>
#include <vector>
using namespace std;

void permute(string str, int l, int r, int &count)
{

    if (l == r)
    {
        count = count + 1;
        return;
    }

    for (int i = l; i <= r; i++)
    {
        swap(str[i], str[l]);
        permute(str, l + 1, r, count);
        swap(str[i], str[l]);
    }
}

int main()
{
    int count = 0;
    permute("abc", 0, 2, count);

    cout << count;

    return 0;
}