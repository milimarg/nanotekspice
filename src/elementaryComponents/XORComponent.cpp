/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** XORComponent
*/

#include "../../include/elementaryComponents.hpp"

nts::XORComponent::XORComponent()
{
    andComponent.setLink(1, nandComponent, 3);
    andComponent.setLink(2, orComponent, 3);
}

nts::XORComponent::~XORComponent() {}

nts::Tristate nts::XORComponent::compute(std::size_t pin, size_t tick)
{
    PinConnection *a = _inputs[1];
    PinConnection *b = _inputs[2];

    if (updateLinks()) {
        nandComponent.setLink(1, a->_component, a->_pin);
        nandComponent.setLink(2, b->_component, b->_pin);
        orComponent.setLink(1, a->_component, a->_pin);
        orComponent.setLink(2, b->_component, b->_pin);
    }
    _outputs[pin] = andComponent.compute(3, tick);
    return _outputs[pin];
}
