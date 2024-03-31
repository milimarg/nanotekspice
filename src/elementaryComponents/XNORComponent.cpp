/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** XnorComponent.cpp
*/

#include "../../include/elementaryComponents.hpp"

nts::XNORComponent::XNORComponent()
{
    notComponent.setLink(1, xorComponent, 3);
}

nts::XNORComponent::~XNORComponent() {}

nts::Tristate nts::XNORComponent::compute(std::size_t pin, size_t tick)
{
    PinConnection *a = _inputs[1];
    PinConnection *b = _inputs[2];

    if (updateLinks()) {
        xorComponent.setLink(1, a->_component, a->_pin);
        xorComponent.setLink(2, b->_component, b->_pin);
    }
    _outputs[pin] = notComponent.compute(2, tick);
    return _outputs[pin];
}
