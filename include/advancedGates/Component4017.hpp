/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4017.hpp (10-bit Johnson Decade)
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4017_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4017_HPP
    #include "../base.hpp"
    #include "../advancedGates.hpp"

namespace nts {

    class Component4017 : public AComponent {
    public:
        Component4017();
        ~Component4017();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::Tristate, 10> _bits;
        size_t currentBit = 0;
        nts::Tristate lastClockState = nts::False;
        const std::array<size_t, 10> output = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11};
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4017_HPP
