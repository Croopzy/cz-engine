template<typename T> // Templates Are Inline By Definition

// Merge Algorithm
void merge(std::vector<T>& arrIn, int low, int mid, int high) {
	int pos1 = 0; // Position in Buffer Array (First Half of arrIn)
    int pos2 = mid + 1; // Position In Second Array (Second Half of arrIn)
    int posM = low; // Merge Position
    
	// Create Buffer Array (Slice arrIn From low To middle)
    std::vector<T> arr1((arrIn.begin() + low), (arrIn.begin() + mid + 1)); // Starts Inclusive, Ends Exclusive (Hence mid -> (mid + 1))
	int len1 = mid + 1 - low; // Number of Items in Buffer Array

	// Merging Arrays
	while (pos1 < len1 && pos2 < (high + 1)) { // While Not At End of List
		if (arr1[pos1] < arrIn[pos2]) { // Current Buffer Array Element < Current Second Array Element
			arrIn[posM] = arr1[pos1]; // Write Current Buffer Element To Merged Array
			pos1++; // Next Item in Buffer Array
		} else {
					arrIn[posM] = arrIn[pos2] // Write Current Element From Second Array To Merged Array
		}
	}
}

// Full Merge Sort Algorithm
void mergeSort(std::vector<T>& arrIn, int low, int high) {
	if (low < high){
		int mid = (low + high) / 2
		mergesort(arrIn, low, mid) // Sort First Half
		mergesort(arrIn, low, mid) // Sort Second Half
		merge(arrIn, low, mid, high) // Merge Sorted Halves
	}
}