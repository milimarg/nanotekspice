/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** ANDComponent
*/

#include "../../include/elementaryComponents.hpp"

nts::ANDComponent::ANDComponent()
{
}

nts::ANDComponent::~ANDComponent()
{
}

nts::Tristate nts::ANDComponent::compute(std::size_t pin, size_t tick)
{
    if (tick == lastTickCheck)
        return _outputs[pin];
    lastTickCheck = tick;
    _outputs[pin] = GET_STATE(_inputs[1]) && GET_STATE(_inputs[2]);
    return _outputs[pin];
}
