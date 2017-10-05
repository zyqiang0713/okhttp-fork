//
// Created by Good_Pudge.
//

#include "../include/Cookie.hpp"

namespace ohf {
    Cookie::Builder::Builder() :
            m_expiresAt(-1),
            m_hostOnly(false),
            m_httpOnly(false),
            m_secure(false),
            m_persistent(false) {};

    Cookie Cookie::Builder::build() {
        return {this};
    }

    Cookie::Builder &Cookie::Builder::domain(const std::string &domain) {
        m_domain = domain;
        return *this;
    }

    Cookie::Builder &Cookie::Builder::expiresAt(time_t expiresAt) {
        m_expiresAt = expiresAt;
        return *this;
    }

    Cookie::Builder &Cookie::Builder::hostOnlyDomain(const std::string &domain) {
        m_domain = domain;
        m_httpOnly = true;
        return *this;
    }

    Cookie::Builder &Cookie::Builder::httpOnly() {
        m_httpOnly = true;
        return *this;
    }

    Cookie::Builder &Cookie::Builder::name(const std::string &name) {
        m_name = name;
        return *this;
    }

    Cookie::Builder &Cookie::Builder::path(const std::string &path) {
        m_path = path;
        return *this;
    }

    Cookie::Builder &Cookie::Builder::secure() {
        m_secure = true;
        return *this;
    }

    Cookie::Builder &Cookie::Builder::value(const std::string &value) {
        m_value = value;
        return *this;
    }
}