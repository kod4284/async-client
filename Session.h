#pragma once
#include <boost/predef.h>
#include <boost/asio.hpp>

#include <mutex>
#include <iostream>

using namespace boost;

typedef void(*Callback) (unsigned int request_id, const std::string& response, const system::error_code& ec);

struct Session {
	Session(asio::io_service& ios,
		const std::string& raw_ip_address,
		unsigned short port_num,
		const std::string& request,
		unsigned int id,
		Callback callback);

		asio::ip::tcp::socket m_sock;
		asio::ip::tcp::endpoint m_ep;
		std::string m_request;

		asio::streambuf m_response_buf;
		std::string m_response;

		system::error_code m_ec;

		unsigned int m_id;

		Callback m_callback;

		bool m_was_cancelled;
		std::mutex m_cancel_guard;
};
