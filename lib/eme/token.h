#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_TOKEN_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_TOKEN_H


namespace reclue {

    class Token final {
    private:
        char m_symbol;

    public:
        explicit Token(char symbol);

        Token();
        Token(const Token& token);
        Token(Token&& token) noexcept;
        Token& operator=(const Token& token);
        Token& operator=(Token&& token) noexcept;
        ~Token();

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
        bool IsUnaryOperator(const Token& prev) const;
        bool IsBinaryOperator(const Token& prev) const;

        bool IsCorrect() const;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_TOKEN_H
