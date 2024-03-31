/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** FourBitAdderComponent.cpp (4-bit full adder)
*/

#include "../../include/advancedGates.hpp"

nts::FourBitAdderComponent::FourBitAdderComponent()
{
    for (size_t i = 0; i < halfMinusOne; i++)
        _fullAdder[i + 1].setLink(3, _fullAdder[i], 5);
}

nts::FourBitAdderComponent::~FourBitAdderComponent() {}

nts::Tristate nts::FourBitAdderComponent::compute(std::size_t pin, size_t tick)
{
    PinConnection *c = _inputs[inputNumber];

    if (updateLinks()) {
        a.clear();
        b.clear();
        for (auto &element : aPins)
            a.push_back(_inputs[element]);
        for (auto &element : bPins)
            b.push_back(_inputs[element]);
        _fullAdder[0].setLink(3, c->_component, c->_pin);
        for (size_t i = 0; i < (inputNumber - 1) / 2; i++) {
            _fullAdder[halfMinusOne - i].setLink(1, a[i]->_component, a[i]->_pin);
            _fullAdder[halfMinusOne - i].setLink(2, b[i]->_component, b[i]->_pin);
        }
    }
    const size_t firstPinOutput = inputNumber + 1;
    const size_t lastPinOutput = firstPinOutput + halfMinusOne;
    if (pin >= firstPinOutput && pin <= lastPinOutput) { // are output values
        _outputs[pin] = _fullAdder[pin - firstPinOutput].compute(4, tick);
        return _outputs[pin];
    }
    if (pin == lastPinOutput + 1) { // is carry out
        _outputs[pin] = _fullAdder[halfMinusOne].compute(5, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
