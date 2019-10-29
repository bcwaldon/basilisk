/*
 ISC License

 Copyright (c) 2016, Autonomous Vehicle Systems Lab, University of Colorado at Boulder

 Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

 */


#ifndef BASILISK_SIMPLEPOWERSINK_H
#define BASILISK_SIMPLEPOWERSINK_H

#include "power/_GeneralModuleFiles/powerNodeBase.h"

/*! \addtogroup SimModelGroup
 * @{
 */

/*! @brief General power source/sink class.
 ## Module Purpose
 ### Executive Summary
    This module is intended to serve as a basic power node with a constant power load or draw. Specifically, it:

    1. Writes out a PowerNodeUsageSimMsg describing its power consumption at each sim update based on its power consumption attribute;
    2. Can be switched on or off using an optional message of type PowerNodeStatusIntMsg.

 ### Module Assumptions and Limitations
    See PowerNodeBase class for inherited assumption and limitations.  The power draw or supply for this module is assumed to be constant.

 ### Message Connection Descriptions
    This module only uses the input and output messages of the PowerNodeBase base class.

 ## User Guide
    This module inherits the user guide from the PowerNodeBase base class.

    For more information on how to set up and use this module, see the simple power system example: @ref scenarioSimplePowerDemo

 */


class SimplePowerSink: public PowerNodeBase {

public:
    SimplePowerSink();
    ~SimplePowerSink();

private:
    void evaluatePowerModel(PowerNodeUsageSimMsg *powerUsageMsg);

};


#endif //BASILISK_SIMPLEPOWERSINK_H