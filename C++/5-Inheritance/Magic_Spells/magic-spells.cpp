#include <iostream>
#include <vector>
#include <string>

class Spell {
private:
    std::string scrollName;
public:
    Spell() = default;

    explicit Spell(std::string &name) : scrollName(name) {
    }

    virtual ~Spell() = default;

    std::string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private:
    int power;
public:
    explicit Fireball(int power) : power(power) {
    }

    void revealFirepower() {
        std::cout << "Fireball: " << power << std::endl;
    }
};

class Frostbite : public Spell {
private:
    int power;
public:
    explicit Frostbite(int power) : power(power) {
    }

    void revealFrostpower() {
        std::cout << "Frostbite: " << power << std::endl;
    }
};

class Thunderstorm : public Spell {
private:
    int power;
public:
    explicit Thunderstorm(int power) : power(power) {
    }

    void revealThunderpower() {
        std::cout << "Thunderstorm: " << power << std::endl;
    }
};

class Waterbolt : public Spell {
private:
    int power;
public:
    explicit Waterbolt(int power) : power(power) {
    }

    void revealWaterpower() {
        std::cout << "Waterbolt: " << power << std::endl;
    }
};

class SpellJournal {
public:
    static std::string journal;

    static std::string read() {
        return journal;
    }
};

std::string SpellJournal::journal;

void counterspell(Spell *spell) {
    if (Fireball *fireball_ptr = dynamic_cast<Fireball *>(spell)) {
        fireball_ptr->revealFirepower();
    }
    else if (Frostbite *frostbite_ptr = dynamic_cast<Frostbite *>(spell)) {
        frostbite_ptr->revealFrostpower();
    }
    else if (Waterbolt *waterbolt_ptr = dynamic_cast<Waterbolt *>(spell)) {
        waterbolt_ptr->revealWaterpower();
    }
    else if (Thunderstorm *thunderstorm_ptr = dynamic_cast<Thunderstorm *>(spell)) {
        thunderstorm_ptr->revealThunderpower();
    }
    else {
        std::string journal_str = SpellJournal::read();
        size_t m = journal_str.length();
        std::string spell_str = spell->revealScrollName();
        size_t n = spell_str.length();

        int subsequence_length[2][n+1];
        // initialize the second row of subsequence_length to all zeros
        for (size_t j = 0; j < n + 1; ++j) {
            subsequence_length[1][j] = 0;
        }
        for (size_t i = 1; i < m + 1; ++i) {
            // copy the second row into the first row
            for (size_t j = 0; j < n + 1; ++j) {
                subsequence_length[0][j] = subsequence_length[1][j];
            }
            for (size_t j = 1; j < n + 1; ++j) {
                if (journal_str[i-1] == spell_str[j-1]) {
                    subsequence_length[1][j] = subsequence_length[0][j-1] + 1;
                }
                else {
                    subsequence_length[1][j] = std::max<int>(subsequence_length[1][j-1], subsequence_length[0][j]);
                }
            }
        }

        std::cout << subsequence_length[1][n] << "\n";
    }
}

class Wizard {
public:
    Spell *cast() {
        Spell *spell;

        std::string s;
        std::cin >> s;

        int power;
        std::cin >> power;

        if (s == "fire") {
            spell = new Fireball(power);
        }
        else if (s == "frost") {
            spell = new Frostbite(power);
        }
        else if (s == "water") {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            std::cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    std::cin >> T;
    Wizard Arawn;

    while (T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
        delete spell;
    }

    return 0;
}
