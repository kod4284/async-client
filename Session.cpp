#include "Session.h";

Session::Session(asio::io_service& ios,
	const std::string& raw_ip_address,
	unsigned short port_num,
	const std::string& request,
	unsigned int id,
	Callback callback) :
	m_sock(ios),
	m_ep(asio::ip::address::from_string(raw_ip_address),
		port_num),
	m_request(request),
	m_id(id),
	m_callback(callback),
	m_was_cancelled(false) {}