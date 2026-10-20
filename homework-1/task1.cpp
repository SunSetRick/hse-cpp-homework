#include <iostream>

enum COMPARE_STATE
{
    LESS,
    GREATER,
    EQUAL
};

bool global_negative = false;

void arguments_count_check(const int& argc)
{
    if (argc != 3)
    {
        throw std::invalid_argument("Invalid args count, you should give exactly 2 numbers");
    }
}

bool is_point(const char& c)
{
    return (c == '\0') || (c == '.');
}

int find_main_len(char* c_num)
{
    int len = 0;
    while(!is_point(*c_num))
    {
        c_num++;
        len++;
    }
    return len;
}

bool is_float_exists(char* c_num_from_point)
{
    if (*c_num_from_point == '\0')
    {
        return false;
    }
    return true;
}

COMPARE_STATE compare_main_parts(char* a, char* b, int count)
{
    
    while (count > 0)
    {
        if (*a < *b)
        {
            return (!global_negative) ? LESS : GREATER;
        }
        else if (*a > *b)
        {
            return (!global_negative) ? GREATER : LESS;
        }
        a++;
        b++;
        --count;
    }

    return EQUAL;
}



COMPARE_STATE compare_float_parts(char* a, char* b)
{
    while (*a != '\0' && *b != '\0')
    {
        if (*a < *b)
        {
            return (!global_negative) ? LESS : GREATER;
        }
        else if (*a > *b)
        {
            return (!global_negative) ? GREATER : LESS;
        }
        a++;
        b++;
    }
    if (*a != '\0')
    {
        return (!global_negative) ? GREATER : LESS;
    }
    else if (*b != '\0') 
    {
        return (!global_negative) ? LESS : GREATER;
    }
    else
    {
        return EQUAL;
    }
}



int main(int argc, char* argv[])
{
    arguments_count_check(argc);
    char* a = argv[1];
    char* b = argv[2];

    //sigh stabilisation
    bool is_a_neg = false;
    bool is_b_neg = false;

    if (*a == '+') ++a;
    if (*b == '+') ++b;

    if (*a == '-')
    {
        is_a_neg = true;
        ++a;
    }
    if (*b == '-')
    {
        is_b_neg = true;
        ++b;
    }

    if (is_a_neg != is_b_neg)
    {
        std::cout << ((is_a_neg) ? "less" : "greater");
        return 0;
    }
    else
    {
        global_negative = is_a_neg;
    }

    //save start positions of strings

    char* const start_a = a;
    char* const start_b = b;

    // go to the probably float point point and take len of the main part

    int a_main_len = find_main_len(a);
    int b_main_len = find_main_len(b);
    
    if (a_main_len != b_main_len)
    {
        if (!global_negative)
        {
            std::cout << ((a_main_len < b_main_len) ? "less" : "greater");
        }
        else
        {
            std::cout << ((a_main_len < b_main_len) ? "greater" : "less");
        }
        return 0;
    }

    COMPARE_STATE main_parts_comparison = compare_main_parts(start_a, start_b, a_main_len);
    switch(main_parts_comparison)
    {
        case LESS:
        {
            std::cout << "less";
            return 0;
        }
        case GREATER:
        {
            std::cout << "greater";
            return 0;
        }
        case EQUAL:
        {
            bool is_a_have_float = is_float_exists(start_a + a_main_len);
            bool is_b_have_float = is_float_exists(start_b + b_main_len);
            
            if (!is_a_have_float && !is_b_have_float)
            {
                std::cout << "equal";
            }
            else if (!is_a_have_float && is_b_have_float)
            {
                std::cout << (!global_negative) ? "less" : "greater";
            }
            else if (is_a_have_float && !is_b_have_float)
            {
                std::cout << (!global_negative) ? "greater" : "less";
            }
            else
            {
                char* const start_float_a = start_a + a_main_len + 1;
                char* const start_float_b = start_b + b_main_len + 1;
                COMPARE_STATE float_parts_comparison = compare_float_parts(start_float_a, start_float_b);

                switch(float_parts_comparison)
                {
                    case LESS:
                    {
                        std::cout << "less";
                        break;
                    }
                    case GREATER:
                    {
                        std::cout << "greater";
                        break;
                    }
                    case EQUAL:
                    {
                        std::cout << "equal";
                        break;
                    }
                }
            }     
        }
    }
}
    

<<<<<<< HEAD:homework-1/task1.cpp

    // std::cout << main_dif;

}
=======
>>>>>>> 6bd0807 (task 1 full rework: - добавил перепроверку количества аргументов):task1.cpp
