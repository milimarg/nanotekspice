/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** NorComponent.cpp
*/

#include "../../include/elementaryComponents.hpp"

nts::NORComponent::NORComponent()
{
    notComponent.setLink(1, orComponent, 3);
}

nts::NORComponent::~NORComponent() {}

nts::Tristate nts::NORComponent::compute(std::size_t pin, size_t tick)
{
    PinConnection *a = _inputs[1];
    PinConnection *b = _inputs[2];

    if (!a || !b)
        return _outputs[pin];
    if (updateLinks()) {
        orComponent.setLink(1, a->_component, a->_pin);
        orComponent.setLink(2, b->_component, b->_pin);
    }
    _outputs[pin] = notComponent.compute(2, tick);
    return _outputs[pin];
}
