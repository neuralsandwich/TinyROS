#include "tiny_ros_node.h"
#include "gtest/gtest.h"

TEST(tiny_ros_node, CreateNodeUsingPOSIX) {
  TinyROS::Node TestNode = {};
  EXPECT_TRUE(TestNode.init(TinyROS::Node::ConnectionType::POSIX_IPC));
};

TEST(tiny_ros_node, CreateNodeUsingIPV6) {
  TinyROS::Node TestNode = {};
  EXPECT_TRUE(TestNode.init(TinyROS::Node::ConnectionType::IPV6));
}
