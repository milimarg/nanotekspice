/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** ClockComponent.hpp
*/
#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_CLOCKCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_CLOCKCOMPONENT_HPP
    #include "../base/AComponent.hpp"

namespace nts {
    class ClockComponent : public AComponent {
    public:
        ClockComponent();
        ~ClockComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        nts::Tristate getStatus() override;
        void setStatus(nts::Tristate tristate) override;
    protected:
    private:
        bool _didSet;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_CLOCKCOMPONENT_HPP
