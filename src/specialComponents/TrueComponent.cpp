/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** TrueComponent.cpp
*/

#include "../../include/specialComponents.hpp"

nts::TrueComponent::TrueComponent()
{
    _outputs[1] = nts::True;
}

nts::TrueComponent::~TrueComponent() {}

nts::Tristate nts::TrueComponent::compute(std::size_t pin, size_t tick)
{
    (void)pin;
    (void)tick;
    return _outputs[1];
}

nts::Tristate nts::TrueComponent::getStatus()
{
    return _outputs[1];
}
