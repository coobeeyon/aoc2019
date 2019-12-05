﻿#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <cassert>

int desiredOutput = 19690720;
std::vector<int> initialCode =
 {  1, -1, -1,3,
    1,1,2,3,
    1,3,4,3,
    1,5,0,3,
    2,1,10,19,
    1,19,5,23,
    1,6,23,27,
    1,27,5,31,
    2,31,10,35,
    2,35,6,39,
    1,39,5,43,
    2,43,9,47,
    1,47,6,51,
    1,13,51,55,
    2,9,55,59,
    1,59,13,63,
    1,6,63,67,
    2,67,10,71,
    1,9,71,75,
    2,75,6,79,
    1,79,5,83,
    1,83,5,87,
    2,9,87,91,
    2,9,91,95,
    1,95,10,99,
    1,9,99,103,
    2,103,6,107,
    2,9,107,111,
    1,111,5,115,
    2,6,115,119,
    1,5,119,123,
    1,123,2,127,
    1,127,9,0,
    99,
    2,0,14,0};

int getOutput(std::vector<int> code, int noun, int verb)
{
    code[1] = noun;
    code[2] = verb;
    auto it = code.begin();
    while (it < code.end())
    {
        int opCode = *it++;
        int argA = *it++;
        int argB = *it++;
        int dst = *it++;
        if (opCode == 1)
        {
            code[dst] = code[argA] + code[argB];
        }
        else if (opCode == 2)
        {
            code[dst] = code[argA] * code[argB];
        }
        else if ( opCode == 99 )
        {
            break;
        }
        else
        {
            assert(false);
        }
    }
    return code[0];
}
int main()
{
    for (int noun = 0 ; noun < 99 ; ++noun)
    {
        for (int verb = 0 ; verb < 99 ; ++verb)
        {
            if ( desiredOutput == getOutput(initialCode, noun, verb))
            {
                std::cout << 100 * noun + verb;
                return 0;
            }
        }
    }
}