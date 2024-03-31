/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** NOTComponent
*/

#ifndef NOTCOMPONENT_HPP_
    #define NOTCOMPONENT_HPP_
    #include "../base/AComponent.hpp"

namespace nts
{
    class NOTComponent : public AComponent
    {
        public:
            NOTComponent();
            ~NOTComponent();

            nts::Tristate compute(std::size_t pin, size_t tick) override;

        protected:
        private:
    };
}

#endif /* !NOTCOMPONENT_HPP_ */
