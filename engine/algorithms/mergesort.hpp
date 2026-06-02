template<typename T> // Templates Are Inline By Definition

// Merge Algorithm
T merge(std::vector<T>& arrIn, int low, int mid, int high) {
	int pos1 = 0 // Position in Buffer Array (First Half of arrIn)
    int pos2 = mid + 1 // Position In Second Arrsy (Second Half of arrIn)
    int posM = low // Merge Position
    
	// Create Buffer Array (Slice arrIn Between low and middle
    std::vector<T> arr1((arrIn.begin() + low), (arrIn.begin() + mid + 1)); // Starts Inclusive, Ends Exclusive (Hence mid -> (mid + 1))

    return arrIn
}

// Full Merge Sort Algorithm
void mergeSort(std::vector<T>& arrIn, int low, int high) {

}