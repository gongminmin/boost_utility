/*
Copyright 2020 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/

#include <boost/config.hpp>
#if (!defined(BOOST_MSVC) || (BOOST_MSVC >= 1922))
#include <boost/operators.hpp>

namespace {

class Value
    : boost::operators<Value> {
public:
    BOOST_OPERATORS_CONSTEXPR explicit Value(int v)
        : v_(v) { }

    BOOST_OPERATORS_CONSTEXPR bool
    operator<(const Value& x) const {
        return v_ < x.v_;
    }

    BOOST_OPERATORS_CONSTEXPR bool
    operator==(const Value& x) const {
        return v_ == x.v_;
    }

private:
    int v_;
};

} // namespace

static_assert(!static_cast<bool>(Value(1) == Value(2)));
static_assert(Value(1) != Value(2));
static_assert(Value(1) < Value(2));
static_assert(Value(1) <= Value(2));
static_assert(!static_cast<bool>(Value(1) > Value(2)));
static_assert(!static_cast<bool>(Value(1) >= Value(2)));

static_assert(!static_cast<bool>(Value(2) == Value(1)));
static_assert(Value(2) != Value(1));
static_assert(!static_cast<bool>(Value(2) < Value(1)));
static_assert(!static_cast<bool>(Value(2) <= Value(1)));
static_assert(Value(2) >  Value(1));
static_assert(Value(2) >= Value(1));

static_assert(Value(1) == Value(1));
static_assert(!static_cast<bool>(Value(1) != Value(1)));
static_assert(!static_cast<bool>(Value(1) < Value(1)));
static_assert(Value(1) <= Value(1));
static_assert(!static_cast<bool>(Value(1) > Value(1)));
static_assert(Value(1) >= Value(1));
#endif
