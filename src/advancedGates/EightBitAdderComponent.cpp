/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** EightBitAdderComponent.cpp
*/

#include "../../include/advancedGates.hpp"

nts::EightBitAdderComponent::EightBitAdderComponent()
{
    for (size_t i = 0; i < halfMinusOne; i++)
        _fullAdder[i + 1].setLink(3, _fullAdder[i], 5);
}

nts::EightBitAdderComponent::~EightBitAdderComponent() {}

nts::Tristate nts::EightBitAdderComponent::compute(std::size_t pin, size_t tick)
{
    PinConnection *c = _inputs[inputNumber];

    if (updateLinks()) {
        a.clear();
        b.clear();
        for (size_t i = 1; i < inputNumber; i++)
            (i % 2 == 1 ? a : b).push_back(_inputs[i]);
        _fullAdder[0].setLink(3, c->_component, c->_pin);
        for (size_t i = 0; i < (inputNumber - 1) / 2; i++) {
            _fullAdder[halfMinusOne - i].setLink(1, a[i]->_component, a[i]->_pin);
            _fullAdder[halfMinusOne - i].setLink(2, b[i]->_component, b[i]->_pin);
        }
    }
    const size_t firstPinOutput = inputNumber + 1;
    const size_t lastPinOutput = firstPinOutput + halfMinusOne;
    if (pin >= firstPinOutput && pin <= lastPinOutput) { // are output values
        _outputs[pin] = _fullAdder[lastPinOutput - pin].compute(4, tick);
        return _outputs[pin];
    }
    if (pin == lastPinOutput + 1) { // is carry out
        _outputs[pin] = _fullAdder[halfMinusOne].compute(5, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
