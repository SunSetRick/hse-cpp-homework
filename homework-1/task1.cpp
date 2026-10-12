#include <iostream>

bool is_point(const char& c)
{
    return (c == '\0') || (c == '.');
}

int main(int argc, char* argv[])
{
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

    //save start positions of strings

    const char* start_a = a;
    const char* start_b = b;

    // go to the probably float point point and take len of the main part

    int a_main_len = 0;
    int b_main_len = 0;
    

    while (!is_point(*a) || !is_point(*b))
    {
        if (!is_point(*a))
        {
            a_main_len++;
            ++a;
        }
        if (!is_point(*b))
        {
            b_main_len++;
            ++b;
        }
    }
    

    // forwsrd to decimal part and back to main to find dif
    int main_dif = 0;
    int dec_dif = 0;
    int i = 0;
    bool can_go_forward_dec_part = true;
    bool can_go_back_main_part = true;

    while(can_go_forward_dec_part || can_go_back_main_part)
    {
        // decimal
        if (can_go_forward_dec_part)
        {
            if (*(a + i) == '\0' && *(b + i) == '\0')
            {
                can_go_forward_dec_part = false;
            }
            else if (*(a + i) == '\0' || *(b + i) == '\0')
            {
                can_go_forward_dec_part = false;
                if (dec_dif == 0)
                {
                    dec_dif = (*(b + i) != '\0') ? -1 : 1;
                    // std::cout << "wtf";
                } 
                
            }
            else
            {
                if (*(a + i) != *(b + i) && dec_dif == 0)
                {
                    dec_dif = (*(a + i) < *(b + i)) ? -1 : 1;
                    can_go_forward_dec_part = false;
                    // std::cout << *(a + i) << *(b + i) << "\n";
                    // std::cout << a << b << "\n";
                }
            }
        }
        

        //back for main
        if (can_go_back_main_part)
        {
            if ((a - i) == start_a - 1 && (b - i) == start_b - 1)
            {
                can_go_back_main_part = false;
            }
            else if ((a - i) == start_a - 1 || (b - i) == start_b - 1)
            {
                can_go_back_main_part = false;
                // std::cout << 'heheh';
                main_dif = ((a - i) == start_a - 1) ? -1 : 1;
            }
            else
            {
                if (*(a - i) != *(b - i))
                {
                    main_dif = (*(a - i) < *(b - i)) ? -1 : 1;
                    // std::cout << *(a - i) << *(b - i) << ' ' << main_dif << '|';
                }
            }
        }

        ++i;
    }

    // std::cout << dec_dif;

    if (is_a_neg != is_b_neg)
    {
        std::cout << ((is_a_neg) ? "less" : "greater");
    }
    else
    {
        if (main_dif == 1)
        {
            std::cout << ((!is_a_neg) ? "greater" : "less");
        }
        else if (main_dif == -1)
        {
            std::cout << ((is_a_neg) ? "greater" : "less");
        }
        else
        {
                if (dec_dif == 1)
            {
                std::cout << ((!is_a_neg) ? "greater" : "less");
            }
            else if (dec_dif == -1)
            {
                std::cout << ((is_a_neg) ? "greater" : "less");
            }
            else
            {
                std::cout << "equal";
            }
        }
    }


    // std::cout << main_dif;

}
