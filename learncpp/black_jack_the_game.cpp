#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include <string_view>

#include "random.h"

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

namespace Setting {
constexpr int threshold_win{17};
constexpr int bust{21};
} // namespace Setting

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

  static constexpr std::array all_ranks{
      ace,   two,  three, four, five,  six,  seven,
      eight, nine, ten,   jack, queen, king,
  };

  static_assert(std::size(all_suits) == max_suits,
                "suits array length not equal to max_suits");
  static_assert(std::size(all_ranks) == max_ranks,
                "rank array length not equal to max_rank");
  int value() const {
    static constexpr std::array rank_values{11, 2, 3,  4,  5,  6, 7,
                                            8,  9, 10, 10, 10, 10};
    return rank_values[rank];
  }
};

std::ostream &operator<<(std::ostream &out, const Card &card) {
  static constexpr std::array ranks{'A', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'T', 'J', 'Q', 'K'};
  static constexpr std::array suits{'C', 'D', 'H', 'S'};
  out << ranks[card.rank] << suits[card.suit];
  return out;
}

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

template <std::size_t N> class Player {
private:
  std::array<Card, N> card_m{};
  int score_m{};

public:
  Player(std::array<Card, N> cards) : card_m{cards} {}
  int get_score() const { return score_m; }

  void calculate_score() {
    for (Card card : card_m) {
      score_m += card.value();
    }
  }

  bool set_drawn_card_score(Card card, std::string_view name) {
    int score{card.value()};
    score_m += score;

    std::cout << "The " << name << " drew the card: " << card << '\n';
    std::cout << "The " << name << " now has score: " << score_m << '\n';

    if (score_m > Setting::bust) {
      std::cout << " - The " << name << " went bust!\n";
      return false;
    }
    if (score_m > Setting::threshold_win) {
      std::cout << " - the " << name << " now has score more than 17, " << name
                << " stopped "
                   "drawing cards\n";
      return false;
    }

    std::cout << '\n';
    return true;
  }
};

char get_input_character() {
  char character{};
  while (true) {
    std::cout << "(h) to hit, or (s) to stand: ";
    std::cin >> character;
    if (!std::cin) {
      std::cout << "Invalid Input!\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (character == 's' || character == 'h') {
      return character;
    }
  }
}

void play_black_jack() {
  Deck deck{};
  deck.shuffle();

  std::array<Card, 2> player_cards{{deck.deal_card(), deck.deal_card()}};
  std::array<Card, 1> dealer_cards{{deck.deal_card()}};

  Player player{player_cards};
  Player dealer{dealer_cards};

  player.calculate_score();
  dealer.calculate_score();

  std::cout << "the dealer shows: " << dealer.get_score() << '\n';
  std::cout << "the player shows: " << player.get_score() << '\n';
  std::cout << '\n';

  // dealer drawing
  bool keep_drawing{true};
  while (keep_drawing) {
    keep_drawing = dealer.set_drawn_card_score(deck.deal_card(), "dealer");

    if (!keep_drawing) {
      break;
    }

    char hit_or_stand{get_input_character()}; // 'h' for hit and 's' for stand
    if (hit_or_stand != 'h') {
      continue;
    }

    keep_drawing = player.set_drawn_card_score(deck.deal_card(), "player");

    if (!keep_drawing) {
      break;
    }
  }

  if (player.get_score() > Setting::bust ||
      dealer.get_score() >= player.get_score() &&
          dealer.get_score() <= Setting::bust) {
    std::cout << " - dealer wins" << '\n';
  } else {
    std::cout << " - player wins" << '\n';
  }
}

int main() {
  while (true) {
    std::cout << ">> ctrl + c to quit\n";
    play_black_jack();
    std::cout << '\n';
  }
  return 0;
}
