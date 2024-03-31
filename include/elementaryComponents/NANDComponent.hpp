/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** NandComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_NANDCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_NANDCOMPONENT_HPP
    #include "../base/AComponent.hpp"
    #include "../../include/elementaryComponents/ANDComponent.hpp"
    #include "../../include/elementaryComponents/NOTComponent.hpp"

namespace nts {

    class NANDComponent : public AComponent
    {
    public:
        NANDComponent();
        ~NANDComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        nts::ANDComponent andComponent;
        nts::NOTComponent notComponent;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_NANDCOMPONENT_HPP
