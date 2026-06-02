template<typename T> // Templates Are Inline By Definition

// Merge Algorithm
void merge(std::vector<T>& arrIn, int low, int mid, int high) {
	int pos1 = 0 // Position in Buffer Array (First Half of arrIn)
    int pos2 = mid + 1 // Position In Second Arrsy (Second Half of arrIn)
    int posM = low // Merge Position
    
	// Create Buffer Array (Slice arrIn From low To middle)
    std::vector<T> arr1((arrIn.begin() + low), (arrIn.begin() + mid + 1)); // Starts Inclusive, Ends Exclusive (Hence mid -> (mid + 1))
	int len1 = mid + 1 - low // Number of Items in Buffer Array

	// ...
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