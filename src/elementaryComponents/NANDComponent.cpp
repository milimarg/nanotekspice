/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** NandComponent.cpp
*/

#include "../../include/elementaryComponents.hpp"
#include "../../include/specialComponents.hpp"

nts::NANDComponent::NANDComponent()
{
    notComponent.setLink(1, andComponent, 3);
}

nts::NANDComponent::~NANDComponent() {}

nts::Tristate nts::NANDComponent::compute(std::size_t pin, size_t tick)
{
    PinConnection *a = _inputs[1];
    PinConnection *b = _inputs[2];

    if (updateLinks()) {
        andComponent.setLink(1, a->_component, a->_pin);
        andComponent.setLink(2, b->_component, b->_pin);
    }
    _outputs[pin] = notComponent.compute(2, tick);
    return _outputs[pin];
}
