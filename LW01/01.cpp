#include <iostream>
#include <fstream>
#include "../LibraryCPPClass/array.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
        std::cerr << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    size_t size = 0;
    if (!(input >> size))
    {
        return 1;
    }

    Array arr(size);
    for (size_t i = 0; i < size; ++i)
    {
        Data val;
        input >> val;
        arr.set(i, val);
    }

    int count5 = 0, count4 = 0, count3 = 0, count2 = 0;

    for (size_t i = 0; i < arr.size(); ++i)
    {
        Data mark = arr.get(i);
        if (mark == 5) ++count5;
        else if (mark == 4) ++count4;
        else if (mark == 3) ++count3;
        else if (mark == 2) ++count2;
    }

    std::cout << "5: " << count5 << ", 4: " << count4 
              << ", 3: " << count3 << ", 2: " << count2 << "\n";

    return 0;
}