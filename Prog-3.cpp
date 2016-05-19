#include <time.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <iostream>
using namespace std;
vector<int> vec;
int find_mid (int first,int mid, int last) {
	if (vec[first] > vec[mid]) swap(first, mid);
	if (vec[first] > vec[last]) swap(first, last);
	if (vec[mid] > vec[last]) swap(mid, last);
	return mid;
}
int find_pivot (int start, int end) {
	if (end -start < 9) 
		return find_mid(start, (end - start) / 2, end - 1);
	int n = end - start;
	int dis1 = (n - 9) / 8 + 1, dis2 = dis1 + 1, dis1_num = 8 - (n - 9) % 8, dis2_num = (n - 9) % 8;
	vector<int> nine;
	nine.push_back(start);
	int point = start;
	while (dis1_num > 0 || dis2_num > 0) {
		if (dis1_num > 0) {
			point += dis1;
			nine.push_back(point);
			dis1_num--;
		}
		else if (dis2_num > 0) {
			point += dis2;
			nine.push_back(point);
			dis2_num--;
		}
	}
	return find_mid(find_mid(nine[0], nine[1], nine[2]), find_mid(nine[3], nine[4], nine[5]), find_mid(nine[6], nine[7], nine[8]));

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
