/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** FalseComponent.cpp
*/

#include "../../include/specialComponents.hpp"

nts::FalseComponent::FalseComponent()
{
    _outputs[1] = nts::False;
}

nts::FalseComponent::~FalseComponent() {}

nts::Tristate nts::FalseComponent::compute(std::size_t pin, size_t tick)
{
    (void)pin;
    (void)tick;
    return _outputs[1];
}

nts::Tristate nts::FalseComponent::getStatus()
{
    return _outputs[1];
}
