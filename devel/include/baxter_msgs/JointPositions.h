/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/m/mico2178/baxter_ws/src/baxter_common/baxter_msgs/msg/JointPositions.msg
 *
 */


#ifndef BAXTER_MSGS_MESSAGE_JOINTPOSITIONS_H
#define BAXTER_MSGS_MESSAGE_JOINTPOSITIONS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace baxter_msgs
{
template <class ContainerAllocator>
struct JointPositions_
{
  typedef JointPositions_<ContainerAllocator> Type;

  JointPositions_()
    : angles()
    , names()  {
    }
  JointPositions_(const ContainerAllocator& _alloc)
    : angles(_alloc)
    , names(_alloc)  {
    }



   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _angles_type;
  _angles_type angles;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _names_type;
  _names_type names;




  typedef boost::shared_ptr< ::baxter_msgs::JointPositions_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::baxter_msgs::JointPositions_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct JointPositions_

typedef ::baxter_msgs::JointPositions_<std::allocator<void> > JointPositions;

typedef boost::shared_ptr< ::baxter_msgs::JointPositions > JointPositionsPtr;
typedef boost::shared_ptr< ::baxter_msgs::JointPositions const> JointPositionsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::baxter_msgs::JointPositions_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::baxter_msgs::JointPositions_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace baxter_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'baxter_msgs': ['/home/m/mico2178/baxter_ws/src/baxter_common/baxter_msgs/msg'], 'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/hydro/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::baxter_msgs::JointPositions_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::baxter_msgs::JointPositions_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_msgs::JointPositions_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_msgs::JointPositions_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_msgs::JointPositions_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_msgs::JointPositions_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::baxter_msgs::JointPositions_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a43c815223f80009ee6700b6d1dd906a";
  }

  static const char* value(const ::baxter_msgs::JointPositions_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa43c815223f80009ULL;
  static const uint64_t static_value2 = 0xee6700b6d1dd906aULL;
};

template<class ContainerAllocator>
struct DataType< ::baxter_msgs::JointPositions_<ContainerAllocator> >
{
  static const char* value()
  {
    return "baxter_msgs/JointPositions";
  }

  static const char* value(const ::baxter_msgs::JointPositions_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::baxter_msgs::JointPositions_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Joint angles in radians:\n\
float64[] angles\n\
# A list of names associated with the above angles\n\
string[]  names\n\
";
  }

  static const char* value(const ::baxter_msgs::JointPositions_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::baxter_msgs::JointPositions_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.angles);
      stream.next(m.names);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct JointPositions_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::baxter_msgs::JointPositions_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::baxter_msgs::JointPositions_<ContainerAllocator>& v)
  {
    s << indent << "angles[]" << std::endl;
    for (size_t i = 0; i < v.angles.size(); ++i)
    {
      s << indent << "  angles[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.angles[i]);
    }
    s << indent << "names[]" << std::endl;
    for (size_t i = 0; i < v.names.size(); ++i)
    {
      s << indent << "  names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.names[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // BAXTER_MSGS_MESSAGE_JOINTPOSITIONS_H