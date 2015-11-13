# tinyROS Namespace Reference

std::string append (const std::string &left, const std::string &right)
 	    Append one name to another. 
std::string clean (const std::string &name)
 	    Cleans a graph resource name: removes double slashes, trailing slash. 
const std::string & getRemappings ()
const std::string & getUnresolvedRemappings ()
void init (const M_string &remappings)
bool isValidCharInName (char c)
std::string parentNamespace (const std::string &name)
 	    Get the parent namespace of a name. 
std::string remap (const std::string &name)
 	    Apply remappings to a name. 
std::string resolve (const std::string &name, bool remap=true)
 	    Resolve a graph resource name into a fully qualified graph resource name. 
std::string resolve (const std::string &ns, const std::string &name, bool remap=true)
 	    Resolve a graph resource name into a fully qualified graph resource name. 
bool validate (const std::string &name, std::string &error)
 	    Validate a name against the name spec. 