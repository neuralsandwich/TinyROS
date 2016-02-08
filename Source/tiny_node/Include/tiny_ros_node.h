#ifndef TINY_ROS_NODE_H
#define TINY_ROS_NODE_H

namespace TinyROS {
class Node {
public:
  enum class ConnectionType {POSIX_IPC, IPV6};
  bool init(const ConnectionType);

private:
};
};

#endif
