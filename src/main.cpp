#include "pch.hpp"

#include "game/Character.hpp"
#include "utils/Math.hpp"

int main()
{
  #ifdef SKIP_GAME
    std::cout << "Skipping game..." << std::endl;
    return 0;
  #endif

  Character hero1("Tuzik");
  Character hero2("Barsik");

  Character * heroes[] = { &hero1, &hero2 };
  
  int round = 0;

  while (true) {
    std::cout << "================= Round " << round << " =================" << std::endl;
    
    int randomHeroIndex = LifeExe::randomInt(0, 1);
    Character * firstAttacker = heroes[randomHeroIndex];
    Character * secondsAttacker = heroes[1 - randomHeroIndex];

    bool hero1Attacked = firstAttacker->attack(*secondsAttacker);    
    if (hero1Attacked) {
      if (secondsAttacker->health() <= 0) {
        std::cout << firstAttacker->name() << " win!" << std::endl;
        break;
      }
    }

    bool hero2Attacked = secondsAttacker->attack(*firstAttacker);
    if (hero2Attacked) {
      if (firstAttacker->health() <= 0) {
        std::cout << secondsAttacker->name() << " win!" << std::endl;
        break;
      }
    }

    if (!hero1Attacked && !hero2Attacked) {
      std::cout << "Both heroes have no bullets!" << std::endl;
      break;
    }

    ++round;
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  std::cout << "================= Game over! =================" << std::endl;

  return 0;
}