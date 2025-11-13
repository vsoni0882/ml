
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
  int n;
  cout << "Enter number of cities: ";
  cin >> n;

  if (n <= 1)
  {
    cout << "Need at least 2 cities.\n";
    return 0;
  }

  int dist[20][20];
  cout << "Enter the distance matrix (" << n << "x" << n << "):\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> dist[i][j];
    }
  }

  vector<int> cities;
  for (int i = 1; i < n; i++)
    cities.push_back(i);

  int minCost = INT_MAX;
  vector<int> bestPath;

  do
  {
    int currentCost = 0;
    int k = 0; // start from city 0

    for (int i = 0; i < cities.size(); i++)
    {
      currentCost += dist[k][cities[i]];
      k = cities[i];
    }
    currentCost += dist[k][0]; // return to start city

    if (currentCost < minCost)
    {
      minCost = currentCost;
      bestPath = cities;
    }

  } while (next_permutation(cities.begin(), cities.end()));

  cout << "\nMinimum cost: " << minCost << endl;
  cout << "Shortest Path: 0 ";
  for (int city : bestPath)
    cout << "-> " << city << " ";
  cout << "-> 0\n";

  return 0;
}
Output : Enter number of cities : 4 Enter the distance matrix(4x4) : 0 10 15 20 10 0 35 25 15 35 0 30 20 25 30 0

         Minimum cost : 80 Shortest Path : 0->1->3->2->0
