#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

bool isEvenValue(double x)
{
    return floor(x) == x && fmod(fabs(x), 2.0) == 0.0;
}

double sumNegative(const double* a, int n)
{
    double sum = 0; for (int i = 0; i < n; ++i) if (a[i] < 0) sum += a[i];
    return sum;
}

int findMinIndex(const double* a, int n)
{
    int best = 0; for (int i = 1; i < n; ++i) if (a[i] < a[best]) best = i;
    return best;
}

int findMaxIndex(const double* a, int n)
{
    int best = 0; for (int i = 1; i < n; ++i) if (a[i] > a[best]) best = i;
    return best;
}

double productBetweenExtremes(const double* a, int n)
{
    int left = findMinIndex(a, n), right = findMaxIndex(a, n);
    if (left > right) swap(left, right);
    double product = 1;
    for (int i = left + 1; i < right; ++i) product *= a[i];
    return product;
}

void sortEvenValues(double* a, int n)
{
    vector<int> positions; vector<double> values;
    for (int i = 0; i < n; ++i) if (isEvenValue(a[i])) { positions.push_back(i); values.push_back(a[i]); }
    sort(values.begin(), values.end());
    for (size_t i = 0; i < positions.size(); ++i) a[positions[i]] = values[i];
}

void printArray(const double* a, int n)
{
    for (int i = 0; i < n; ++i) { cout << setw(8) << a[i]; }
    cout << '\n';
}

#ifndef UNIT_TEST
int main()
{
    int n; cout << "n: "; if (!(cin >> n) || n <= 0 || n > 1000) return 1;
    double* a = new double[n];
    cout << "Enter " << n << " real values: ";
    for (int i = 0; i < n; ++i) if (!(cin >> a[i])) { delete[] a; return 1; }
    cout << fixed << setprecision(2) << "Initial:"; printArray(a, n);
    cout << "Negative sum = " << sumNegative(a, n) << '\n';
    cout << "Product between min and max = " << productBetweenExtremes(a, n) << '\n';
    sortEvenValues(a, n); cout << "After sorting even values:"; printArray(a, n);
    delete[] a;
}
#endif
