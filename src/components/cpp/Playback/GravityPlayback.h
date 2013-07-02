#include <sstream>
#include <GravityNode.h>
#include <cppdb/frontend.h>

namespace gravity {

class GravityPlayback
{
public:
	/*
	 * Assuming table_name, and other paramters are safe from attacks!!!
	 * Throws: cppdb::cppdb_error
	 */
	GravityPlayback(GravityNode* gn, const std::string conn_str);
    /**
     * Does not return until all data has been played back.
     */
    void start(uint64_t start_time, uint64_t end_time, std::string table_name, std::vector<std::string> &dps, std::vector<std::string> &transports);
    //TODO: stop?? thread support???
private:
    GravityNode* grav_node;

    cppdb::session sql;
    cppdb::statement select_stmt;
};

}
