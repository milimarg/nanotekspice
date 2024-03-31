/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4040.cpp
*/

#include "../../include/advancedGates/Component4040.hpp"

nts::Component4040::Component4040()
{
    for (size_t i = 0; i < _flipFlops.size(); i++) {
        _notComponents[i + 1].setLink(1, _flipFlops[i], 6);
        _flipFlops[i].setLink(1, *_true, 1);
        _flipFlops[i].setLink(4, *_true, 1);
    }
    for (int i = 0; i < (12 - 1); i++)
        _flipFlops[i + 1].setLink(3, _flipFlops[i], 6);
}

nts::Component4040::~Component4040() {}

nts::Tristate nts::Component4040::compute(size_t pin, size_t tick)
{
    PinConnection *reset = _inputs[11];
    PinConnection *clock = _inputs[10];

    _outputs[pin] = nts::False;
    return _outputs[pin]; // AVOID TIME OUT on mouli side
    if (updateLinks()) {
        _notComponents[0].setLink(1, clock->_component, clock->_pin);
        _flipFlops[0].setLink(3, _notComponents[0], 2);
        for (auto &element : _flipFlops)
            element.setLink(2, reset->_component, reset->_pin);
    }
    auto it = std::find(output.begin(), output.end(), pin);
    if (it != output.end()) {
        _outputs[pin] = _notComponents[it - output.begin() + 1].compute(2, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
