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
/**************************************************************************

    This is the component code. This file contains the child class where
    custom functionality can be added to the component. Custom
    functionality to the base class can be extended here. Access to
    the ports can also be done from this class

**************************************************************************/

#include "ECM_CPP.h"
#include <ostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

PREPARE_LOGGING(ECM_CPP_i)

ECM_CPP_i::ECM_CPP_i(const char *uuid, const char *label) :
    ECM_CPP_base(uuid, label)
{
    p_msgid=0;
    addPropertyChangeListener("enablecb", this, &ECM_CPP_i::enableChanged);
}

ECM_CPP_i::~ECM_CPP_i()
{
}

void ECM_CPP_i::initialize() 
{
    ecm = redhawk::events::Manager::GetManager( this );
    pub = ecm->Publisher("test1");
    sub  = ecm->Subscriber("test1");
}

void ECM_CPP_i::releaseObject()  
{
  pub.reset();
  sub.reset();
  ECM_CPP_base::releaseObject();
}

void ECM_CPP_i::dataArrived( const CORBA::Any &data )  {

    CORBA::Long msgin;
    if ( data >>= msgin ) {
        if ( msgin == p_msgid ) {
            msg_recv=msg_recv+1;
        }
        p_msgid++;
        LOG_INFO(ECM_CPP_i, " Received (CB) msgid : " << msgin  << " msg_recv:" << msg_recv);
    }

}


void ECM_CPP_i::enableChanged(  const bool *ov, bool const *nv ) {

    if ( nv and *nv  ){
        LOG_DEBUG(ECM_CPP_i, " Enable ECM Callbacks ");
        sub->setDataArrivedListener( this, &ECM_CPP_i::dataArrived );
    }
}



