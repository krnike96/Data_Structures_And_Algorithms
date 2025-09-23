#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int v, w;
    double r = 0.0;
};

double frac_knapsack(vector<Item> &items, int n, int W, vector<pair<int, double>> &selected)
{
    sort(items.begin(), items.end(), [](Item a, Item b)
         { return a.r > b.r; });

    double val = 0.0;
    int rem = W;

    for (int i = 0; i < n; i++)
    {
        if (items[i].w <= rem)
        {
            val += items[i].v;
            rem -= items[i].w;
            selected.push_back({i, 1.0}); // Item fully taken
        }
        else
        {
            double fraction = (double)rem / items[i].w;
            val += items[i].r * rem;
            selected.push_back({i, fraction}); // Item partially taken
            rem = 0;
            break;
        }
    }
    return val;
}

int main()
{
    int n;
    cout << "Enter the no. of available items: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of items must be positive.\n";
        return main();
    }

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the values for (value & weight) of item-" << i + 1 << ": ";
        cin >> items[i].v >> items[i].w;
        if (items[i].w <= 0 || items[i].v < 0)
        {
            cout << "Invalid input: Weight must be positive, and value must be non-negative.\n";
            return 1;
        }
    }

    int W;
    cout << "Enter the Weight of the knapsack: ";
    cin >> W;
    if (W <= 0)
    {
        cout << "Knapsack weight must be positive.\n";
        return 1;
    }

    for (int i = 0; i < n; i++)
        items[i].r = (double)items[i].v / items[i].w;

    vector<pair<int, double>> selected;
    double max_val = frac_knapsack(items, n, W, selected);

    cout << "Maximum value: " << fixed << setprecision(2) << max_val << endl;
    cout << "Selected items:\n";
    for (auto &p : selected)
    {
        int idx = p.first;
        double fraction = p.second;
        cout << "Item " << idx + 1 << " (Value: " << items[idx].v
             << ", Weight: " << items[idx].w << ") - ";
        if (fraction == 1.0)
            cout << "Fully taken\n";
        else
            cout << "Taken " << fixed << setprecision(2) << fraction * 100 << "%\n";
    }

    return 0;
}