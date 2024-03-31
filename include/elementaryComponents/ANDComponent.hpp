/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** ANDComponent
*/

#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_
    #include "../base/AComponent.hpp"

namespace nts
{
    class ANDComponent : public AComponent
    {
        public:
            ANDComponent();
            ~ANDComponent();

            nts::Tristate compute(std::size_t pin, size_t tick) override;

        protected:
        private:
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
