#include <cassert>

#include "game/Character.hpp"

int main()
{
    assert(1 == 1);

    Character hero1("Tuzik");

    assert(hero1.health() == 100);
    hero1.takeDamage(50);
    assert(hero1.health() == 50);

    return 0;
}