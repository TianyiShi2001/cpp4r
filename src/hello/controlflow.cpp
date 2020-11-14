#include <iostream>
#include <vector>
#include <cassert>

namespace basic
{
    void while_example()
    {
        int i = 10;
        while (i > 0)
        {
            if (i == 8)
            {
                continue;
            }
            if (i == 5)
            {
                break;
            }
        }
    }
    void for_traditional()
    {
        printf("|i|j|\n");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("|%d|%d|", i, j);
            }
        }
    }
} // namespace basic

namespace break_outer
{

    void with_goto()
    {
        printf("Break outer loop using goto:\n");
        std::cout << "ijk " << std::endl;
        for (int i = 0; i < 3; ++i)
        {

            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (i == 1)
                    {
                        goto for_i_end;
                    }
                    std::cout << i << j << k << std::endl;
                }
            }
        for_i_end:
        {
        }
        }
    }

    void with_flag()
    {
        printf("Break outer loop using flag:\n");
        std::cout << "ijk " << std::endl;
        bool i_is_1{false};
        for (int i = 0; i < 3; ++i)
        {

            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (i == 1)
                    {
                        i_is_1 = true;
                        break;
                    }
                    else
                    {
                        i_is_1 = false;
                    }
                    std::cout << i << j << k << std::endl;
                }
                if (i_is_1)
                {
                    break;
                }
            }
        }
    }

    void with_lambda()
    {
        printf("Break outer loop using lambda:\n");
        std::cout << "ijk " << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            [&] {
                for (int j = 0; j < 3; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        if (i == 1)
                        {
                            return;
                        }
                        std::cout << i << j << k << std::endl;
                    }
                }
            }();
        }
    }
} // namespace break_outer

int main()
{
    basic::for_traditional();
    break_outer::with_goto();
    break_outer::with_flag();
    break_outer::with_lambda();
}