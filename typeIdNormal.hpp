#pragma once

#include <optional>
#include <string>
#include <typeinfo>
#include <fmt/core.h>
#include <cxxabi.h>

struct demangler
{
protected:
    static auto demangle(const char*) -> std::optional<std::string>;

    std::optional<std::string> demangled;
};

auto demangler::demangle(const char* mangled) -> std::optional<std::string>
{
    int status = 0;
    std::string demangled {};
    char* tmp = abi::__cxa_demangle(mangled, 0, 0, &status);
    switch (status)
    {
    case 0:
        demangled = std::string(tmp);
        free(tmp);
        return demangled;
    case -1:
        fmt::print("Memory allocation failed for {}", mangled);
        return {};
    case -2:
        fmt::print("is an invalid name under ABI. {}", mangled);
        return {};
    default:
        fmt::print("Fatal error occured during demangling", mangled);
        return {};
    }
}

struct specialTypeid final : private demangler
{
    template<typename T>
    specialTypeid(T &&t) { this->demangled = demangle(typeid(t).name()); };

    std::string name() { return this->demangled.value_or("(null)"); }

    std::string name() const { return this->demangled.value_or("(null)"); }

    friend std::ostream &operator<<(std::ostream &os, const specialTypeid &id) { return os << id.name(); }
};