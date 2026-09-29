#include <iostream>
#include <fstream>
#include <string>
#include "../LibraryCPPClass/array.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <a> <b>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
        std::cerr << "Error opening file\n";
        return 1;
    }

    int a = std::stoi(argv[2]);
    int b = std::stoi(argv[3]);

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

    size_t write_idx = 0;
    for (size_t read_idx = 0; read_idx < arr.size(); ++read_idx)
    {
        Data val = arr.get(read_idx);
        if (val < a || val > b)
        {
            arr.set(write_idx, val);
            ++write_idx;
        }
    }

    for (size_t i = write_idx; i < arr.size(); ++i)
    {
        arr.set(i, 0);
    }

    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr.get(i) << (i + 1 == arr.size() ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}