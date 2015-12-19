#include <iostream>
using namespace std;

int binary_search(int* a, int len, int goal);

int main()
{
    const int LEN  = 10000;
    int a[LEN];
    for(int i = 0; i < LEN; i++)
        a[i] = i - 5000;
    int goal;
    cin>>goal;
    int index = binary_search(a, LEN, goal);

    if(index != -1)
        cout<<goal<<"在数组中的下标为"<<binary_search(a, LEN, goal)<<endl;
    else
        cout<<"不存在"<<goal<<endl;
    return 0;
}

int binary_search(int* a, int len, int goal)
{
    int low = 0;
    int high = len - 1;
    while(low <= high)
    {
        int middle = (low + high)/2;
        if(a[middle] == goal)
            return middle;
        else if(a[middle] > goal)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}
