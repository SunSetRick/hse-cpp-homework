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
    // enterput
    int n = c_string_to_int(argv[1]);
    int* arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int k{};
    std::cin >> k;

    // doing
    // make every dif more comfortable (between 0 and n)
    k = (n +(k % n)) % n;

    int tmp = arr[0];
    int i = 0;
    do
    {
        arr[i] = arr[(i + n - k) % n];
        i = (i + n - k) % n;
    } while ((i + n - k) % n  != 0);
    arr[i] = tmp;

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
}
