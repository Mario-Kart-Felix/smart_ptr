/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_SMART_PTR_MAKE_UNIQUE_OBJECT_HPP
#define BOOST_SMART_PTR_MAKE_UNIQUE_OBJECT_HPP

#include <boost/config.hpp>
#include <boost/smart_ptr/detail/up_if_not_array.hpp>
#include <utility>

namespace boost {
    template<typename T>
    inline typename boost::detail::up_if_not_array<T>::type
    make_unique() {
        return std::unique_ptr<T>(new T());
    }

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template<typename T, typename... Args>
    inline typename boost::detail::up_if_not_array<T>::type
    make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
#endif
    
    template<typename T>
    inline typename boost::detail::up_if_not_array<T>::type
    make_unique(T&& value) {
        return std::unique_ptr<T>(new T(std::move(value)));
    }

    template<typename T>
    inline typename boost::detail::up_if_not_array<T>::type
    make_unique_noinit() {
        return std::unique_ptr<T>(new T);
    }
}

#endif
