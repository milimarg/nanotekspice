/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** TrueComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_TRUECOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_TRUECOMPONENT_HPP
    #include "../base/AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
    public:
        TrueComponent();
        ~TrueComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        nts::Tristate getStatus() override;
    protected:
    private:
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_TRUECOMPONENT_HPP
