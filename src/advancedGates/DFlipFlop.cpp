/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** DFlipFlop.cpp
*/

#include "../../include/advancedGates/DFlipFlop.hpp"

nts::DFlipFlop::DFlipFlop() {}

nts::DFlipFlop::~DFlipFlop() {}

nts::Tristate nts::DFlipFlop::compute(std::size_t pin, size_t tick)
{
    bool updated = false;
    nts::Tristate setState = GET_STATE(_inputs[1]);
    nts::Tristate resetState = GET_STATE(_inputs[2]);
    nts::Tristate currentClock = GET_STATE(_inputs[3]);
    nts::Tristate dataState = GET_STATE(_inputs[4]);

    updateLinks();
    if (!updated && lastClockState == nts::False && currentClock == nts::True) {
        Q = dataState;
        updated = true;
    }
    if (!updated && setState == nts::True && resetState == nts::False) {
        Q = nts::True;
        updated = true;
    }
    if (!updated && setState == nts::False && resetState == nts::True) {
        Q = nts::False;
        updated = true;
    }
    if (!updated && setState == nts::True && resetState == nts::True)
        Q = nts::False;
    if (lastClockState != currentClock)
        lastClockState = currentClock;
    if (pin >= 5 && pin <= 6) {
        _outputs[pin] = pin == 5 ? Q : !Q;
        return _outputs[pin];
    }
    return nts::Undefined;
}
