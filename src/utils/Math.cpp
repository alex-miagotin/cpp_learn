#include <random>

#include "Math.hpp"

namespace LifeExe {
    int max(int x, int y)
    {
        return x > y ? x : y;
    }

    int factorial(int n)
    {
        return n <= 1 ? 1 : n * factorial(n - 1);
    }

    int sum(int n)
    {
        return n <= 0 ? 0 : n + sum(n - 1);
    }

    int randomInt(int min, int max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> dist(min, max);
        
        return dist(gen);
    }
}
