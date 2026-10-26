#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "stack.h"

void print_stack(Stack &s, std::ostream &out)
{
    std::vector<int> temp;
    while (!s.empty())
    {
        temp.push_back(s.get());
        s.pop();
    }

    for (int i = static_cast<int>(temp.size()) - 1; i >= 0; --i)
    {
        out << temp[i];
        if (i > 0) out << " ";
        s.push(temp[i]);
    }
    out << "\n";
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <script_file> <input_file>\n";
        return 1;
    }

    std::ifstream script_file(argv[1]);
    std::ifstream input_file(argv[2]);

    if (!script_file.is_open())
    {
        std::cerr << "Error opening script file\n";
        return 1;
    }

    std::string script((std::istreambuf_iterator<char>(script_file)),
                        std::istreambuf_iterator<char>());

    Stack stackA;
    Stack stackB;
    Stack* current_stack = &stackA;
    int k = 0;

    std::vector<size_t> flags;
    for (size_t i = 0; i < script.length(); ++i)
    {
        if (script[i] == '*' || script[i] == 'f')
        {
            flags.push_back(i);
        }
    }

    size_t ip = 0;
    while (ip < script.length())
    {
        char cmd = script[ip];
        switch (cmd)
        {
            case '^':
            case 'u':
                if (!current_stack->empty())
                {
                    k = current_stack->get();
                    current_stack->pop();
                }
                break;
            case 'v':
            case 'd':
                current_stack->push(k);
                break;
            case '/':
            case 's':
            {
                if (!current_stack->empty()) {
                    int a = current_stack->get(); current_stack->pop();
                    int b = current_stack->get(); current_stack->pop();
                    current_stack->push(a);
                    current_stack->push(b);
                }
                break;
            }
            case ';':
            case 'S':
                current_stack = (current_stack == &stackA) ? &stackB : &stackA;
                break;
            case '1':
            case 'l':
                current_stack->push(1);
                break;
            case '-':
            case 'm':
            {
                int a = current_stack->get(); current_stack->pop();
                int b = current_stack->get(); current_stack->pop();
                current_stack->push(b - a);
                break;
            }
            case '[':
            case 'i':
            {
                int val;
                if (input_file >> val)
                {
                    current_stack->push(val);
                }
                break;
            }
            case ']':
            case 'o':
                if (!current_stack->empty())
                {
                    std::cout << current_stack->get() << "\n";
                    current_stack->pop();
                }
                break;
            case '%':
            case 'r':
            {
                std::vector<int> elems;
                while (!current_stack->empty())
                {
                    elems.push_back(current_stack->get());
                    current_stack->pop();
                }
                for (int val : elems)
                {
                    current_stack->push(val);
                }
                break;
            }
            case '*':
            case 'f':
                break;
            case '>':
            case 'g':
            {
                if (!current_stack->empty())
                {
                    int n = current_stack->get();
                    current_stack->pop();
                    if (n != 0)
                    {
                        auto it = std::find(flags.begin(), flags.end(), ip);
                        if (it != flags.end())
                        {
                            size_t flag_idx = std::distance(flags.begin(), it);
                            long long target_idx = (long long)flag_idx + n;
                            if (target_idx >= 0 && target_idx < (long long)flags.size())
                            {
                                ip = flags[target_idx];
                            }
                        }
                    }
                }
                break;
            }
            default:
                break;
        }
        ip++;
    }

    print_stack(stackA, std::cout);
    print_stack(stackB, std::cout);

    return 0;
}