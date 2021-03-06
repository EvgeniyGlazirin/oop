// HTTP_URL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHttpUrl.h"


using namespace std;

string ProtocolToString(Protocol protocol)
{
	return (protocol == HTTP) ? "http"s : "https"s;
}

void PrintUrlInfo(CHttpUrl const& url)
{
	cout << "Protocol: " << ProtocolToString(url.GetProtocol()) << "\n";
	cout << "Domain: " << url.GetDomain() << "\n";
	cout << "Port: " << url.GetPort() << "\n";
	cout << "Document: " << url.GetDocument() << "\n";
	cout << "Url: " << url.GetURL() << "\n";
}

int main()
{
	vector<CHttpUrl> urlList;

	while (!cin.eof())
	{
		string inputLine;
		cin >> inputLine;
		try
		{
			CHttpUrl url(inputLine);
			urlList.push_back(url);
			PrintUrlInfo(urlList.back());
		}
		catch (const std::exception& e)
		{
			cout << e.what() << "\n";
		}
	}
	return 0;
}