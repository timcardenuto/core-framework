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


#include "SimpleComponent_cpp_impl1_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

*******************************************************************************************/


/******************************************************************************************

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/
 
SimpleComponent_cpp_impl1_base::SimpleComponent_cpp_impl1_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    construct();
}

void SimpleComponent_cpp_impl1_base::construct() {

    loadProperties();
}

SimpleComponent_cpp_impl1_base::~SimpleComponent_cpp_impl1_base(void)
{
    usleep(1);
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void SimpleComponent_cpp_impl1_base::start() 
{
    Component::start();
    ThreadedComponent::startThread();
}

void SimpleComponent_cpp_impl1_base::stop() 
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void SimpleComponent_cpp_impl1_base::releaseObject() 
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void SimpleComponent_cpp_impl1_base::configure(const CF::Properties& props) 
{
    PropertySet_impl::configure(props);
}

void SimpleComponent_cpp_impl1_base::loadProperties()
{
    addProperty(ep_only,
                "default execparam only value", 
               "DCE:c709f95e-6b05-439a-9db9-dba95e70888e",
               "ep_only",
               "readwrite",
               "null",
               "external",
               "execparam");

    addProperty(ep_cfg,
                "default execparam-config value", 
               "DCE:6ea8108d-76ea-4532-9255-01684ad68429",
               "ep_cfg",
               "readwrite",
               "null",
               "external",
               "configure,execparam");

    addProperty(myOct,
                200,
               "DCE:10add64d-1160-4de0-885b-46a991f52f1d",
               "myOct",
               "readwrite",
               "null",
               "external",
               "configure,execparam");

}
