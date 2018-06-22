#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"


CHttpUrl::CHttpUrl(std::string const& url)
	:m_url(url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Url is empty");
	}
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


/*
CHttpUrl::CHttpUrl()
{
}


CHttpUrl::~CHttpUrl()
{
}
*/