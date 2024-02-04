#include <iostream>
#include <conio.h>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool mycomp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

// T.C : O(NlogN)
int solveAccomodationProblem(int &numberOfTrains, int arrival[], int departure[])
{
    vector<pair<int, int>> data;
    for (int i = 0; i < numberOfTrains; i++)
        data.push_back({arrival[i], departure[i]});

    // sort, keep that pair first which has small departure time
    sort(data.begin(), data.end(), mycomp);

    // starting train will be included anyhow
    int count = 1;

    // stores the departure time of the last train
    int lastDeparture = data[0].second;
    cout << data[0].first << ", " << data[0].second << "\n";
    for (int i = 1; i < numberOfTrains; i++)
    {
        if (data[i].first >= lastDeparture)
        {
            count++;
            lastDeparture = data[i].second;
            cout << data[i].first << ", " << data[i].second << "\n";
        }
    }
    return count;
}

// T.C : O(NlogN)
int shopCandiesMin(int prices[], int numberOfCandies)
{
    sort(prices, prices + numberOfCandies);

    int amount = 0;
    int buy = 0;
    int free = numberOfCandies - 1;
    while (buy <= free)
    {
        amount += prices[buy];
        buy++;
        free--;
        free--;
    }
    return amount;
}

// T.C : O(NlogN)
void defendKingdom()
{
    int x, y, t, towers;
    cin >> t;
    while (t--)
    {
        // x and y are the dimensions of the board (or the rectangle where towers will be placed)
        cin >> x >> y >> towers;
        vector<int> rowCoordinates;
        vector<int> columnCoordinates;

        // insert the imaginary defended row and defended column co-ordinates at the beginnning
        // so that area can be found for the edges (boundary)
        rowCoordinates.push_back(0);
        columnCoordinates.push_back(0);
        while (towers--)
        {
            int a, b;
            cin >> a >> b;
            rowCoordinates.push_back(a);
            columnCoordinates.push_back(b);
        }

        // insert the imaginary defended row and defended column co-ordinates at the end
        // so that area can be found for the edges (boundary)
        rowCoordinates.push_back(x + 1);
        columnCoordinates.push_back(y + 1);

        sort(rowCoordinates.begin(), rowCoordinates.end());
        sort(columnCoordinates.begin(), columnCoordinates.end());

        int maxLen = INT_MIN;
        for (int i = 1; i < rowCoordinates.size(); i++)
        {
            int a = rowCoordinates[i - 1];
            int b = rowCoordinates[i];
            maxLen = max(maxLen, b - a - 1);
        }

        int maxWidth = INT_MIN;
        for (int i = 1; i < columnCoordinates.size(); i++)
        {
            int a = columnCoordinates[i - 1];
            int b = columnCoordinates[i];
            maxWidth = max(maxWidth, b - a - 1);
        }

        cout << maxLen * maxWidth << "\n";
    }
}

bool mycomp2(pair<int, int> &a, pair<int, int> &b)
{
    double ratio1 = ((1.0) * a.first) / a.second;
    double ratio2 = ((1.0) * b.first) / b.second;
    return ratio1 > ratio2;
}

// T.C : O(NlogN)
int fractionalKnapsack(int val[], int wt[], int &n, int capacity, vector<pair<int, int>> &value_weight_pair_data)
{
    for (int i = 0; i < n; i++)
        value_weight_pair_data.push_back({val[i], wt[i]});

    sort(value_weight_pair_data.begin(), value_weight_pair_data.end());

    int totalProfit = 0;
    // check if whole item can be picked or only a fraction of it can be picked
    for (int i = 0; i < n; i++)
    {
        pair<int, int> item = value_weight_pair_data[i];
        int itemValue = item.first;
        int itemWeight = item.second;

        if (itemWeight <= capacity)
        {
            capacity -= itemWeight;
            totalProfit += itemValue;
        }
        else
        {
            // calculate the fraction  of the profit of that item
            totalProfit += (((1.0) * itemValue) / itemWeight) * capacity;
            capacity = 0;
            break;
        }
    }
    return totalProfit;
}
int main()
{
    system("cls");
    // ACCOMODATING N TRAINS ON 1 PLATFORM
    int numberOfTrains = 4;
    int arrival[] = {5, 8, 2, 4};
    int departure[] = {7, 11, 6, 5};
    int numberOfTrainsAccomodated = solveAccomodationProblem(numberOfTrains, arrival, departure);
    cout << "Number of trains which can be accomodated in 1 platform are : " << numberOfTrainsAccomodated << "\n";

    // SHOP CANDIES QUESTION ON LEETCODE
    // https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1
    int prices[] = {2, 8, 6, 9, 4, 7};
    int numberOfCandies = 6;
    int minAmountOfMoney = shopCandiesMin(prices, numberOfCandies);
    cout << "Minimum amount of money to be spent to buy all candies are : " << minAmountOfMoney << "\n";

    // DEFKIN - Defense of a Kingdom
    // https://www.spoj.com/problems/DEFKIN/
    // assume here 1 based indexing is followed
    defendKingdom();

    // MINIMUM COST TO JOIN ROPES
    // T.C : O(NlogN)
    // https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1?source=google&medium=cpc&device=c&keyword=&matchtype=&campaignid=20992253746&adgroup=&gad_source=1
    // HUFFMAN ENCODING BASED ON SAME CONCEPT - TRY IT OUT !

    // FRACTIONAL KNAPSACK
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int n = 3;
    int capacity = 50;
    vector<pair<int, int>> value_weight_pair_data;
    cout << "Maximum profit according to fractoinal knapsack is : " << fractionalKnapsack(val, wt, n, capacity, value_weight_pair_data) << "\n";

    // CHOCOLATE DISTRIBUTION PROBLEM - THIS IS BASED ON SLIDING WINDOW
    // T.C : O(NlogN)
    // https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
    return 0;
}