/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** NorComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_NORCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_NORCOMPONENT_HPP
    #include "ORComponent.hpp"
    #include "NOTComponent.hpp"
    #include "../base/IComponent.hpp"

namespace nts {
    class NORComponent : public AComponent {
    public:
        NORComponent();
        ~NORComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        nts::ORComponent orComponent;
        nts::NOTComponent notComponent;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_NORCOMPONENT_HPP
