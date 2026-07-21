#pragma once
#include <vector>

// Merge Algorithm
template<typename T> // Templates Are Inline By Definition
void merge(std::vector<T>& arrIn, int low, int mid, int high, bool reverse = false) {
	int pos1 = 0; // Position in Buffer Array (First Half of arrIn)
	int pos2 = mid + 1; // Position In Second Half of arrIn
	int posM = low; // Merge Position
    
	// Create Buffer Array (Slice arrIn From low To middle)
    std::vector<T> arr1((arrIn.begin() + low), (arrIn.begin() + mid + 1)); // Starts Inclusive, Ends Exclusive (Hence mid -> (mid + 1))
	int len1 = arr1.size(); // Number of Items in Buffer Array

	// Merging Arrays
	while (pos1 < len1 && pos2 <= high) { // While Not At End of Either List
		if (!reverse ? (arr1[pos1] < arrIn[pos2]) : (arr1[pos1] > arrIn[pos2])) { // Compare Current Buffer Array Element To Current Second Half Element
			arrIn[posM] = arr1[pos1]; // Write Current Buffer Element To Merged Array
			pos1++; // Next Item in Buffer Array
		} else {
					arrIn[posM] = arrIn[pos2]; // Write Current Element From Second Array To Merged Array
					pos2++; // Next Item in Second Half
		}
		posM++; // Always Increment Position in Merged Array
	}

	while (pos1 < len1) { // Executes IF pos2 == (high + 1)
    	arrIn[posM] = arr1[pos1]; // Copy Remaining Buffer Array To Merged Array
    	pos1++; // Next Item in Buffer Array
    	posM++; // Increment Position in Merged Array
	}

	while (pos2 <= high) { // Executes IF pos1 == len1
    	arrIn[posM] = arrIn[pos2]; // Copy Remaining Second Half To Merged Array
    	pos2++; // Next Item in Second Half
    	posM++; // Increment Position in Merged Array
	}
};


// Full Merge Sort Algorithm
template<typename T>
void mergeSort(std::vector<T>& arrIn, int low, int high, bool reverse = false) {
	if (low < high){
		int mid = (low + high) / 2;
		mergeSort(arrIn, low, mid, reverse); // Sort First Half
		mergeSort(arrIn, (mid + 1), high, reverse); // Sort Second Half
		merge(arrIn, low, mid, high, reverse); // Merge Sorted Halves
	}
};
