/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** FourInputAndComponent.cpp
*/

#include "../../include/elementaryComponents/FourInputAndComponent.hpp"

nts::FourInputANDComponent::FourInputANDComponent() {}

nts::FourInputANDComponent::~FourInputANDComponent() {}

nts::Tristate nts::FourInputANDComponent::compute(size_t pin, size_t tick)
{
    PinConnection *a = _inputs[1];
    PinConnection *b = _inputs[2];
    PinConnection *c = _inputs[3];
    PinConnection *d = _inputs[4];

    _andComponents.setLink(1, a->_component, a->_pin);
    _andComponents.setLink(2, b->_component, b->_pin);
    _andComponents.setLink(5, c->_component, c->_pin);
    _andComponents.setLink(6, d->_component, d->_pin);
    _andComponents.setLink(8, _andComponents, 3);
    _andComponents.setLink(9, _andComponents, 4);
    if (pin == 5) {
        _outputs[pin] = _andComponents.compute(10, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
