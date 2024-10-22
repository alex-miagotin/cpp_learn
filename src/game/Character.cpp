#include <iostream>

#include "Character.hpp"
#include "Weapon.hpp"
#include "utils/Math.hpp"

Character::Character(const char* name) : m_name(name)
{
  const int bullets = LifeExe::randomInt(1, 10);
  m_weapon = new Weapon(bullets);
}

Character::~Character()
{
  delete m_weapon;
  m_weapon = nullptr;
}

const char* Character::name() const
{
  return m_name;
}

int Character::health() const
{
  return m_health;
}

bool Character::attack(Character& other)
{
  bool fired = m_weapon->fire();
  if (fired)
  {
    auto damage = m_weapon->damage();
    std::cout << m_name << " attack " << other.name() << " with damage " << damage << std::endl;

    other.takeDamage(damage);
  }
  else
  {
    std::cout << m_name << " tried to attack " << other.name() << " but has no bullets!" << std::endl;
  }

  return fired;
}

void Character::takeDamage(int damage)
{
  m_health -= damage;
  if (m_health < 0) m_health = 0;

  if (m_health == 0)
  {
    // Die
    std::cout << m_name << " died!" << std::endl;
  }
  else
  {
    // Survive
    std::cout << m_name << " took " << damage << " damage! Health: " << m_health << std::endl;
  }
}

bool Character::dead()
{
  return m_health == 0;
}
