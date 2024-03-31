/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** ORComponent
*/

#ifndef ORCOMPONENT_HPP_
    #define ORCOMPONENT_HPP_
    #include "../base/AComponent.hpp"

namespace nts
{
    class ORComponent : public AComponent
    {
        public:
            ORComponent();
            ~ORComponent();

            nts::Tristate compute(std::size_t pin, size_t tick) override;

        protected:
        private:
    };
}

#endif /* !ORCOMPONENT_HPP_ */
