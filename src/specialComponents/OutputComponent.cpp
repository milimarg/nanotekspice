/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** OutputComponent.cpp
*/

#include "../../include/specialComponents.hpp"

nts::OutputComponent::OutputComponent()
{
    _outputs[1] = nts::Undefined;
}

nts::OutputComponent::~OutputComponent() {}

nts::Tristate nts::OutputComponent::compute(std::size_t pin, size_t tick)
{
    (void)tick;
    _outputs[pin] = GET_STATE(_inputs[pin]);
    return _outputs[pin];
}

nts::Tristate nts::OutputComponent::getStatus()
{
    return _outputs[1];
}