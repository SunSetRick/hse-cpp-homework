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

int main(int argc, char* argv[])
{   
    
    try {
        arguments_count_check(argc);
    }
    catch (std::invalid_argument e)
    {
        return 1;
    }
    
    int n = c_string_to_int(argv[1]);

    float* f_arr = new float[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> f_arr[i];
    }

    double comp{};
    float t{};

    for (int i = 0; i < n; ++i)
    {
        std::cin >> t;
        comp += t * f_arr[i];
    }

    std::cout << comp;

    delete[] f_arr;

}
