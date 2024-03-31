/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** DualFlipFlop.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_DUALFLIPFLOP_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_DUALFLIPFLOP_HPP
    #include "../base.hpp"
    #include "../advancedGates.hpp"

namespace nts {

    class DualFlipFlop : public AComponent {
    public:
        DualFlipFlop();
        ~DualFlipFlop();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::DFlipFlop, 2> _flipFlops;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_DUALFLIPFLOP_HPP
