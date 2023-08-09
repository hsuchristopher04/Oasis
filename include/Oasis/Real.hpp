//
// Created by Matthew McCall on 7/2/23.
//

#ifndef OASIS_REAL_HPP
#define OASIS_REAL_HPP

#include "LeafExpression.hpp"

namespace Oasis {

class Real : public LeafExpression<Real> {
public:
    Real() = default;
    Real(const Real& other) = default;

    explicit Real(double value);

    EXPRESSION_TYPE(Real)
    EXPRESSION_CATEGORY(0)

    [[nodiscard]] auto GetValue() const -> double;

    [[nodiscard]] auto ToString() const -> std::string final;

    static auto Specialize(const Expression& other) -> std::unique_ptr<Real>;
    static auto Specialize(const Expression& other, tf::Subflow& subflow) -> std::unique_ptr<Real>;

    auto operator=(const Real& other) -> Real& = default;

private:
    double value {};
};

} // Oasis

#endif // OASIS_REAL_HPP