#include <iostream>
#include <vector>
#include <cassert>

namespace basic
{
    void while_example()
    {
        std::cout << "basic while loop" << std::endl;
        int i = 10;
        while (i > 0)
        {
            i--;
            if (i == 8)
            {
                continue;
            }
            if (i == 5)
            {
                break;
            }
            std::cout << i << std::endl;
        }
    }
    void for_traditional()
    {
        std::cout << "basic traditional for loop" << std::endl;
        printf("|i|j|\n");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("|%d|%d|\n", i, j);
            }
        }
    }
    void switch_example()
    {
        int d = 5;
        switch (d)
        {
        case 0:
            printf("It's Sunday!\n");
            break;
        case 6:
            printf("It's Saturday!\n");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("It's weekday.\n");
            break;
        default:
            printf("Not a valid day of week!\n");
            break;
        }
    }
    void main()
    {
        while_example();
        for_traditional();
        switch_example();
    }
} // namespace basic

namespace range_based
{
    std::vector<std::string> v{"foo", "bar", "baz", "boo"};
    void copied()
    {
        std::cout << "range-based for loop: copied" << std::endl;
        for (auto s : v)
        {
            std::cout << s << std::endl;
        }
    }
    void borrowed()
    {
        std::cout << "range-based for loop: borrowed via reference" << std::endl;
        for (auto &s : v)
        {
            std::cout << s << std::endl;
        }
    }
    void mutation()
    {
        std::cout << "range-based for loop: mutation" << std::endl;
        for (auto &s : v)
        {
            s += '!';
        }
    }

    void main()
    {
        copied();
        borrowed();
        mutation();
        // after mutation
        borrowed();
    }
} // namespace range_based

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

    void main()
    {
        with_goto();
        with_flag();
        with_lambda();
    }
} // namespace break_outer

int main()
{
    basic::main();
    range_based::main();
    break_outer::main();
}