#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include "F1_types_alias.hpp"
#include "packet_header.hpp"
#include "motion_packet.hpp"

namespace DataHandler{
  uint8 GetPacketId(char [constants::kMaxPacketSize]);
};

#endif
