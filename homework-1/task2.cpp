#include <iostream>

void arguments_count_check(const int& argc)
{
    if (argc != 2)
    {
        throw std::invalid_argument("Invalid args count, you should give exactly 2 numbers");
    }
}

int c_string_to_int(char* p)
{
    int res{0};
    
    while (*p != '\0')
    {
        res *= 10;
        res += (static_cast<int>(*p) - static_cast<int>('0'));
        ++p;
    }

    return res;
}

void rotate(int*& arr, int left_index, int right_index)
{
    int tmp;
    while (left_index < right_index)
    {
        tmp = arr[left_index];
        arr[left_index] = arr[right_index];
        arr[right_index] = tmp;
        ++left_index;
        --right_index;
    }
}

int main(int argc, char* argv[])
{
    try {
        arguments_count_check(argc);
    }
    catch (std::invalid_argument e)
    {
        return 1;
    }
    
    // enterput
    int n = c_string_to_int(argv[1]);
    int* arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;

    k = k % n;
    if (k < 0) {k += n;}

    // reversal algorithm

    rotate(arr, 0, n - k - 1);
    rotate(arr, n - k, n - 1);
    rotate(arr, 0, n - 1);

    // output

    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << '\n';
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    delete[] arr;
}
