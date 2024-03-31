/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4081.hpp (4x AND Gates)
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4081_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4081_HPP
    #include "../base.hpp"
    #include "../elementaryComponents/ANDComponent.hpp"

namespace nts {

    class Component4081 : public AComponent {
    public:
        Component4081();
        ~Component4081();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::ANDComponent, 4> _andComponents;
        const std::array<size_t, 4> firstInputPins = {1, 5, 8, 12};
        const std::array<size_t, 4> output = {3, 4, 10, 11};
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4081_HPP
