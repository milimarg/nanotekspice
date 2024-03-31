/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4094.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4094_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4094_HPP
    #include "../base.hpp"
    #include "../advancedGates.hpp"
    #include "../specialComponents.hpp"

namespace nts {

    class Component4094 : public AComponent {
    public:
        Component4094();
        ~Component4094();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::DFlipFlop, 8> _flipFlops;
        std::array<nts::NOTComponent, 4> _inputsNot;
        std::array<nts::NOTComponent, 8> _outputsNot;
        const std::array<size_t, 8> outputs = {4, 5, 6, 7, 14, 13, 12, 11};
        nts::FalseComponent falseComponent;
        nts::NOTComponent _notComponent;
        std::array<nts::ANDComponent, 8> _andComponents;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4094_HPP
