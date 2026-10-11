#include <iostream>


int main(int argc, char* argv[])
{
    char* a = argv[1];
    char* b = argv[2];

    bool in_minus_ints = false;
    int dif = 0;


    while (*a != '\0' && *b != '\0')
    {
        // мутка со знаками
        if(*a == '-')
        {
            in_minus_ints = true;
            if(*b != '-')
            {
                std::cout << "less";
                break;
            }
        }
        if(*b == '-')
        {
            in_minus_ints = true;
            if(*a != '-')
            {
                std::cout << "greater";
                break;
            }
        }
        if (*a == '+' && *b != '+')
        {
            ++a;
            continue;
        }
        if (*b == '+' && *a != '+')
        {
            ++b;
            continue;
        }

        if (*a == '.' && *b != '.')
        {
            if (!in_minus_ints)
            {
                std::cout << "less";
            }
            else
            {
                std::cout << "greater";
            }
            break;
        }
        if (*b == '.' && *a != '.')
        {
            if (!in_minus_ints)
            {
                std::cout << "greater";
            }
            else
            {
                std::cout << "less";
            }
            break;
        }

        if (*a < *b && dif == 0)
        {
            dif = -1;
        }
        if (*b < *a && dif == 0)
        {
            dif = 1;
        }
        ++a;
        ++b;
    }

    if (dif == 0)
    {
        if (*a != '\0')
        {
            std::cout << "greater";
        }
        else if (*b != '\0')
        {
            std::cout << "less";
        }
        else
        {
            std::cout << "equal";

        }
    }
    if (dif == -1 && !in_minus_ints || dif == 1 && in_minus_ints)
    {
        std::cout << "less";
    }
    if (dif == 1 && !in_minus_ints || dif == -1 && in_minus_ints)
    {
        std::cout << "greater";
    }

    // std::cout << a << ' ' << b << '\n';
}