#include "Weapon.hpp"
#include "utils/Math.hpp"

Weapon::Weapon(int bullets)
    : m_bullets(bullets)
{

}

bool Weapon::fire()
{
    if (m_bullets <= 0) return false;
    --m_bullets;
    return true;
}

int Weapon::damage()
{
    return LifeExe::randomInt(5, 30);
}

