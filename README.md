# tinyROS
Tiny Robot Operating System for Raspberry Pi

## Communications Types

* Parameter Service
* Topics Service
* RPC Services 

## Naming

Follows ROS convention

Here are some name resolution examples:

| Node      | Relative (default)     | Global               | Private                       |
|-----------|------------------------|----------------------|-------------------------------|
| /node1    | bar -> /bar            | /bar -> /bar         | ~bar -> /node1/bar            |
| /wg/node2 | bar -> /wg/bar         | /bar -> /bar         | ~bar -> /wg/node2/bar         |
| /wg/node3 | foo/bar -> /wg/foo/bar | /foo/bar -> /foo/bar | ~foo/bar -> /wg/node3/foo/bar |

The API can be found here [Namespace Reference](docs/Namespace-Reference.md)

## Current Work

i2c-test

## Dependencies

* [ino](http://www.inotool.org)
* i2c-tools
