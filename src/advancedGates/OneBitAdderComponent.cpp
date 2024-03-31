/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** OneBitAdderComponent.cpp
*/

#include "../../include/advancedGates.hpp"

nts::OneBitAdderComponent::OneBitAdderComponent()
{
    _xorComponents[1].setLink(1, _xorComponents[0], 3);
    _andComponents[0].setLink(2, _xorComponents[0], 3);
    _orComponent.setLink(1, _andComponents[0], 3);
    _orComponent.setLink(2, _andComponents[1], 3);
}

nts::OneBitAdderComponent::~OneBitAdderComponent() {}

nts::Tristate nts::OneBitAdderComponent::compute(std::size_t pin, size_t tick)
{
    PinConnection *a = _inputs[1];
    PinConnection *b = _inputs[2];
    PinConnection *c = _inputs[3];

    if (updateLinks()) {
        _xorComponents[0].setLink(1, a->_component, a->_pin);
        _xorComponents[0].setLink(2, b->_component, b->_pin);
        _xorComponents[1].setLink(2, c->_component, c->_pin);
        _andComponents[0].setLink(1, c->_component, c->_pin);
        _andComponents[1].setLink(1, a->_component, a->_pin);
        _andComponents[1].setLink(2, b->_component, b->_pin);
    }
    if (pin == 4) {
        _outputs[pin] = _xorComponents[1].compute(3, tick);
        return _outputs[pin];
    }
    if (pin == 5) {
        _outputs[pin] = _orComponent.compute(3, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
