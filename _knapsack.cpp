| Algorithm           | Time Complexity | Space Complexity | Approach            |
| ------------------- | --------------- | ---------------- | ------------------- |
| Fractional Knapsack | **O(n²)**       | **O(1)**         | Greedy              |
| 0/1 Knapsack        | **O(n × W)**    | **O(n × W)**     | Dynamic Programming |


#include <iostream>
#include <algorithm>
using namespace std;

// Function for Fractional Knapsack (Greedy)
double fractionalKnapsack(int n, int value[], int weight[], int W)
{
  double ratio[n];
  for (int i = 0; i < n; i++)
    ratio[i] = (double)value[i] / weight[i];

  // Sort items by ratio in descending order
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (ratio[i] < ratio[j])
      {
        swap(ratio[i], ratio[j]);
        swap(value[i], value[j]);
        swap(weight[i], weight[j]);
      }
    }
  }

  double totalValue = 0.0;
  for (int i = 0; i < n && W > 0; i++)
  {
    if (weight[i] <= W)
    {
      W -= weight[i];
      totalValue += value[i];
    }
    else
    {
      totalValue += value[i] * ((double)W / weight[i]);
      W = 0;
    }
  }
  return totalValue;
}

// Function for 0/1 Knapsack (Dynamic Programming)
int zeroOneKnapsack(int n, int value[], int weight[], int W)
{
  int dp[n + 1][W + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int w = 0; w <= W; w++)
    {
      if (i == 0 || w == 0)
        dp[i][w] = 0;
      else if (weight[i - 1] <= w)
        dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  return dp[n][W];
}

int main()
{
  int n = 3;                    // Number of items
  int value[] = {60, 100, 120}; // Values
  int weight[] = {10, 20, 30};  // Weights
  int W = 50;                   // Capacity of Knapsack

  double maxFractional = fractionalKnapsack(n, value, weight, W);
  int maxZeroOne = zeroOneKnapsack(n, value, weight, W);

  cout << "Fractional Knapsack (Greedy): " << maxFractional << endl;
  cout << "0/1 Knapsack (DP): " << maxZeroOne << endl;

  cout << "\nObservation:\n";
  if ((int)maxFractional != maxZeroOne)
    cout << "=> Greedy (Fractional) approach does NOT give the optimal result for 0/1 Knapsack.\n";
  else
    cout << "=> Both give the same result (rare case).\n";

  return 0;
}
