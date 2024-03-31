/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** XORComponent
*/

#ifndef XORCOMPONENT_HPP_
    #define XORCOMPONENT_HPP_
    #include "../base/AComponent.hpp"
    #include "../elementaryComponents/ANDComponent.hpp"
    #include "../elementaryComponents/NANDComponent.hpp"
    #include "../elementaryComponents/ORComponent.hpp"

namespace nts
{
    class XORComponent : public AComponent
    {
        public:
            XORComponent();
            ~XORComponent();

            nts::Tristate compute(std::size_t pin, size_t tick) override;

        protected:
        private:
            nts::NANDComponent nandComponent;
            nts::ORComponent orComponent;
            nts::ANDComponent andComponent;
    };
}

#endif /* !XORCOMPONENT_HPP_ */