/***********************************************************************************************

    Basic functionality:

        The service function is called by the serviceThread object (of type ProcessThread).
        This call happens immediately after the previous call if the return value for
        the previous call was NORMAL.
        If the return value for the previous call was NOOP, then the serviceThread waits
        an amount of time defined in the serviceThread's constructor.
        
    SRI:
        To create a StreamSRI object, use the following code:
                std::string stream_id = "testStream";
                BULKIO::StreamSRI sri = bulkio::sri::create(stream_id);

	Time:
	    To create a PrecisionUTCTime object, use the following code:
                BULKIO::PrecisionUTCTime tstamp = bulkio::time::utils::now();

        
    Ports:

        Data is passed to the serviceFunction through the getPacket call (BULKIO only).
        The dataTransfer class is a port-specific class, so each port implementing the
        BULKIO interface will have its own type-specific dataTransfer.

        The argument to the getPacket function is a floating point number that specifies
        the time to wait in seconds. A zero value is non-blocking. A negative value
        is blocking.  Constants have been defined for these values, bulkio::Const::BLOCKING and
        bulkio::Const::NON_BLOCKING.

        Each received dataTransfer is owned by serviceFunction and *MUST* be
        explicitly deallocated.

        To send data using a BULKIO interface, a convenience interface has been added 
        that takes a std::vector as the data input

        NOTE: If you have a BULKIO dataSDDS or dataVITA49  port, you must manually call 
              "port->updateStats()" to update the port statistics when appropriate.

        Example:
            // this example assumes that the component has two ports:
            //  A provides (input) port of type bulkio::InShortPort called short_in
            //  A uses (output) port of type bulkio::OutFloatPort called float_out
            // The mapping between the port and the class is found
            // in the component base class header file

            bulkio::InShortPort::dataTransfer *tmp = short_in->getPacket(bulkio::Const::BLOCKING);
            if (not tmp) { // No data is available
                return NOOP;
            }

            std::vector<float> outputData;
            outputData.resize(tmp->dataBuffer.size());
            for (unsigned int i=0; i<tmp->dataBuffer.size(); i++) {
                outputData[i] = (float)tmp->dataBuffer[i];
            }

            // NOTE: You must make at least one valid pushSRI call
            if (tmp->sriChanged) {
                float_out->pushSRI(tmp->SRI);
            }
            float_out->pushPacket(outputData, tmp->T, tmp->EOS, tmp->streamID);

            delete tmp; // IMPORTANT: MUST RELEASE THE RECEIVED DATA BLOCK
            return NORMAL;

        If working with complex data (i.e., the "mode" on the SRI is set to
        true), the std::vector passed from/to BulkIO can be typecast to/from
        std::vector< std::complex<dataType> >.  For example, for short data:

            bulkio::InShortPort::dataTransfer *tmp = myInput->getPacket(bulkio::Const::BLOCKING);
            std::vector<std::complex<short> >* intermediate = (std::vector<std::complex<short> >*) &(tmp->dataBuffer);
            // do work here
            std::vector<short>* output = (std::vector<short>*) intermediate;
            myOutput->pushPacket(*output, tmp->T, tmp->EOS, tmp->streamID);

        Interactions with non-BULKIO ports are left up to the component developer's discretion

    Properties:
        
        Properties are accessed directly as member variables. For example, if the
        property name is "baudRate", it may be accessed within member functions as
        "baudRate". Unnamed properties are given the property id as its name.
        Property types are mapped to the nearest C++ type, (e.g. "string" becomes
        "std::string"). All generated properties are declared in the base class
        (ECM_CPP_base).
    
        Simple sequence properties are mapped to "std::vector" of the simple type.
        Struct properties, if used, are mapped to C++ structs defined in the
        generated file "struct_props.h". Field names are taken from the name in
        the properties file; if no name is given, a generated name of the form
        "field_n" is used, where "n" is the ordinal number of the field.
        
        Example:
            // This example makes use of the following Properties:
            //  - A float value called scaleValue
            //  - A boolean called scaleInput
              
            if (scaleInput) {
                dataOut[i] = dataIn[i] * scaleValue;
            } else {
                dataOut[i] = dataIn[i];
            }
            
        Callback methods can be associated with a property so that the methods are
        called each time the property value changes.  This is done by calling 
        addPropertyChangeListener(<property name>, this, &ECM_CPP_i::<callback method>)
        in the constructor.

        Callback methods should take two arguments, both const pointers to the value
        type (e.g., "const float *"), and return void.

        Example:
            // This example makes use of the following Properties:
            //  - A float value called scaleValue
            
        //Add to ECM_CPP.cpp
        ECM_CPP_i::ECM_CPP_i(const char *uuid, const char *label) :
            ECM_CPP_base(uuid, label)
        {
            addPropertyChangeListener("scaleValue", this, &ECM_CPP_i::scaleChanged);
        }

        void ECM_CPP_i::scaleChanged(const float *oldValue, const float *newValue)
        {
            std::cout << "scaleValue changed from" << *oldValue << " to " << *newValue
                      << std::endl;
        }
            
        //Add to ECM_CPP.h
        void scaleChanged(const float* oldValue, const float* newValue);
        

************************************************************************************************/
int ECM_CPP_i::serviceFunction()
{
    LOG_DEBUG(ECM_CPP_i, "serviceFunction() example log message");

    if  ( ecm  ) {
	if ( msg_limit > msg_xmit ) {
            LOG_INFO(ECM_CPP_i, "Generated MSG msgid =" << msg_xmit);

            pub->push( msg_xmit );
            msg_xmit++;
            boost::this_thread::sleep(boost::posix_time::milliseconds(100));
        }
        if ( msg_limit > msg_recv ) {
            CORBA::Long msgin=0;
            if ( sub->getData( msgin ) == 0 ) {
                LOG_INFO(ECM_CPP_i, "Received MSG msgid =" << msgin);
                if ( msgin == p_msgid ) {
                    msg_recv++;
                }
                p_msgid++;
            }
        }
    }
    else {
	RH_NL_INFO("ECM_CPP", "NO ECM ... ");
    }

    
    return NOOP;
}

