#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Kinda like kadane's algorithm 

int main()
{
    std::string dna_sequence;
    std::cin >> dna_sequence;

    int max_sum  = 0;
    int curr_sum = 0;
    char curr = dna_sequence[0];
    for(const auto& el : dna_sequence)
    {
        if(curr == el)
        {
            curr_sum++;
        }
        else 
        {
            curr = el;
            curr_sum = 1;
        }
        max_sum = std::max(max_sum, curr_sum);
    }

    std::cout << max_sum << '\n';
}