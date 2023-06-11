//
// Created by david on 17-May-23.
//

#ifndef A89_EXCEPTIONS_H
#define A89_EXCEPTIONS_H

#endif //A89_EXCEPTIONS_H
#pragma once
#include <string>
#include <stdexcept>

class RepositoryException : public std::exception {
private:
    std::string message;
public:
    RepositoryException(const std::string& message) {
        this->message = message;
    }
    const char* what() const noexcept override {
        return this->message.c_str();
    }
};

class ValidationException : public std::exception {
private:
    std::string message;
public:
    ValidationException(const std::string& message) {
        this->message = message;
    }
    const char* what() const noexcept override {
        return this->message.c_str();
    }
};

class InputException : public std::exception {
private:
    std::string message;
public:
    InputException(const std::string& message) {
        this->message = message;
    }
    const char* what() const noexcept override {
        return this->message.c_str();
    }
};
