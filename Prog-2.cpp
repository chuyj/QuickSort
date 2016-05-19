#include <time.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <iostream>
using namespace std;
vector<int> vec;
int find_pivot (int start, int end) {
	int mid = (end - start) / 2 + start;
	int first = start, last = end - 1;
	if (vec[first] > vec[mid]) swap(first, mid);
	if (vec[first] > vec[last]) swap(first, last);
	if (vec[mid] > vec[last]) swap(mid, last);
	return mid;
}
void quick_sort (int start, int end) {
	if (end-start <= 1) return ;
	swap(vec[start], vec[find_pivot(start, end)]);
	int pivot = vec[start];
	int left = start+1, right = end-1;
	bool done = false;
	while (!done) {
		while (left < end && vec[left] <= pivot)
			left++;
		while (right > start && vec[right] > pivot)
			right--;
		if (left < right)
			swap(vec[left], vec[right]);
		else {
			done = true;
			if (left == end) {
				swap(vec[start], vec[end-1]);
				quick_sort(start, end - 1);
			}
			else if (right == start)
				quick_sort(start + 1, end);
			else {
				swap(vec[start], vec[right]);
				quick_sort(start, right);
				quick_sort(right + 1, end);
			}
		}
	}
	return ;
}

int main()
{
	int n;
	while (cin >> n) {
		vec.push_back(n);
	}
	quick_sort(0, vec.size());
	for (size_t i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;
	return 0;
}
