/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** SixteenInputDemultiplexer.cpp
*/

#include "../../include/advancedGates/SixteenInputDemultiplexer.hpp"

nts::SixteenInputDemultiplexer::SixteenInputDemultiplexer() {}

nts::SixteenInputDemultiplexer::~SixteenInputDemultiplexer() {}

nts::Tristate nts::SixteenInputDemultiplexer::compute(size_t pin, size_t tick)
{
    PinConnection *data = _inputs[1];
    PinConnection *inhibit = _inputs[6];
    nts::Tristate enableState = GET_STATE(_inputs[7]);

    if (updateLinks()) {
        _inhibitNot.setLink(1, inhibit->_component, inhibit->_pin);
        for (size_t i = 0; i < _notComponents.size(); i += 1)
            _notComponents[i].setLink(1, _inputs[lastInputPin - i]->_component, _inputs[lastInputPin - i]->_pin);
        for (size_t i = 0; i < _andComponents.size(); i += 1) {
            _andComponents[i].setLink(1, data->_component, data->_pin);
            _outputAnds[i].setLink(1, _andComponents[i], 5);
            _inhibitAnds[i].setLink(1, _inhibitNot, 2);
            _inhibitAnds[i].setLink(2, _outputAnds[i], 3);
        }
        for (size_t i = 0; i < _andComponents.size(); i += 1) {
            std::bitset<4> bitSet(i);
            for (size_t j = 0; j < bitSet.size(); j += 1)
                setInsideAndGates(bitSet, i, j);
        }
    }
    if (pin >= 8 && pin <= 23) {
        _outputs[pin] = enableState == nts::False ? _inhibitAnds[pin - 8].compute(3, tick) : nts::Undefined;
        return _outputs[pin];
    }
    return nts::Undefined;
}

void nts::SixteenInputDemultiplexer::setInsideAndGates(std::bitset<4> &bitSet,
                                                       size_t i, size_t j)
{
    PinConnection *test = _inputs[lastInputPin - j];
    size_t index = j == 0 ? 2 : bitSet.size() - j + 1;

    if (!bitSet.test(j)) {
        if (j == 0)
            _outputAnds[i].setLink(index, _notComponents[j], 2);
        else
            _andComponents[i].setLink(index, _notComponents[j], 2);
    } else {
        if (j == 0)
            _outputAnds[i].setLink(index, test->_component, test->_pin);
        else
            _andComponents[i].setLink(index, test->_component, test->_pin);
    }
}
