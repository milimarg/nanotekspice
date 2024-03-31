/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4514.cpp
*/

#include "../../include/advancedGates.hpp"

nts::Component4514::Component4514() {}

nts::Component4514::~Component4514() {}

nts::Tristate nts::Component4514::compute(size_t pin, size_t tick)
{
    PinConnection *strobe = _inputs[1];
    PinConnection *inhibit = _inputs[23];
    PinConnection *temp = nullptr;

    _inhibitNot.setLink(1, strobe->_component, strobe->_pin);
    demultiplexer.setLink(1, _inhibitNot, 2);
    for (size_t i = 0; i < inputsPin.size(); i += 1) {
        temp = _inputs[inputsPin[i]];
        demultiplexer.setLink(i + 2, temp->_component, temp->_pin);
    }
    demultiplexer.setLink(6, inhibit->_component, inhibit->_pin);
    demultiplexer.setLink(7, _falseComponent, 1);
    auto it = std::find(outputsPin.begin(), outputsPin.end(), pin);
    if (it != outputsPin.end()) {
        _outputs[pin] = demultiplexer.compute(8 + it - outputsPin.begin(), tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
