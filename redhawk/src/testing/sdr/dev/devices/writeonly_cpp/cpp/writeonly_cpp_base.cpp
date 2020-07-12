#include "writeonly_cpp_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the device class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

writeonly_cpp_base::writeonly_cpp_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl),
    ThreadedComponent()
{
    construct();
}

writeonly_cpp_base::writeonly_cpp_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, char *compDev) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl, compDev),
    ThreadedComponent()
{
    construct();
}

writeonly_cpp_base::writeonly_cpp_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, CF::Properties capacities) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl, capacities),
    ThreadedComponent()
{
    construct();
}

writeonly_cpp_base::writeonly_cpp_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, CF::Properties capacities, char *compDev) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl, capacities, compDev),
    ThreadedComponent()
{
    construct();
}

writeonly_cpp_base::~writeonly_cpp_base()
{
}

void writeonly_cpp_base::construct()
{
    loadProperties();

}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void writeonly_cpp_base::start() 
{
    Device_impl::start();
    ThreadedComponent::startThread();
}

void writeonly_cpp_base::stop() 
{
    Device_impl::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void writeonly_cpp_base::releaseObject() 
{
    // This function clears the device running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Device_impl::releaseObject();
}

void writeonly_cpp_base::loadProperties()
{
    addProperty(device_kind,
                "DCE:cdc5ee18-7ceb-4ae6-bf4c-31f983179b4d",
                "device_kind",
                "readonly",
                "",
                "eq",
                "allocation");

    addProperty(device_model,
                "DCE:0f99b2e4-9903-4631-9846-ff349d18ecfb",
                "device_model",
                "readonly",
                "",
                "eq",
                "allocation");

    addProperty(foo,
                "something",
                "foo",
                "",
                "writeonly",
                "",
                "external",
                "allocation");

    // Set the sequence with its initial values
    foo_seq.push_back("abc");
    addProperty(foo_seq,
                foo_seq,
                "foo_seq",
                "",
                "writeonly",
                "",
                "external",
                "allocation");

    addProperty(foo_struct,
                foo_struct_struct(),
                "foo_struct",
                "",
                "writeonly",
                "",
                "external",
                "allocation");

    addProperty(foo_struct_seq,
                foo_struct_seq,
                "foo_struct_seq",
                "",
                "writeonly",
                "",
                "external",
                "allocation");

    {
        ghi_struct __tmp;
        __tmp.jkl = "mno";
        foo_struct_seq.push_back(__tmp);
    }

}


