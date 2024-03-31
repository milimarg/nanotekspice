/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4069.hpp (6x NOT Gates)
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4069_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4069_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"

namespace nts {

    class Component4069 : public AComponent {
    public:
        Component4069();
        ~Component4069();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::NOTComponent, 6> _notComponents;
        const std::array<size_t, 6> input = {1, 3, 5, 9, 11, 13};
        const std::array<size_t, 6> output = {2, 4, 6, 8, 10, 12};
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4069_HPP
