/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** DFlipFlop.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_DFlipFlop_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_DFlipFlop_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"
    #include <array>

namespace nts {

    class DFlipFlop : public AComponent {
    public:
        DFlipFlop();
        ~DFlipFlop();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        nts::Tristate Q = nts::False;
        nts::Tristate lastClockState = nts::False;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_DFlipFlop_HPP
