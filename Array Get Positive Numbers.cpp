// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW9 Q3
// Program: Get the Positive Numbers	
// Input: input is a dynamic integer array	
// Output: ouptus a dyanimic int array of different size only including the positive numbers from input array
// Description: 4 versions of a program performing the same thing extracting positive numbers 

#include <iostream>
#include <cstring>
using namespace std;

int* initialize_array();
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main1();
int main2();
int main3();
int main4();

int main()
{
	cout << "Version 1" << endl;
	main1();
	cout << "\n\nVersion 2" << endl;
	main2();
	cout << "\n\nVersion 3" << endl;
	main3();
	cout << "\n\nVersion 4" << endl;
	main4();

	return 0;
}
int* initialize_array() {
	int num_arr[20] = { -1, 2, 6, -5, 5, 10, 7, 11, 13, 20, 22, -8, 1, 78, 2, -6, 3, 45, 23, 39 };

	return num_arr;
}
int main1() {
	///////////////////////***VERSION ONE***//////////////////////////////////////
	int* ptr1;
	int arr_size = 20, out_size = 0;

	ptr1 = new int[arr_size];

	for (int index = 0, neg = 1; index < arr_size; index++, neg *= -1) {
		ptr1[index] = (index * neg);
		cout << ptr1[index] << " ";
	}

	ptr1 = getPosNums1(ptr1, arr_size, out_size);

	cout << "\noutsize: " << out_size << endl;
	for (int index = 0; index < out_size; index++) {
		cout << ptr1[index] << " ";
	}
		
	delete[]ptr1;
	ptr1 = NULL;

	return 0;
}
int main2() {
	///////////////////////***VERSION TWO***//////////////////////////////////////
	int* ptr2, *ptr3;
	int arr_size2 = 20, out_size2 = 0;

	ptr2 = new int[arr_size2];
	ptr3 = new int[arr_size2];

	for (int index = 0, neg = 1; index < arr_size2; index++, neg *= -1) {
		ptr2[index] = index * neg;
		cout << ptr2[index] << " ";
	}
	for (int index = 0; index < arr_size2; index++) {
		ptr3[index] = 0;
	}

	getPosNums2(ptr2, arr_size2, ptr3, out_size2);

	cout << "\noutsize: " << out_size2 << endl;
	for (int index = 0; index < out_size2; index++) {
		cout << ptr3[index] << " ";
	}

	delete[] ptr2;
	delete[] ptr3;

	return 0;
}
int main3() {
		///////////////////////***VERSION THREE***//////////////////////////////////////
		int* ptr4;
		int arr_size3 = 20, * out_size3, out_size4 = 0;

		out_size3 = &out_size4;
		ptr4 = new int[arr_size3];

		for (int index = 0, neg = 1; index < arr_size3; index++, neg *= -1) {
			ptr4[index] = index * neg;
			cout << ptr4[index] << " ";
		}

		ptr4 = getPosNums3(ptr4, arr_size3, out_size3);

		cout << "\noutsize: " << out_size4 << endl;
		for (int index = 0; index < out_size4; index++) {
			cout << ptr4[index] << " ";
		}

		delete[] ptr4;

		return 0;
}
int main4() {
	///////////////////////***VERSION FOUR***//////////////////////////////////////
	int* ptr5 = NULL, ** ptr6 = NULL;
	int arr_size4 = 20, out_size4 = 0, * ptr_out_size;
	ptr_out_size = &out_size4;

	ptr5 = new int[arr_size4];
	ptr6 = &ptr5;

	for (int index = 0, neg = 1; index < arr_size4; index++, neg *= -1) {
		ptr5[index] = index * neg;
		cout << ptr5[index] << " ";
	}
	
	getPosNums4(ptr5, arr_size4, ptr6, ptr_out_size);

	cout << "\noutsize: " << out_size4 << endl;
	for (int index = 0; index < out_size4; index++) {
		cout << *(*ptr6 + index) << " ";
	}

	delete[] ptr5;
	ptr5 = NULL;

	return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	int* ptr;

	ptr = new int[arrSize];

	for (int index = 0; index < arrSize; index++) {
		ptr[index] = NULL;
	}

	for (int index = 0, evendex = 0; index < arrSize ; index++) {
		if (arr[index] > 0) {
			ptr[evendex] = arr[index];
			outPosArrSize++;
			evendex++;
		}
	}

	return ptr;
}
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {

	for (int index = 0, evendex = 0; index < arrSize; index++) {
		if (arr[index] > 0) {
			outPosArr[evendex] = arr[index];
			outPosArrSize++;
			evendex++;
		}
	}
}
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
	int* ptr;

	ptr = new int[arrSize];

	for (int index = 0; index < arrSize; index++) {
		ptr[index] = NULL;
	}

	for (int index = 0, evendex = 0; index < arrSize; index++) {
		if (arr[index] > 0) {
			ptr[evendex] = arr[index];
			*outPosArrSizePtr += 1;
			evendex++;
		}
	}

	return ptr;
}
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
	int pos_num_count = 0;

	for (int index = 0, evendex = 0; index < arrSize; index++) {
		if (arr[index] > 0) {
			*(*outPosArrPtr + evendex) = arr[index];
			cout << arr[index] << " " << *(*outPosArrPtr + evendex) << " ";
			pos_num_count++;
			evendex++;
		}
	}

	*outPosArrSizePtr = pos_num_count;
}