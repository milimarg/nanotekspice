/*
** EPITECH PROJECT, 2024
** Bootstrap_NanoTekSpice
** File description:
** AComponent
*/

#include "../../include/base.hpp"

AComponent::AComponent()
{
}

AComponent::~AComponent()
{
    for (auto& pair : _inputs)
        delete pair.second;
}

void AComponent::simulate(std::size_t tick)
{
    (void)tick;
    return;
}

void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        _inputs[pin] = new PinConnection(other, otherPin);
}

nts::Tristate AComponent::getStatus()
{
    return nts::True;
}

void AComponent::setStatus(nts::Tristate tristate)
{
    (void)tristate;
    std::cerr << "can't set the status of this element" << std::endl;
    return;
}

bool AComponent::updateLinks()
{
    bool update = false;

    if (_lastInputs.size() != _inputs.size()) {
        for (auto &element : _inputs)
            _lastInputs.push_back(element.second);
        return true;
    }
    for (size_t i = 0; i < _lastInputs.size(); i++) {
        if (_inputs[i + 1] != _lastInputs[i]) {
            _lastInputs[i] = _inputs[i + 1];
            update = true;
        }
    }
    return update;
}

namespace nts
{
    Tristate operator&&(Tristate lhs, Tristate rhs)
    {
        if ((lhs == Undefined && rhs == True) ||
            (lhs == True && rhs == Undefined))
            return Undefined;
        if (lhs == Undefined && rhs == Undefined)
            return Undefined;
        if (lhs == True && rhs == True)
            return True;
        return False;
    }

    Tristate operator||(Tristate lhs, Tristate rhs)
    {
        if (lhs == True || rhs == True)
            return True;
        if (lhs == False && rhs == False)
            return False;
        return Undefined;
    };

    Tristate operator!(Tristate lhs)
    {
        if (lhs == Undefined)
            return Undefined;
        return lhs == True ? False : True;
    }
}

std::ostream &operator<<(std::ostream &s, const nts::Tristate &v)
{
    if (v == nts::Undefined)
        return s << "U";
    return v == nts::False ? s << "0" : s << "1";
}