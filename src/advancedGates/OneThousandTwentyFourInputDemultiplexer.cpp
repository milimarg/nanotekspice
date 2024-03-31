/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** OneThousandTwentyFourInputDemultiplexer.cpp
*/

#include "../../include/advancedGates/OneThousandTwentyFourInputDemultiplexer.hpp"

nts::OneThousandTwentyFourInputDemultiplexer::OneThousandTwentyFourInputDemultiplexer() {}

nts::OneThousandTwentyFourInputDemultiplexer::~OneThousandTwentyFourInputDemultiplexer() {}

nts::Tristate nts::OneThousandTwentyFourInputDemultiplexer::compute(size_t pin, size_t tick)
{
    PinConnection *data = _inputs[1];
    PinConnection *inhibit = _inputs[12];
    nts::Tristate enableState = GET_STATE(_inputs[13]);
    PinConnection *temp = nullptr;

    if (updateLinks()) {
        _inhibitNot.setLink(1, inhibit->_component, inhibit->_pin);
        for (size_t i = 0; i < _notComponents.size(); i += 1)
            _notComponents[i].setLink(1, _inputs[lastInputPin - i]->_component, _inputs[lastInputPin - i]->_pin);
        for (size_t i = 0; i < _andComponents.size(); i += 1) {
            _andComponents[i].setLink(11, data->_component, data->_pin);
            _inhibitAnds[i].setLink(1, _inhibitNot, 2);
            _inhibitAnds[i].setLink(2, _andComponents[i], 11);
        }
        for (size_t i = 0; i < _andComponents.size(); i += 1) {
            std::bitset<10> bitSet(i);
            for (size_t j = 0; j < bitSet.size(); j += 1) {
                if (!bitSet.test(j)) {
                    _andComponents[i].setLink(bitSet.size() - j, _notComponents[j], 2);
                } else {
                    temp = _inputs[lastInputPin - j];
                    _andComponents[i].setLink(bitSet.size() - j, temp->_component, temp->_pin);
                }
            }
        }
    }
    if (pin >= 14 && pin <= 1037) {
        _outputs[pin] = enableState == nts::False ? _inhibitAnds[pin - 14].compute(3, tick) : nts::Undefined;
        return _outputs[pin];
    }
    return nts::Undefined;
}
