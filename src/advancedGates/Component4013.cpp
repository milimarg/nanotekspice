/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** DualFlipFlop.cpp
*/

#include "../../include/advancedGates/Component4013.hpp"

nts::DualFlipFlop::DualFlipFlop() {}

nts::DualFlipFlop::~DualFlipFlop() {}

nts::Tristate nts::DualFlipFlop::compute(std::size_t pin, size_t tick)
{
    PinConnection *data1 = _inputs[5];
    PinConnection *set1 = _inputs[6];
    PinConnection *reset1 = _inputs[4];
    PinConnection *clock1 = _inputs[3];

    PinConnection *data2 = _inputs[9];
    PinConnection *set2 = _inputs[8];
    PinConnection *reset2 = _inputs[10];
    PinConnection *clock2 = _inputs[11];

    if (updateLinks()) {
        _flipFlops[0].setLink(4, data1->_component, data1->_pin);
        _flipFlops[0].setLink(1, set1->_component, set1->_pin);
        _flipFlops[0].setLink(2, reset1->_component, reset1->_pin);
        _flipFlops[0].setLink(3, clock1->_component, clock1->_pin);
        _flipFlops[1].setLink(4, data2->_component, data2->_pin);
        _flipFlops[1].setLink(1, set2->_component, set2->_pin);
        _flipFlops[1].setLink(2, reset2->_component, reset2->_pin);
        _flipFlops[1].setLink(3, clock2->_component, clock2->_pin);
    }
    if (pin == 1) {
        _outputs[pin] = !_flipFlops[0].compute(5, tick);
        return _outputs[pin];
    }
    if (pin == 2) {
        _outputs[pin] = !_flipFlops[0].compute(6, tick);
        return _outputs[pin];
    }
    if (pin == 13) {
        _outputs[pin] = !_flipFlops[1].compute(5, tick);
        return _outputs[pin];
    }
    if (pin == 12) {
        _outputs[pin] = !_flipFlops[1].compute(6, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
