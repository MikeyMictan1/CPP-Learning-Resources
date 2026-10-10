#pragma once
#include <string>

class Player {
public:
    Player(std::string name, int hp) : name_(std::move(name)), hp_(hp) {}

    void takeDamage(int amount);              // declared only
    int  getHp() const { return hp_; }        // defined in-class → implicitly inline, OK in header

private:
    std::string name_;
    int hp_;
};