/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4040.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4040_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4040_HPP
    #include "../base.hpp"
    #include "../advancedGates.hpp"
    #include "../specialComponents.hpp"

namespace nts {

    class Component4040 : public AComponent {
    public:
        Component4040();
        ~Component4040();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::NOTComponent, 13> _notComponents;
        std::array<nts::DFlipFlop, 12> _flipFlops;
        const std::array<size_t, 12> output = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};
        std::unique_ptr <nts::IComponent> _true = std::make_unique<nts::TrueComponent>();
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4040_HPP
