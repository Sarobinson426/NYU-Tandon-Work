#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void merge(vector<T>& vec, size_t leftpos, size_t leftend, size_t rightend, vector<T>& temp) {
	size_t rightpos = leftend + 1;
	size_t originalpos = leftpos;
	size_t temppos = leftpos;
	while (leftpos <= leftend && rightpos <= rightend) {
		if (vec[leftpos] < vec[rightpos])
			temp[temppos++] = vec[leftpos++];
		else
			temp[temppos++] = vec[rightpos++];
	}
	while (leftpos <= leftend)
		temp[temppos++] = vec[leftpos++];
	while (rightpos <= rightend)
		temp[temppos++] = vec[rightpos++];
	for (size_t i = originalpos; i <= rightend; i++)
		vec[i] = temp[i];
}

template <class T>
void mergeSort(vector<T>& vec, size_t start, size_t end, vector<T>& temp) {
	//cout << "start: " << start << endl;
	//cout << "end: " << end << endl;
	if (start >= end)
		return;
	size_t mid = (start + end) / 2;
	/*cout << "Left: ";
	for (int x = 0; x < mid; x++) {
		cout << vec[x] << " ";
	}
	cout << endl;
	cout << "Right: ";
	for (int x = mid + 1; x <  end; x++) {
		cout << vec[x] << " ";
	}
	cout << endl;*/
	mergeSort(vec, start, mid, temp); //sort the left
	mergeSort(vec, (mid + 1), end, temp); //sort the right
	merge(vec, start, mid, end, temp);
}

template <class T>
void mergeSort(vector<T>& vec) { //driver
	vector<T> temp(vec.size());
	//cout << "Vector.size()  passed into merge sort: " << vec.size() << endl;
	//cout << "Vector.size() (temp) passed to merges: " << temp.size() << endl;
	mergeSort(vec, 0, vec.size() - 1, temp);
}

int main()
{
	vector<int> skittle;
	bool is_filled;
	int input, count;

	is_filled = true;
	count = 0;
	cout << "Enter numbers to fill array (-1 to stop): ";

	while (is_filled) {
		cin >> input;
		if (input == -1) {
			is_filled = false;
		}
		else {
			skittle.push_back(input);
			count++;
		}
	}

	cout << "Before the sort: ";
	for (int x = 0; x < count; x++) {
		cout << skittle[x] << " ";
	}

	cout << endl;

	mergeSort(skittle);

	cout << "After the sort: ";
	for (int x = 0; x < count; x++) {
		cout << skittle[x] << " ";
	}
	cout << endl;


	return 0;
}