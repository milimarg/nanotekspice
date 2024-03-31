/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4017.cpp (10-bit Johnson Decade)
*/

#include "../../include/advancedGates/Component4017.hpp"

nts::Component4017::Component4017()
{
    for (auto &element : _bits)
        element = nts::False;
    _bits[currentBit] = nts::True;
}

nts::Component4017::~Component4017() {}

nts::Tristate nts::Component4017::compute(size_t pin, size_t tick)
{
    nts::Tristate currentClock = GET_STATE(_inputs[14]);
    nts::Tristate enableState = !GET_STATE(_inputs[13]);
    nts::Tristate resetState = GET_STATE(_inputs[15]);

    updateLinks();
    if (enableState && lastClockState == nts::False &&
    currentClock == nts::True) {
        if (resetState == nts::True) {
            _bits[currentBit] = nts::False;
            currentBit = 0;
            _bits[currentBit] = nts::True;
        } else {
            _bits[currentBit] = nts::False;
            currentBit = currentBit < _bits.size() - 1 ? currentBit + 1 : 0;
            _bits[currentBit] = nts::True;
        }
    }
    if (lastClockState != currentClock)
        lastClockState = currentClock;
    auto it = std::find(output.begin(), output.end(), pin);
    if (it != output.end()) {
        _outputs[pin] = _bits[it - output.begin()];
        return _outputs[pin];
    }
    if (pin == 12) {
        _outputs[pin] = currentBit >= 5 && currentBit <= 9 ? nts::False : nts::True;
        return _outputs[pin];
    }
    return nts::Undefined;
}
