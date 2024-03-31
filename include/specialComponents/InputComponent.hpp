/*
** EPITECH PROJECT, 2024
** Bootstrap_NanoTekSpice
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
    #define INPUTCOMPONENT_HPP_
    #include "../base/AComponent.hpp"

namespace nts {

    class InputComponent : public AComponent {
    public:
        InputComponent();
        ~InputComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        nts::Tristate getStatus() override;
        void setStatus(nts::Tristate tristate) override;
    protected:
    private:
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
