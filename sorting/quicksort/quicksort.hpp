
template <typename T>
int partition(T &cont, int size, int left, int right)
{
    int pivot = right; // depends on the implementation, this is the simplest choice of pivot
    int pivot_value = cont[pivot];
    int i = left;

    for (int j = left; j <= right-1; j++) {
        if (cont[j] < pivot_value) {
            // swap cont[i] with cont[j]
            auto temp = cont[i];
            cont[i] = cont[j];
            cont[j] = temp;
            ++i;
        }
    }
    // move pivot to its correct place
    auto temp = cont[i];
    cont[i] = cont[pivot];
    cont[pivot] = temp;
    return i;
}

template <typename T>
void quicksort(T &cont, int size, int left, int right)
{
    if (left >= right) return;
    int p = partition(cont, size, left, right);

    quicksort(cont, size, left, p-1);
    quicksort(cont, size, p+1, right);

    return;
}

template<typename T>
void quicksort(T &cont, int size)
{
    quicksort(cont, size, 0, size-1);
    return;
}