/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4514.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4514_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4514_HPP
    #include "../base.hpp"
    #include "../specialComponents.hpp"
    #include "../advancedGates/SixteenInputDemultiplexer.hpp"

namespace nts {
    class Component4514 : public AComponent {
    public:
        Component4514();
        ~Component4514();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        const std::array<size_t, 4> inputsPin = {2, 3, 21, 22};
        const std::array<size_t, 16> outputsPin = {11, 9, 10, 8, 7, 6, 5, 4, 18,
                                             17, 20, 19, 14, 13, 16, 15};
        nts::FalseComponent _falseComponent;
        nts::SixteenInputDemultiplexer demultiplexer;
        nts::NOTComponent _inhibitNot;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4514_HPP
