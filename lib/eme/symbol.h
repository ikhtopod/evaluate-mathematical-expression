#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_SYMBOL_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_SYMBOL_H


namespace reclue {

    class Symbol final {
    private:
        char m_symbol;

    public:
        explicit Symbol(char symbol);

        Symbol();
        Symbol(const Symbol& symbol);
        Symbol(Symbol&& symbol) noexcept;
        Symbol& operator=(const Symbol& symbol);
        Symbol& operator=(Symbol&& symbol) noexcept;
        ~Symbol();

    public:
        char GetSymbol() const;

    public:
        bool IsDigit() const;
        bool IsNumberSeparator() const;
        bool IsNumber() const;

        bool IsBeginScope() const;
        bool IsEndScope() const;

        bool IsSubtract() const;
        bool IsAddition() const;
        bool IsDivide() const;
        bool IsMultiply() const;

        bool IsNegative() const;

        bool IsOperator() const;
        bool IsUnaryOperator(const Symbol& prev) const;
        bool IsBinaryOperator(const Symbol& prev) const;

        bool IsCorrect() const;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_SYMBOL_H
