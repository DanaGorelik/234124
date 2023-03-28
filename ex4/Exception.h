#ifndef MTMCHKIN_H_EXCEPTION_H
#define MTMCHKIN_H_EXCEPTION_H
#include <exception>
#include "stdexcept"
#include <string>


class DeckFileNotFound : public std::runtime_error
{
public:
    explicit DeckFileNotFound(const std::string& what):
            std::runtime_error(what)
    {}
    ~DeckFileNotFound() override=default;
};


class DeckFileFormatError : public std::logic_error
{
    const int m_numRow;
public:
    DeckFileFormatError(const std::string& what, int numRow) :
            std::logic_error(what  + (std::to_string(numRow))), m_numRow(numRow)
    {}

    ~DeckFileFormatError() override=default;
};


class DeckFileInvalidSize : public std::logic_error
{
public:
    explicit DeckFileInvalidSize(const std::string& what):
            std::logic_error(what)
    {}
    ~DeckFileInvalidSize() override=default;

};


class RoundLimit : public std::runtime_error
{
public:
    explicit RoundLimit(const std::string& what) :
            std::runtime_error(what)
    {}
    ~RoundLimit() override=default;
};



#endif //MTMCHKIN_H_EXCEPTION_H