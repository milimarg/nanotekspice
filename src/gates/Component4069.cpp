/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4069.cpp (6x NOT Gates)
*/

#include "../../include/gates.hpp"

nts::Component4069::Component4069() {}

nts::Component4069::~Component4069() {}

nts::Tristate nts::Component4069::compute(std::size_t pin, size_t tick)
{
    PinConnection *current = nullptr;

    for (size_t i = 0; i < output.size(); i++) {
        if (pin != output[i])
            continue;
        if (updateLinks()) {
            current = _inputs[input[i]];
            _notComponents[i].setLink(1, current->_component, current->_pin);
        }
        _outputs[pin] = _notComponents[i].compute(2, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
