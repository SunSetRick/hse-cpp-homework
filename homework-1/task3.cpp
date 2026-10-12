#include <iostream>

int find_tens(char* str_p)
{
    int tens{1};
    while (*str_p != '\0')
    {
        tens *= 10;
        ++str_p;
    }
    // std::cout << tens << ' ';
    return tens / 10;
}

int c_string_to_int(char* p)
{
    int res{0};
    int tens{find_tens(p)};
    
    while (*p != '\0')
    {
        res += ((int)*p - (int)'0') * tens;
        // std::cout << *p << ' ' << tens << '\n';
        tens /= 10;
        ++p;
    }

    return res;
}

int main(int argc, char* argv[])
{
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

}
