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
#include "TestCppPropsRange_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

TestCppPropsRange_base::TestCppPropsRange_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    loadProperties();
}

TestCppPropsRange_base::~TestCppPropsRange_base()
{
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void TestCppPropsRange_base::start() 
{
    Component::start();
    ThreadedComponent::startThread();
}

void TestCppPropsRange_base::stop() 
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void TestCppPropsRange_base::releaseObject() 
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void TestCppPropsRange_base::loadProperties()
{
    addProperty(my_octet_name,
                1,
                "my_octet",
                "my_octet_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_short_name,
                2,
                "my_short",
                "my_short_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_ushort_name,
                3,
                "my_ushort",
                "my_ushort_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_long_name,
                4,
                "my_long",
                "my_long_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_ulong_name,
                5,
                "my_ulong",
                "my_ulong_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_longlong_name,
                6LL,
                "my_longlong",
                "my_longlong_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_ulonglong_name,
                7LL,
                "my_ulonglong",
                "my_ulonglong_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_octet_name.push_back(1);
    seq_octet_name.push_back(2);
    addProperty(seq_octet_name,
                seq_octet_name,
                "seq_octet",
                "seq_octet_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_short_name.push_back(1);
    seq_short_name.push_back(2);
    addProperty(seq_short_name,
                seq_short_name,
                "seq_short",
                "seq_short_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_ushort_name.push_back(1);
    seq_ushort_name.push_back(2);
    addProperty(seq_ushort_name,
                seq_ushort_name,
                "seq_ushort",
                "seq_ushort_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_long_name.push_back(1);
    seq_long_name.push_back(2);
    addProperty(seq_long_name,
                seq_long_name,
                "seq_long",
                "seq_long_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_ulong_name.push_back(1);
    seq_ulong_name.push_back(2);
    addProperty(seq_ulong_name,
                seq_ulong_name,
                "seq_ulong",
                "seq_ulong_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_longlong_name.push_back(1LL);
    seq_longlong_name.push_back(2LL);
    addProperty(seq_longlong_name,
                seq_longlong_name,
                "seq_longlong",
                "seq_longlong_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_ulonglong_name.push_back(1LL);
    seq_ulonglong_name.push_back(2LL);
    addProperty(seq_ulonglong_name,
                seq_ulonglong_name,
                "seq_ulonglong",
                "seq_ulonglong_name",
                "readwrite",
                "",
                "external",
                "configure");

    // Set the sequence with its initial values
    seq_char_name.push_back('a');
    seq_char_name.push_back('b');
    addProperty(seq_char_name,
                seq_char_name,
                "seq_char",
                "seq_char_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_struct_name,
                my_struct_name_struct(),
                "my_struct",
                "my_struct_name",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(my_structseq_name,
                my_structseq_name,
                "my_structseq",
                "my_structseq_name",
                "readwrite",
                "",
                "external",
                "configure");

}


