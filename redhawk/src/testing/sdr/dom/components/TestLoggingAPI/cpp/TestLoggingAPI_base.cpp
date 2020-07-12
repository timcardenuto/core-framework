/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK core.
 *
 * REDHAWK core is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK core is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
#include "TestLoggingAPI_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

TestLoggingAPI_base::TestLoggingAPI_base(const char *uuid, const char *label) :
    Resource_impl(uuid, label),
    ThreadedComponent()
{
    loadProperties();
}

TestLoggingAPI_base::~TestLoggingAPI_base()
{
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void TestLoggingAPI_base::start() 
{
    Resource_impl::start();
    ThreadedComponent::startThread();
}

void TestLoggingAPI_base::stop() 
{
    Resource_impl::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void TestLoggingAPI_base::releaseObject() 
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Resource_impl::releaseObject();
}

void TestLoggingAPI_base::loadProperties()
{
    addProperty(new_log_level,
                "new_log_level",
                "new_log_level",
                "readwrite",
                "",
                "external",
                "property");

    addProperty(new_log_cfg,
                "new_log_cfg",
                "new_log_cfg",
                "readwrite",
                "",
                "external",
                "property");

    addProperty(disable_cb,
                false,
                "DISABLE_CB",
                "disable_cb",
                "readwrite",
                "",
                "external",
                "property");

}


