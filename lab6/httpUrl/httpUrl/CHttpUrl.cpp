#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <regex> 
#include <boost/lexical_cast.hpp>
constexpr int MIN_PORT_VALUE = 1;
constexpr int MAX_PORT_VALUE = 65535;
constexpr unsigned short DEFAULT_HTTP_PORT_VALUE = 80;
constexpr unsigned short DEFAULT_HTTPS_PORT_VALUE = 443;

namespace
{
	Protocol ParseProtocol(std::string const & stringProtocol)
	{
		if (stringProtocol == "http")
		{
			return HTTP;
		}
		else if (stringProtocol == "https")
		{
			return HTTPS;
		}
		else
		{
			throw CUrlParsingError("Invalid protocol");
		}
	}

	unsigned short ParsePort(std::string const & stringPort, Protocol protocol)
	{
		unsigned short port = 0;
		if (stringPort.empty())
		{
			if (protocol == HTTP)
			{
				return DEFAULT_HTTP_PORT_VALUE;
			}
			else
			{
				return DEFAULT_HTTPS_PORT_VALUE;
			}
		}
		else
		{
			try
			{
				port = boost::lexical_cast<unsigned short>(stringPort);
			}
			catch (std::exception& e)
			{
				throw CUrlParsingError(e.what());
			}
			if ((port < MIN_PORT_VALUE) || (port > MAX_PORT_VALUE))
			{
				throw CUrlParsingError("Invalid port value");
			}
		}

		return port;
	}
}
CHttpUrl::CHttpUrl(std::string const& url)
	:m_url(url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Url is empty");
	}
	std::smatch matchedResult;
	std::regex urlRegex(R"(^(\w+):\/\/([^\s:\/]+)(?::(\d+))?(?:\/(\S*))?$)");

	if (!regex_search(url, matchedResult, urlRegex))
	{
		throw CUrlParsingError("Incorrect URL");
	}
	m_protocol = ParseProtocol(matchedResult[1]);
	m_domain = matchedResult[2];
	m_port = ParsePort(matchedResult[3], m_protocol);
	m_document = matchedResult[4];
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	: m_protocol(protocol)
	, m_document(document)
{
	if (!domain.empty())
	{
		m_domain = domain;
	}
	else
	{
		throw CUrlParsingError("Empty domain");
	}
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	: m_protocol(protocol)
	, m_document(document)
{
	if (!domain.empty())
	{
		m_domain = domain;
	}
	else
	{
		throw CUrlParsingError("Empty domain");
	}
	m_port = ParsePort(std::to_string(port), m_protocol);
}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}
