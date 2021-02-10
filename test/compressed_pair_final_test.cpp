/*
Copyright 2018 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/config.hpp>
#include <boost/compressed_pair.hpp>
#include <boost/core/lightweight_test.hpp>

struct type1 {
    operator bool() const {
        return false;
    }
};

struct type2 final {
    operator bool() const {
        return false;
    }
};

template<class T1, class T2>
void test()
{
    boost::compressed_pair<T1, T2> p;
    BOOST_TEST(!p.first());
    BOOST_TEST(!p.second());
}

int main()
{
    test<type1, type2>();
    test<type2, type1>();
    test<type2, type2>();
    return boost::report_errors();
}
