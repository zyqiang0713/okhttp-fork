//
// Created by Good_Pudge.
//

#include "../include/Headers.hpp"
#include "../util/string.hpp"
#include "../include/Exception.hpp"

using namespace ohf;

Headers::Builder &Headers::Builder::add(const std::string &line) {
    std::vector<std::string> nameValue = util::string::split(line, ": ");
    if (nameValue.size() != 2)
        throw Exception(Exception::Code::INVALID_HEADER_LINE, "Invalid header line: " + line);
    this->add(nameValue[0], nameValue[1]);
    return *this;
}

Headers::Builder &Headers::Builder::add(const std::string &name, const std::string &value) {
    namesAndValues.push_back(name);
    namesAndValues.push_back(value);
    return *this;
}

Headers Headers::Builder::build() {
    return Headers(this);
}

std::string Headers::Builder::get(std::string name) const {
    util::string::toLower(name);
    for (auto it = namesAndValues.begin(); it != namesAndValues.end(); it += 2) {
        std::string element = *it;
        util::string::toLower(element);
        if (name == element)
            return *(++it);

    }
    throw Exception(Exception::Code::HEADER_NOT_EXISTS, "Header not exists: " + name);
}

Headers::Builder &Headers::Builder::removeAll(std::string name) {
    util::string::toLower(name);
    for (auto it = namesAndValues.begin(); it != namesAndValues.end(); it += 2) {
        std::string element = *it;
        util::string::toLower(element);
        if (name == element) {
            namesAndValues.erase(it);
            namesAndValues.erase(++it);
            it -= 2;
        }
    }

    return *this;
}

Headers::Builder &Headers::Builder::set(const std::string &name, const std::string &value) {
    removeAll(name);
    namesAndValues.push_back(name);
    namesAndValues.push_back(value);
    return *this;
}
