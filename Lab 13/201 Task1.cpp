#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5];
    int j=0;
    set <int> st;
    for(int i=0;i<10;i++)
    {
        if(i%2) st.insert(i);
        else {
            arr[j]=i;
            j++;
        }
    }

    vector <int> v(10);
    merge(arr, arr+5, st.begin(), st.end(), v.begin());
    for (auto x : v) cout << x << " ";
    return 0;
}
