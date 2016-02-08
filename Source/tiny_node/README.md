# tiny_core

Requirements:

* Manages either local or network messaging between nodes.

All LEDs are off after the driver is initialized. A single LED can be turned on.
A single LED can be turned off.
Multiple LEDs can be turned on/off .
Turn on all LEDs
Turn off all LEDs
Query LED state
Check boundary values Check out-of-bounds values

## Testing

* Returns true when POSIX IPC is setup
* Returns true when network IPV6 is setup
* Manage incoming messages
* Manage outgoing messages
* Broadcast messages
* Accept node subscription
* Notify subscribed nodes
* Reject subscribing node
* Query Node for topics
* Subscribe to another node
* Unsubscribe from another node
