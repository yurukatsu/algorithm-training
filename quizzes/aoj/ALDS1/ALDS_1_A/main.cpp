#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void debug(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i == a.size() - 1 ? "\n" : " ");
}

vector<int> insertion_sort(vector<int> &a, bool debug_mode = false)
{
    int n = a.size();
    if (debug_mode)
        debug(a);

    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;

        if (debug_mode)
            debug(a);
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> sorted_a = insertion_sort(a, true);
}
