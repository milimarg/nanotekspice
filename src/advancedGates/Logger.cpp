/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Logger.cpp
*/

#include "../../include/advancedGates/Logger.hpp"
#include <bitset>
#include <fstream>

nts::Logger::Logger() {}

nts::Logger::~Logger() {}

nts::Tristate nts::Logger::compute(size_t pin, size_t tick)
{
    if (firstCall) {
        firstCall = false;
        return nts::Undefined;
    }
    (void)pin;
    std::bitset<8> bitSet;
    int bit = 0;
    char output = 0;
    nts::Tristate input;
    nts::Tristate inhibitState = GET_STATE(_inputs[10]);
    nts::Tristate clockState = GET_STATE(_inputs[9]);

    for (int i = 8; i > 0; i -= 1) {
        input = GET_STATE(_inputs[i]);
        if (input == nts::Undefined)
            return nts::Undefined;
        bit = input == nts::True;
        bitSet.set(i - 1, bit);
    }
    output = bitSet.to_ulong();
    if (inhibitState == nts::False && lastClockState == nts::False &&
    clockState == nts::True) {
        std::ofstream stream("./log.bin", std::ios::app);
        stream << output;
        stream.close();
    }
    if (lastClockState != clockState)
        lastClockState = clockState;
    return nts::Undefined;
}
