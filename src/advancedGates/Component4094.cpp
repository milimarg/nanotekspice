/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4094.cpp
*/

#include "../../include/advancedGates/Component4094.hpp"

nts::Component4094::Component4094()
{
    for (size_t i = 0; i < _flipFlops.size() - 1; i += 1)
        _flipFlops[i + 1].setLink(4, _flipFlops[i], 5);
    for (size_t i = 0; i < _flipFlops.size(); i += 1) {
        _outputsNot[i].setLink(1, _flipFlops[i], 5);
        _flipFlops[i].setLink(1, falseComponent, 1);
        _flipFlops[i].setLink(2, falseComponent, 1);
    }
    for (auto &element : _andComponents)
        element.setLink(1, _notComponent, 2);
}

nts::Component4094::~Component4094() {}

nts::Tristate nts::Component4094::compute(size_t pin, size_t tick)
{
    PinConnection *strobe = _inputs[1];
    PinConnection *data = _inputs[2];
    PinConnection *clock = _inputs[3];
    PinConnection *enable = _inputs[15];
    nts::Tristate enableState = !GET_STATE(enable);

    _notComponent.setLink(1, strobe->_component, strobe->_pin);
    _flipFlops[0].setLink(4, data->_component, data->_pin);
    for (auto &element : _flipFlops)
        element.setLink(3, clock->_component, clock->_pin);
    for (size_t i = 0; i < _outputsNot.size(); i += 1)
        _andComponents[i].setLink(2, _outputsNot[i], 2);
    auto it = std::find(outputs.begin(), outputs.end(), pin);
    if (it != outputs.end()) {
        _outputs[pin] = enableState == nts::True ?
            _andComponents[it - outputs.begin()].compute(3, tick) : nts::Undefined;
        return _outputs[pin];
    }
    return nts::Undefined;
}
