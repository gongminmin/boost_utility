
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/utility/identity_type

#include <boost/utility/identity_type.hpp>
#include <boost/type_traits/is_const.hpp>
#include <map>

//[paren
#define TMP_ASSERT_PAREN(parenthesized_metafunction) \
    /* use `BOOST_IDENTITY_TYPE` in macro definition instead of invocation */ \
    static_assert(BOOST_IDENTITY_TYPE(parenthesized_metafunction)::value)

#define TMP_ASSERT(metafunction) \
    static_assert(metafunction::value)

// Specify only extra parenthesis `((...))`.
TMP_ASSERT_PAREN((boost::is_const<std::map<int, char> const>));

// Specify both the extra parenthesis `((...))` and `BOOST_IDENTITY_TYPE` macro.
TMP_ASSERT(BOOST_IDENTITY_TYPE((boost::is_const<std::map<int, char> const>)));
//]

//[paren_always
TMP_ASSERT_PAREN((boost::is_const<int const>)); // Always extra `((...))`.

TMP_ASSERT(boost::is_const<int const>); // No extra `((...))` and no macro.
//]

int main() { return 0; }

