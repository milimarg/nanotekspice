/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Circuit
*/

#include "../../include/circuit.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

std::unique_ptr<nts::IComponent> createComponent(const std::string &type)
{
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> IComponentFactory
    {
        // Special components
        {"clock", []() { return std::make_unique<nts::ClockComponent>(); }},
        {"input", []() { return std::make_unique<nts::InputComponent>(); }},
        {"output", []() { return std::make_unique<nts::OutputComponent>(); }},
        {"true", []() { return std::make_unique<nts::TrueComponent>(); }},
        {"false", []() { return std::make_unique<nts::FalseComponent>(); }},
        // Elementary components
        {"and", []() { return std::make_unique<nts::ANDComponent>(); }},
        {"or", []() { return std::make_unique<nts::ORComponent>(); }},
        {"xor", []() { return std::make_unique<nts::XORComponent>(); }},
        {"not", []() { return std::make_unique<nts::NOTComponent>(); }},
        // Gates components
        {"4001", []() { return std::make_unique<nts::Component4001>(); }},
        {"4011", []() { return std::make_unique<nts::Component4011>(); }},
        {"4030", []() { return std::make_unique<nts::Component4030>(); }},
        {"4071", []() { return std::make_unique<nts::Component4071>(); }},
        {"4069", []() { return std::make_unique<nts::Component4069>(); }},
        {"4071", []() { return std::make_unique<nts::Component4071>(); }},
        {"4081", []() { return std::make_unique<nts::Component4081>(); }},
        // Advanced components
        {"4008", []() { return std::make_unique<nts::FourBitAdderComponent>(); }},
        {"4013", []() { return std::make_unique<nts::DualFlipFlop>(); }},
        {"4017", []() { return std::make_unique<nts::Component4017>(); }},
        {"4040", []() { return std::make_unique<nts::Component4040>(); }},
        {"4094", []() { return std::make_unique<nts::Component4094>(); }},
        {"4512", []() { return std::make_unique<nts::Component4512>(); }},
        {"4514", []() { return std::make_unique<nts::Component4514>(); }},
        // {"4801",}, ram
        // {"2716",}, rom
        {"logger", []() { return std::make_unique<nts::Logger>(); }},
    };
    if (IComponentFactory.find(type) == IComponentFactory.end())
        throw Circuit::Error("Bad chipset type");
    return IComponentFactory[type]();
}

void Circuit::addComponent(std::string &type, std::string &name)
{
    auto first = _components.find(name);
    if (first != _components.end())
        throw Error("Two components have the same name");
    _components[name] = createComponent(type);
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &Circuit::getComponents()
{
    return _components;
}

void Circuit::addInput(std::string &type, std::string &name)
{
    auto first = _inputs.find(name);
    if (first != _inputs.end())
        throw Error("Two Inputs have the same name");
    _inputs[name] = createComponent(type);
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &Circuit::getInput()
{
    return _inputs;
}

void Circuit::addOutput(std::string &type, std::string &name)
{
    auto first = _outputs.find(name);
    if (first != _outputs.end())
        throw Error("Two Outputs have the same name");
    _outputs[name] = createComponent(type);
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &Circuit::getOutput()
{
    return _outputs;
}

void Circuit::setLink(std::string &component, size_t pin, std::string &otherComponent, size_t otherPin)
{
    auto first = _components.find(component);
    if (first == _components.end()) {
        first = _inputs.find(component);
        if (first == _inputs.end()) {
            first = _outputs.find(component);
            if (first == _outputs.end())
                throw Error("First element non existing when linking");
        }
    }
    auto second = _components.find(otherComponent);
    if (second == _components.end()) {
        second = _inputs.find(otherComponent);
        if (second == _inputs.end()) {
            second = _outputs.find(otherComponent);
            if (second == _outputs.end())
                throw Error("Second element non existing when linking");
        }
    }
    first->second->setLink(pin, *second->second, otherPin);
    second->second->setLink(otherPin, *first->second, pin);
}

void Circuit::checkEmpty()
{
    if (_components.size() == 0 && _inputs.size() == 0) {
        std::cout << _components.size() << " & " << _inputs.size() << std::endl;
        throw Error("There is no chipset in the circuit");
    }
    if (_outputs.size() == 0)
        throw Error("There is no output in the circuit");
}

nts::EightBitBus &Circuit::getBus()
{
    return bus;
}

std::ostream &operator<<(std::ostream &os, Circuit &circuit)
{
    (void)circuit;
    os << "input(s):" << std::endl;
    for (const auto& pair : circuit.getInput()) {
        const std::string& name = pair.first;
        nts::IComponent& component = *(pair.second);
        os << "  " << name << ": ";
        os << component.getStatus();
        os << std::endl;
    }
    os << "output(s):";
    for (const auto& pair : circuit.getOutput()) {
        if (pair.first == "logger")
            continue;
        os << std::endl;
        const std::string& name = pair.first;
        nts::IComponent& component = *(pair.second);
        os << "  " << name << ": ";
        os << component.getStatus();
    }
    return os;
}
