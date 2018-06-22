#pragma once

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(std::string const & message);
private:
	std::string m_message;
};