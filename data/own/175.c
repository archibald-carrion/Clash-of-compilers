// Function for heap implementation
void heapify(int *heap, int heap_size, int i, int *freq_map) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && freq_map[heap[left]] > freq_map[heap[largest]]) largest = left;
    if (right < heap_size && freq_map[heap[right]] > freq_map[heap[largest]]) largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, heap_size, largest, freq_map);
    }
}
