#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <regex>
#include <string_view>

#include "random.h"

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

struct Card {
  enum Rank : int {

    ace,   // 0
    two,   // 1
    three, // 2
    four,  // 3
    five,  // 4
    six,   // 5
    seven, // 6
    eight, // 7
    nine,  // 8
    ten,   // 9
    jack,  // 10
    queen, // 11
    king,  // 12

    max_ranks // 13
  };

  enum Suit : int {
    clubs,    // 0
    diamonds, // 1
    hearts,   // 2
    spades,   // 3
    max_suits // 4
  };

  Rank rank{};
  Suit suit{};

  friend std::ostream &operator<<(std::ostream &out, const Card &card);

  static constexpr std::array all_suits{
      clubs,
      diamonds,
      hearts,
      spades,
  };
  // static constexpr std::array<std::string_view, max_suits> suits_name{
  //     "clubs",
  //     "diamonds",
  //     "hearts",
  //     "spades",
  // };

  static constexpr std::array all_ranks{
      ace,   two,  three, four, five,  six,  seven,
      eight, nine, ten,   jack, queen, king,
  };
  // static constexpr std::array<std::string_view, max_ranks> ranks_name{
  //     "ace",   "two",  "three", "four", "five",  "six",  "seven",
  //     "eight", "nine", "ten",   "jack", "queen", "king",
  // };

  static_assert(std::size(all_suits) == max_suits,
                "suits array length not equal to max_suits");
  static_assert(std::size(all_ranks) == max_ranks,
                "rank array length not equal to max_rank");
  int value() const {
    static constexpr std::array rank_values{11, 2, 3,  4,  5,  6, 7,
                                            8,  9, 10, 10, 10, 10};
    return rank_values[this->rank];
  }
};

std::ostream &operator<<(std::ostream &out, const Card &card) {
  static constexpr std::array ranks{'A', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'T', 'J', 'Q', 'K'};
  static constexpr std::array suits{'C', 'D', 'H', 'S'};
  out << ranks[card.rank] << suits[card.suit];
  return out;
}

// class Deck {
// public:
//   Deck() = default;
//   Deck(Deck &&) = default;
//   Deck(const Deck &) = default;
//   Deck &operator=(Deck &&) = default;
//   Deck &operator=(const Deck &) = default;
//   ~Deck() = default;
//
// private:
// };
class Deck {
private:
  std::array<Card, 52> card_m{};
  std::size_t next_card{};

public:
  Deck() {
    std::size_t count{};
    for (auto rank : card_m[count].all_suits) {
      for (auto suit : card_m[count].all_ranks) {
        card_m[count++] = {suit, rank};
      }
    }
  }

  void print() const {
    for (auto suit : card_m) {
      std::cout << suit << ' ';
    }
    std::cout << '\n';
  }

  Card deal_card() {
    assert(next_card != 52 && "You ran out of cards");
    return card_m[next_card++];
  }

  void shuffle() {
    std::shuffle(card_m.begin(), card_m.end(), Random::mt);
    next_card = 0;
  }
};

int main() {
  Deck deck{};
  deck.print();

  std::cout << '\n';

  std::cout << deck.deal_card() << ' ' << deck.deal_card() << ' '
            << deck.deal_card() << '\n';

  deck.shuffle();
  std::cout << deck.deal_card() << ' ' << deck.deal_card() << ' '
            << deck.deal_card() << '\n';

  return 0;
}
