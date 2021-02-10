
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/utility/identity_type

#include <boost/utility/identity_type.hpp>
#include <type_traits>

//[abstract
#define TMP_ASSERT(metafunction) \
    static_assert(metafunction::value)

template<typename T, bool b>
struct abstract {
    static const bool value = b;
    virtual void f(T const& x) = 0;     // Pure virtual function.
};

TMP_ASSERT(
    std::remove_reference<            // Add and remove
        BOOST_IDENTITY_TYPE((           // reference for
            std::add_lvalue_reference<       // abstract type.
                abstract<int, true>
            >::type
        ))
    >::type
);
//]

int main() { return 0; }

