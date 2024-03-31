/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** FourInputOrComponent.cpp
*/

#include "../../include/elementaryComponents/FourInputOrComponent.hpp"

nts::FourInputORComponent::FourInputORComponent() {}

nts::FourInputORComponent::~FourInputORComponent() {}

nts::Tristate nts::FourInputORComponent::compute(size_t pin, size_t tick)
{
    PinConnection *a = _inputs[1];
    PinConnection *b = _inputs[2];
    PinConnection *c = _inputs[3];
    PinConnection *d = _inputs[4];

    _orComponents.setLink(1, a->_component, a->_pin);
    _orComponents.setLink(2, b->_component, b->_pin);
    _orComponents.setLink(5, c->_component, c->_pin);
    _orComponents.setLink(6, d->_component, d->_pin);
    _orComponents.setLink(8, _orComponents, 3);
    _orComponents.setLink(9, _orComponents, 4);
    if (pin == 5) {
        _outputs[pin] = _orComponents.compute(10, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
