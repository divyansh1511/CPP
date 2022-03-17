#include <string>
#include <iostream>

std::string urlify(std::string& s, int true_len)
{
    int first_space_idx = -1;
    int num_spaces = 0;

    for (int i = 0; i < true_len; i++)
    {
        if (s[i] == ' ')
        {
            if (num_spaces == 0)
                first_space_idx = i;
            ++num_spaces;
        }
    }

    if (num_spaces == 0)
        return s;

    for (int i = (true_len - 1); i > first_space_idx; i--)
    {
        if (s[i] == ' ')
        {
            --num_spaces;
            continue;
        }
        s[i + 2 * num_spaces] = s[i];
        s[i] = ' ';
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s[i] = '%';
            s[i + 1] = '2';
            s[i + 2] = '0';
        }
    }
    
    return s;
}

int main(int argc, char** argv)
{
    std::string s1(" hi  ");
    std::string s2("Mr John Smith    ");
    std::string s3("foo");
    std::string s4("      ");

    std::cout << urlify(s1, 3) << std::endl;
    std::cout << urlify(s2, 13) << std::endl;
    std::cout << urlify(s3, 3) << std::endl;
    std::cout << urlify(s4, 2) << std::endl;
    return 0;
}