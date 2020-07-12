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
// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#include "dmd-pimpl.h"

CREATE_LOGGER(dmd_parser)

rh_logger::LoggerPtr dmd::parserLog;

namespace dmd
{
  // domainmanagerconfiguration_pimpl
  //

  void domainmanagerconfiguration_pimpl::
  pre ()
  {
    _data.reset(new ossie::DomainManagerConfiguration::DMD()); 
  }

  void domainmanagerconfiguration_pimpl::
  description (const ::std::string& description)
  {
    // TODO
    //
  }

  void domainmanagerconfiguration_pimpl::
  domainmanagersoftpkg (const ::std::string& softpkg)
  {
      _data->softpkg = softpkg;
  }

  void domainmanagerconfiguration_pimpl::
  services ()
  {
  }

  void domainmanagerconfiguration_pimpl::
  id (const ::std::string& id)
  {
      _data->id = id;
  }

  void domainmanagerconfiguration_pimpl::
  name (const ::std::string& name)
  {
      _data->name = name; 
  }

  std::unique_ptr<ossie::DomainManagerConfiguration::DMD> domainmanagerconfiguration_pimpl::
  post_domainmanagerconfiguration ()
  {
      RH_TRACE(dmd::parserLog, "domainmanagerconfiguration post");
      return std::move(_data);
  }

  // domainmanagersoftpkg_pimpl
  //

  void domainmanagersoftpkg_pimpl::
  pre ()
  {
  }

  void domainmanagersoftpkg_pimpl::
  localfile (const ::std::string& localfile)
  {
      _localfile = localfile; 
  }

  ::std::string domainmanagersoftpkg_pimpl::
  post_domainmanagersoftpkg ()
  {
      return _localfile;
  }

  // localfile_pimpl
  //

  void localfile_pimpl::
  pre ()
  {
  }

  void localfile_pimpl::
  name (const ::std::string& name)
  {
      _name = name;
  }

  ::std::string localfile_pimpl::
  post_localfile ()
  {
      return _name;
  }

  // services_pimpl
  //

  void services_pimpl::
  pre ()
  {
  }

  void services_pimpl::
  service ()
  {
  }

  void services_pimpl::
  post_services ()
  {
  }

  // service_pimpl
  //

  void service_pimpl::
  pre ()
  {
  }

  void service_pimpl::
  usesidentifier (const ::std::string& usesidentifier)
  {
    // TODO
    //
  }

  void service_pimpl::
  findby ()
  {
  }

  void service_pimpl::
  post_service ()
  {
  }

  // findby_pimpl
  //

  void findby_pimpl::
  pre ()
  {
  }

  void findby_pimpl::
  namingservice ()
  {
  }

  void findby_pimpl::
  stringifiedobjectref (const ::std::string& stringifiedobjectref)
  {
    // TODO
    //
  }

  void findby_pimpl::
  domainfinder ()
  {
  }

  void findby_pimpl::
  post_findby ()
  {
  }

  // namingservice_pimpl
  //

  void namingservice_pimpl::
  pre ()
  {
  }

  void namingservice_pimpl::
  name ()
  {
  }

  void namingservice_pimpl::
  post_namingservice ()
  {
  }

  // domainfinder_pimpl
  //

  void domainfinder_pimpl::
  pre ()
  {
  }

  void domainfinder_pimpl::
  type (const ::std::string& type)
  {
    // TODO
    //
  }

  void domainfinder_pimpl::
  name (const ::std::string& name)
  {
    // TODO
    //
  }

  void domainfinder_pimpl::
  post_domainfinder ()
  {
  }
}

