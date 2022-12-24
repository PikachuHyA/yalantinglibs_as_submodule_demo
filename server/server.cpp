#include "coro_rpc/coro_rpc_server.hpp"
#include "service.h"
void hi() {
  std::cout << "call hi" << std::endl;
}
int main() {
  coro_rpc::register_handler<hi>();
  coro_rpc::coro_rpc_server server(2, 8801);
  auto ec = server.start();
  return ec == std::errc{};
}