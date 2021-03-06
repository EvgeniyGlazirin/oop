// httpUrlTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../httpUrl/CHttpUrl.h"
#include "../httpUrl/CUrlParsingError.h"

BOOST_AUTO_TEST_SUITE(class_CHttpUrl)

BOOST_AUTO_TEST_CASE(create_exception_error_if_url_is_empty)
{
	BOOST_CHECK_THROW(CHttpUrl(""), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(create_exception_error_if_url_has_wrong_protocol)
{
	BOOST_CHECK_THROW(CHttpUrl("httd://last.fm"), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(create_exception_if_port_is_incorrect)
{
	BOOST_CHECK_THROW(CHttpUrl("http://ab.ru:as6"), CUrlParsingError);
	BOOST_CHECK_THROW(CHttpUrl("http://ab.ru:0"), CUrlParsingError);
	CHttpUrl url2("http://last.fm:1");
	BOOST_CHECK(url2.GetPort() == 1);
	BOOST_CHECK_THROW(CHttpUrl("https://ya.ru:65536"), CUrlParsingError);
	CHttpUrl url("http://last.fm:65535");
	BOOST_CHECK(url.GetPort() == 65535);
}

BOOST_AUTO_TEST_CASE(create_url_with_domain_document_and_protocol)
{
	CHttpUrl url("ya.ru", "image.jpg", HTTPS);
	BOOST_CHECK(url.GetProtocol() == Protocol(HTTPS)
		&& url.GetDomain() == "ya.ru"
		&& url.GetDocument() == "image.jpg");
}

BOOST_AUTO_TEST_CASE(create_url_with_domain_document_protocol_and_port)
{
	CHttpUrl url("ya.ru", "image.jpg", HTTPS, 1234);
	BOOST_CHECK(url.GetProtocol() == Protocol(HTTPS)
		&& url.GetDomain() == "ya.ru"
		&& url.GetPort() == 1234
		&& url.GetDocument() == "image.jpg");
}

BOOST_AUTO_TEST_CASE(create_exception_if_domain_is_empty)
{
	BOOST_CHECK_THROW(CHttpUrl url("", "image.jpg", HTTPS), CUrlParsingError);
	BOOST_CHECK_THROW(CHttpUrl url("", "image.jpg", HTTPS, 1234), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(define_default_ports_for_protocols)
{
	CHttpUrl url("http://last.fm");
	BOOST_CHECK(url.GetPort() == 80);

	CHttpUrl url2("https://last.fm");
	BOOST_CHECK(url2.GetPort() == 443);
}

BOOST_AUTO_TEST_CASE(get_parameters_from_url)
{
	CHttpUrl url("https://last.ru:1234/index.html");
	BOOST_CHECK(url.GetProtocol() == Protocol(HTTPS)
		&& url.GetDomain() == "last.ru"
		&& url.GetPort() == 1234
		&& url.GetDocument() == "index.html");
}

BOOST_AUTO_TEST_CASE(get_url)
{
	CHttpUrl url("https://last.ru:1234/index.html");
	BOOST_CHECK(url.GetURL() == "https://last.ru:1234/index.html");
}

BOOST_AUTO_TEST_SUITE_END()

