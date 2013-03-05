/*
 * GravitySubscriber.h
 *
 *  Created on: Sept. 19, 2012
 *      Author: Tim Ludwinski
 */

#ifndef GRAVITYHEARTBEATLISTENER_H_
#define GRAVITYHEARTBEATLISTENER_H_

#include <string>

namespace gravity
{

/**
 * Interface specification for an object that will respond to connection outages of gravity products.
 */
class GravityHeartbeatListener
{
public:
	/**
	 * Called when another component's heartbeat is off by a certain amount.
	 * \param componentID component id for the component whose heartbeat was missed
	 * \param microsecond_to_last_heartbeat number of microseconds since the last heartbeat was received, or -1 if
	 * a heart beat was never received.
	 * \param interval_in_microseconds The current heart beat interval for the given component ID.  Updates to this value
	 * will change the interval used in subsequent iterations.
	 */
	virtual void MissedHeartbeat(std::string componentID, uint64_t microsecond_to_last_heartbeat, uint64_t& interval_in_microseconds) = 0;

	/**
	 * Called when another component's heartbeat is received
     * \param componentID component id for the component whose heartbeat was received
     * \param interval_in_microseconds The current heart beat interval for the given component ID.  Updates to this value
     * will change the interval used in subsequent iterations.
	 */
	virtual void ReceivedHeartbeat(std::string componentID, uint64_t& interval_in_microseconds) = 0;

    /**
     * Default destructor
     */
	virtual ~GravityHeartbeatListener() { };
};

} /* namespace gravity */
#endif //GRAVITYHEARTBEATLISTENER_H_
