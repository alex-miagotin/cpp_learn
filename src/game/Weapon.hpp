#pragma once

class Weapon
{
public:
    Weapon(int bulltest);
    bool fire();
    int damage();

private:
    int m_bullets{ 23 };
};