/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4030.cpp (4x XOR Gates)
*/

#include "../../include/gates.hpp"

nts::Component4030::Component4030() {}

nts::Component4030::~Component4030() {}

nts::Tristate nts::Component4030::compute(std::size_t pin, size_t tick)
{
    PinConnection *current = nullptr;
    PinConnection *current2 = nullptr;

    for (size_t i = 0; i < output.size(); i++) {
        if (pin != output[i])
            continue;
        if (updateLinks()) {
            current = _inputs[firstInputPins[i]];
            current2 = _inputs[firstInputPins[i] + 1];
            _xorComponents[i].setLink(1, current->_component, current->_pin);
            _xorComponents[i].setLink(2, current2->_component, current2->_pin);
        }
        _outputs[pin] = _xorComponents[i].compute(3, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
