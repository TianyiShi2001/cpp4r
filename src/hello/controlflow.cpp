#include <iostream>
#include <vector>
#include <cassert>

namespace basic
{
    void while_example()
    {
        puts("basic while loop");
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
        puts("basic traditional for loop");
        puts("|i|j|");
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
            puts("It's Sunday!");
            break;
        case 6:
            puts("It's Saturday!");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            puts("It's weekday.");
            break;
        default:
            puts("Not a valid day of week!");
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
    std::vector<std::string> v{ "foo", "bar", "baz", "boo" };
    void copied()
    {
        puts("range-based for loop: copied");
        for (auto s : v)
        {
            std::cout << s << std::endl;
        }
    }
    void borrowed()
    {
        puts("range-based for loop: borrowed via reference");
        for (auto& s : v)
        {
            std::cout << s << std::endl;
        }
    }
    void mutation()
    {
        puts("range-based for loop: mutation");
        for (auto& s : v)
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
        puts("Break outer loop using goto:");
        puts("i j k");
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
                    printf("%d %d %d\n", i, j, k);
                }
            }
        for_i_end:
            {
                // * cannot be left blank; needs a placeholder
            }
        }
    }

    void with_flag()
    {
        puts("Break outer loop using flag:");
        puts("i j k");
        bool i_is_1{ false };
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
                    printf("%d %d %d\n", i, j, k);
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
        puts("Break outer loop using lambda:");
        puts("i j k");
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
                        printf("%d %d %d\n", i, j, k);
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