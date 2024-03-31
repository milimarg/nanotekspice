/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4512.cpp
*/

#include "../../include/advancedGates/Component4512.hpp"

nts::Component4512::Component4512()
{
    _fourOrComponents[0].setLink(1, _andComponents[0], 5);
    _fourOrComponents[0].setLink(2, _andComponents[1], 5);
    _fourOrComponents[0].setLink(3, _andComponents[2], 5);
    _fourOrComponents[0].setLink(4, _andComponents[3], 5);
    _fourOrComponents[1].setLink(1, _andComponents[4], 5);
    _fourOrComponents[1].setLink(2, _andComponents[5], 5);
    _fourOrComponents[1].setLink(3, _andComponents[6], 5);
    _fourOrComponents[1].setLink(4, _andComponents[7], 5);
    _orComponent.setLink(1, _fourOrComponents[0], 5);
    _orComponent.setLink(2, _fourOrComponents[1], 5);
}

nts::Component4512::~Component4512() {}

nts::Tristate nts::Component4512::compute(size_t pin, size_t tick)
{
    PinConnection *inhibit = _inputs[10];
    PinConnection *enable = _inputs[15];
    PinConnection *a = _inputs[11];
    PinConnection *b = _inputs[12];
    PinConnection *c = _inputs[13];
    nts::Tristate enableState = GET_STATE(enable);

    if (updateLinks()) {
        inhibitNot.setLink(1, inhibit->_component, inhibit->_pin);
        for (size_t i = 0; i < 3; i++)
            _notComponents[i].setLink(1, _inputs[11 + i]->_component, _inputs[11 + i]->_pin);
        for (size_t i = 0; i < _andComponents.size(); i++)
            _andComponents[i].setLink(1, _inputs[inputPins[i]]->_component, _inputs[inputPins[i]]->_pin);
        _andComponents[0].setLink(2, _notComponents[0], 2);
        _andComponents[0].setLink(3, _notComponents[1], 2);
        _andComponents[0].setLink(4, _notComponents[2], 2);

        _andComponents[1].setLink(2, a->_component, a->_pin);
        _andComponents[1].setLink(3, _notComponents[1], 2);
        _andComponents[1].setLink(4, _notComponents[2], 2);

        _andComponents[2].setLink(2, b->_component, b->_pin);
        _andComponents[2].setLink(3, _notComponents[0], 2);
        _andComponents[2].setLink(4, _notComponents[2], 2);

        _andComponents[3].setLink(2, a->_component, a->_pin);
        _andComponents[3].setLink(3, b->_component, b->_pin);
        _andComponents[3].setLink(4, _notComponents[2], 2);

        _andComponents[4].setLink(2, _notComponents[0], 2);
        _andComponents[4].setLink(3, _notComponents[1], 2);
        _andComponents[4].setLink(4, c->_component, c->_pin);

        _andComponents[5].setLink(2, a->_component, a->_pin);
        _andComponents[5].setLink(3, _notComponents[1], 2);
        _andComponents[5].setLink(4, c->_component, c->_pin);

        _andComponents[6].setLink(2, _notComponents[0], 2);
        _andComponents[6].setLink(3, b->_component, b->_pin);
        _andComponents[6].setLink(4, c->_component, c->_pin);

        _andComponents[7].setLink(2, a->_component, a->_pin);
        _andComponents[7].setLink(3, b->_component, b->_pin);
        _andComponents[7].setLink(4, c->_component, c->_pin);

        _andComponent.setLink(1, _orComponent, 3);
        _andComponent.setLink(2, inhibitNot, 2);
    }
    if (pin == 14) {
        _outputs[pin] = enableState == nts::False ? _andComponent.compute(3, tick) : nts::Undefined;
        return _outputs[pin];
    }
    return nts::Undefined;
}
