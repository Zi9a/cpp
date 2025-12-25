#include "random.h"

#include <iostream>

#include <string>
#include <string_view>

class Monster {
public:
  enum Type {
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,
    maxMonsterTypes
  };

private:
  Type m_type {};
  std::string m_name {"???"};
  std::string m_roar {"???"};
  int m_hitPoints {};

public:
  Monster(Type type, std::string_view name, std::string_view roar, int hitPoints) 
  : m_type{type}
  , m_name{name}
  , m_roar{roar}
  , m_hitPoints{hitPoints} {}

  Type getType() { return m_type; }
  std::string_view getName() { return m_name; }
  std::string_view getRoar() { return m_roar; }
  int getHitPoints() { return m_hitPoints; }


  constexpr void print() const;
  constexpr std::string_view getMonsterType() const;
};

constexpr void Monster::print() const {
  std::cout << m_name << " the " << getMonsterType();

  if (this->m_hitPoints <= 0) {
    std::cout << " is dead!" << '\n';
  } else {
    std::cout << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
  }
}

constexpr std::string_view Monster::getMonsterType() const {
  switch(this->m_type) {
    case Dragon: return "Dragon";
    case Goblin: return "Goblin";
    case Ogre: return "Ogre";
    case Orc: return "Orc";
    case Skeleton: return "Skeleton";
    case Troll: return "Troll";
    case Vampire: return "Vampire";
    case Zombie: return "Zombie";
    default: return "???";
  }
}

namespace MonsterGenerator {
std::string_view getName(int num) {
  switch (num) {
    case 0:  return "Blarg";
    case 1:  return "Moog";
    case 2:  return "Pksh";
    case 3:  return "Tyrn";
    case 4:  return "Mort";
    case 5:  return "Hans";
    default: return "???"; 
  }
}

std::string_view getRoar(int num) {
  switch (num) {
    case 0:  return "*ROAR*";
    case 1:  return "*peep*";
    case 2:  return "*squeal*";
    case 3:  return "*whine*";
    case 4:  return "*growl*";
    case 5:  return "*burp*";
    default: return "???";
  }
}

Monster generate() {
  return Monster{
    static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes-1)),
    getName(Random::get(0,5)),
    getRoar(Random::get(0,5)),
    Random::get(1, 100)
  };
}
}


int main() {
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
